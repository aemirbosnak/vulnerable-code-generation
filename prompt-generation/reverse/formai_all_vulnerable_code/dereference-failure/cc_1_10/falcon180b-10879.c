//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100 // maximum length of a word
#define NUM_FEATURES 10000 // number of features to extract from each email
#define THRESHOLD 0.5 // threshold for classifying an email as spam or not spam

struct feature {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct email {
    char *subject;
    char *body;
    int is_spam;
};

void extract_features(struct email *email, struct feature *features) {
    char *token = strtok(email->body, " ");
    int i = 0;
    while (token!= NULL) {
        if (i >= NUM_FEATURES) {
            break;
        }
        struct feature *current_feature = &features[i];
        strcpy(current_feature->word, token);
        current_feature->count = 1;
        i++;
        token = strtok(NULL, " ");
    }
}

int is_spam(struct email *email, struct feature *features) {
    int i = 0;
    while (i < NUM_FEATURES) {
        struct feature *current_feature = &features[i];
        if (current_feature->count >= THRESHOLD) {
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    struct email email1 = {"Buy now", "Viagra pills for sale. Best prices.", 1}; // spam
    struct email email2 = {"Re: Meeting tomorrow", "Hey team, just a reminder that we have a meeting tomorrow at 10am.", 0}; // not spam

    struct feature features[NUM_FEATURES];
    extract_features(&email1, features);
    extract_features(&email2, features);

    int is_spam1 = is_spam(&email1, features);
    int is_spam2 = is_spam(&email2, features);

    printf("Email 1 is spam: %d\n", is_spam1);
    printf("Email 2 is spam: %d\n", is_spam2);

    return 0;
}