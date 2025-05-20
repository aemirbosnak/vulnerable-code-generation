//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define MAX_EMAIL_LEN 100
#define SPAM_THRESHOLD 5

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    char *words[MAX_WORDS];
    int numWords;
} EmailWords;

void addWord(EmailWords *emailWords, char *word) {
    int i;
    for (i = 0; i < emailWords->numWords; i++) {
        if (strcmp(word, emailWords->words[i]) == 0) {
            emailWords->words[i] = NULL;
            break;
        }
    }
    emailWords->words[emailWords->numWords++] = word;
}

void processEmail(char *email, EmailWords *emailWords) {
    char *word;
    char *token;
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        emailWords->words[i] = NULL;
    }
    emailWords->numWords = 0;

    token = strtok(email, " \t\r\n");
    while (token!= NULL) {
        word = strtok(token, ".,!?;:\"'()[]{}<>");
        while (word!= NULL) {
            addWord(emailWords, word);
            word = strtok(NULL, ".,!?;:\"'()[]{}<>");
        }
        token = strtok(NULL, " \t\r\n");
    }
}

int isSpam(EmailWords *emailWords) {
    int i;
    int spamCount = 0;

    for (i = 0; i < emailWords->numWords; i++) {
        if (emailWords->words[i]!= NULL) {
            spamCount += 1;
        }
    }

    return (spamCount >= SPAM_THRESHOLD);
}

int main() {
    FILE *fp;
    char email[MAX_EMAIL_LEN];
    EmailWords emailWords;

    fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", email)!= EOF) {
        processEmail(email, &emailWords);
        if (isSpam(&emailWords)) {
            printf("Spam: %s\n", email);
        }
    }

    fclose(fp);
    return 0;
}