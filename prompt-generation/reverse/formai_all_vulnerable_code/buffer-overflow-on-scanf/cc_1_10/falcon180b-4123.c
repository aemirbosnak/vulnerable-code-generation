//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20
#define MAX_EMAIL_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct email {
    char sender[MAX_EMAIL_LENGTH];
    char subject[MAX_WORD_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    int num_words;
    struct word *words;
};

int compare_words(const void *a, const void *b) {
    struct word *word1 = (struct word *)a;
    struct word *word2 = (struct word *)b;
    return word2->frequency - word1->frequency;
}

void read_words(struct email *email) {
    char word[MAX_WORD_LENGTH];
    char *token;
    int i = 0;
    while ((token = strtok(email->body, " \t\n\r\f\v"))!= NULL) {
        if (strlen(token) >= MIN_WORD_LENGTH && strlen(token) <= MAX_WORD_LENGTH) {
            strcpy(word, token);
            for (int j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }
            email->words[i] = (struct word) {.word = word,.frequency = 1};
            i++;
        }
    }
    email->num_words = i;
    qsort(email->words, i, sizeof(struct word), compare_words);
}

int is_spam(struct email *email) {
    int i;
    for (i = 0; i < email->num_words; i++) {
        if (email->words[i].frequency > 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct email email;
    char sender[MAX_EMAIL_LENGTH];
    char subject[MAX_WORD_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email body: ");
    scanf("%s", body);
    strcpy(email.sender, sender);
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    read_words(&email);
    if (is_spam(&email)) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }
    return 0;
}