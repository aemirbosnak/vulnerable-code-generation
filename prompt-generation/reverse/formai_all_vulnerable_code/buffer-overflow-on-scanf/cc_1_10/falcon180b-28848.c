//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define WORD_MAX_LEN 100

typedef struct {
    char word[WORD_MAX_LEN];
    int count;
} WordFrequency;

void initWords(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        strcpy(words[i].word, "");
        words[i].count = 0;
    }
}

void readTextFile(FILE *file, WordFrequency words[]) {
    char c;
    int index = 0;
    while (!feof(file)) {
        c = fgetc(file);
        if (isalpha(c)) {
            if (index >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcat(words[index].word, &c);
        } else {
            if (strlen(words[index].word) > 0) {
                words[index].count++;
                index++;
            }
            strcpy(words[index].word, "");
        }
    }
}

void displayWordFrequency(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    WordFrequency words[MAX_WORDS];
    initWords(words);
    readTextFile(file, words);
    fclose(file);
    displayWordFrequency(words);
    return 0;
}