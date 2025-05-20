//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SPAM_WORDS 100
#define MAX_EMAIL_LENGTH 1000

struct spam_word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    char email_body[MAX_EMAIL_LENGTH];
    int email_length = 0;

    struct spam_word spam_words[MAX_SPAM_WORDS] = {
        {"Viagra", 0},
        {"Cialis", 0},
        {"Levitra", 0},
        {"Mortgage", 0},
        {"Refinance", 0},
        {"Loan", 0},
        {"Insurance", 0},
        {"Credit", 0},
        {"Debt", 0},
        {"Stock", 0}
    };

    FILE *fp;
    fp = fopen("spam_words.txt", "r");

    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    char spam_word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", spam_word)!= EOF) {
        int i;
        for (i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(spam_word, spam_words[i].word) == 0) {
                spam_words[i].count++;
                break;
            }
        }
    }

    fclose(fp);

    printf("Enter email body:\n");
    fgets(email_body, MAX_EMAIL_LENGTH, stdin);
    email_length = strlen(email_body);

    int spam_score = 0;

    char *token = strtok(email_body, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strstr(token, spam_words[i].word)!= NULL) {
                spam_score += spam_words[i].count;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    if (spam_score >= 3) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}