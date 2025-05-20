//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        WordFrequency* currentWord = words;
        while (currentWord->frequency!= 0 && strcmp(currentWord->word, word)!= 0) {
            currentWord++;
        }

        if (currentWord->frequency == 0) {
            if (i >= MAX_WORDS - 1) {
                printf("Error: Too many unique words in file.\n");
                exit(1);
            }
            strcpy(currentWord->word, word);
            currentWord->frequency = 1;
        } else {
            currentWord->frequency++;
        }
    }

    fclose(file);
}

void printFrequencies(WordFrequency* words) {
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency!= 0) {
            printf("%s\t\t%d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    readWords(argv[1], words);
    printFrequencies(words);

    return 0;
}