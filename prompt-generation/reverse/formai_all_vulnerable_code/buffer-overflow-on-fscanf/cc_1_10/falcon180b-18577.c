//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define MAX_FILE_SIZE 1000000 // 1 MB

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int wordIndex = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        strcpy(words[wordIndex], word);
        wordIndex++;
    }
}

void countWordFrequencies(char words[MAX_WORDS][MAX_WORD_LENGTH], WordFrequency frequencies[MAX_WORDS]) {
    int i, j;
    for (i = 0; i < strlen(words[0]); i++) {
        for (j = 0; j < strlen(words[0]); j++) {
            if (i!= j && words[0][i] == words[0][j]) {
                frequencies[0].frequency += 1;
            }
        }
    }
    for (i = 1; i < MAX_WORDS; i++) {
        frequencies[i].frequency = 0;
        int k;
        for (k = 0; k < i; k++) {
            int l;
            for (l = 0; l < strlen(words[k]); l++) {
                if (words[k][l] == words[i][0]) {
                    frequencies[i].frequency += 1;
                    break;
                }
            }
            if (frequencies[i].frequency > 0) {
                break;
            }
        }
    }
}

void printWordFrequencies(WordFrequency frequencies[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i].frequency > 0) {
            printf("%s: %d\n", frequencies[i].word, frequencies[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    readWords(file, words);
    countWordFrequencies(words, frequencies);
    printWordFrequencies(frequencies);
    fclose(file);
    return 0;
}