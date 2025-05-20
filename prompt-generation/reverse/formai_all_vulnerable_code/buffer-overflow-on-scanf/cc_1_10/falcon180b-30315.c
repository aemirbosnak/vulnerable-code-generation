//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words!\n");
            exit(1);
        }
        words[i].word[0] = toupper(word[0]);
        strcpy(&words[i].word[1], word);
        words[i].count = 1;
        i++;
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

void sortWords(WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    readWords(file, words);
    fclose(file);

    sortWords(words);
    printWords(words);

    return 0;
}