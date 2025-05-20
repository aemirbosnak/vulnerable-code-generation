//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define SPAM_THRESHOLD 0.8
#define NUM_TRAINING_SAMPLES 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} TrainingSample;

TrainingSample training_samples[NUM_TRAINING_SAMPLES];

int count_spam_words(char *email) {
    int count = 0;
    char *word = strtok(email, " ");
    while (word!= NULL) {
        if (is_spam_word(word)) {
            count++;
        }
        word = strtok(NULL, " ");
    }
    return count;
}

int is_spam_word(char *word) {
    for (int i = 0; i < NUM_TRAINING_SAMPLES; i++) {
        if (strcmp(training_samples[i].word, word) == 0 && training_samples[i].is_spam == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("Enter training data (spam/ham):\n");
    for (int i = 0; i < NUM_TRAINING_SAMPLES; i++) {
        char email[MAX_EMAIL_LENGTH];
        scanf("%s", email);
        if (strcmp(email, "spam") == 0) {
            strcpy(training_samples[i].word, "viagra");
            training_samples[i].is_spam = 1;
        } else if (strcmp(email, "ham") == 0) {
            strcpy(training_samples[i].word, "newsletter");
            training_samples[i].is_spam = 0;
        }
    }

    printf("Enter email to classify as spam or ham:\n");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);
    int is_spam = count_spam_words(email) >= (NUM_TRAINING_SAMPLES * SPAM_THRESHOLD);

    if (is_spam) {
        printf("Email is spam.\n");
    } else {
        printf("Email is ham.\n");
    }

    return 0;
}