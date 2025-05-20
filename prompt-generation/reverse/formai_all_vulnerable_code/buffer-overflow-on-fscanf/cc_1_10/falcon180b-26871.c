//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int is_spam;
} Word;

int main() {
    // Load the list of spam words
    FILE *fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open spam_words.txt\n");
        exit(1);
    }

    int num_spam_words = 0;
    Word *spam_words = malloc(sizeof(Word) * MAX_WORDS);
    while (fscanf(fp, "%s", spam_words[num_spam_words].word)!= EOF) {
        spam_words[num_spam_words].is_spam = 1;
        num_spam_words++;
    }
    fclose(fp);

    // Load the email content
    char *email_content = malloc(sizeof(char) * MAX_WORD_LENGTH);
    printf("Enter email content: ");
    fgets(email_content, MAX_WORD_LENGTH, stdin);

    // Convert email content to lowercase
    for (int i = 0; i < strlen(email_content); i++) {
        email_content[i] = tolower(email_content[i]);
    }

    // Tokenize email content into words
    char *token = strtok(email_content, " ");
    while (token!= NULL) {
        int is_spam = 0;
        for (int i = 0; i < num_spam_words; i++) {
            if (strcmp(token, spam_words[i].word) == 0) {
                is_spam = 1;
                break;
            }
        }
        if (is_spam) {
            printf("SPAM\n");
        } else {
            printf("NOT SPAM\n");
        }
        token = strtok(NULL, " ");
    }

    return 0;
}