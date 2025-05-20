//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

bool is_spam(const char *message) {
    FILE *fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    Word words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Too many spam words\n");
            exit(1);
        }
        strcpy(words[num_words].word, word);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(fp);

    char *token = strtok(message, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    int total_spam_words = 0;
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            total_spam_words++;
        }
    }

    if (total_spam_words >= 3) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char message[1000];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}