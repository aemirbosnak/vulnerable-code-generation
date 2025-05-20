//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} word_t;

void toLower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int main() {
    word_t words[MAX_WORDS];
    int num_words = 0;
    char line[1024];

    while (gets(line) != NULL) {
        toLower(line);
        char* token = strtok(line, " \t\n");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (num_words == MAX_WORDS) {
                    printf("Error: Too many words!\n");
                    return 1;
                }
                strcpy(words[num_words].word, token);
                words[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}