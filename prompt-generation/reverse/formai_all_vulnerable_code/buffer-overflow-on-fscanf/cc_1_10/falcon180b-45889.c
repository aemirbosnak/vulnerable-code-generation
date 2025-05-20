//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
};

int is_spam(char* text) {
    FILE* fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    struct word_t words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Too many spam words\n");
            exit(1);
        }

        words[num_words].word[0] = tolower(word[0]);
        strncpy(words[num_words].word + 1, word + 1, MAX_WORD_LENGTH - 1);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(fp);

    char* tokens = strtok(text, ",.!?;:");
    while (tokens!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(tokens, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        tokens = strtok(NULL, ",.!?;:");
    }

    int total_spam_words = 0;
    for (int i = 0; i < num_words; i++) {
        total_spam_words += words[i].count;
    }

    if (total_spam_words >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char text[1000];
    printf("Enter text to check for spam: ");
    fgets(text, 1000, stdin);

    if (is_spam(text)) {
        printf("Text is spam\n");
    } else {
        printf("Text is not spam\n");
    }

    return 0;
}