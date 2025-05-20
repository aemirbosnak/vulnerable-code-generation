//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *file, WordFrequency words[MAX_WORDS]) {
    char ch;
    char word[MAX_WORD_LENGTH];
    int i = 0;
    int j = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[j++] = tolower(ch);
        } else if (j > 0) {
            word[j] = '\0';
            for (i = 0; i < MAX_WORD_LENGTH && words[i].word[0]!= '\0'; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == MAX_WORD_LENGTH) {
                printf("Exceeded maximum number of unique words.\n");
            }
            j = 0;
        }
    }

    if (j > 0) {
        word[j] = '\0';
        for (i = 0; i < MAX_WORD_LENGTH && words[i].word[0]!= '\0'; i++) {
            if (strcmp(word, words[i].word)!= 0) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                break;
            }
        }
    }
}

void printWordFrequencies(WordFrequency words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORD_LENGTH && words[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readFile(file, words);

    fclose(file);

    printWordFrequencies(words);

    return 0;
}