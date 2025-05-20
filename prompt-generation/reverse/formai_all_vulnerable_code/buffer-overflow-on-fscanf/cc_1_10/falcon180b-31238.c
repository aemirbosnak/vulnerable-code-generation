//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, char **words, int *wordCount) {
    char buffer[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", buffer)!= EOF) {
        for (int j = 0; j < strlen(buffer); j++) {
            if (!isalpha(buffer[j])) {
                buffer[j] = '\0';
            }
        }
        words[i] = strdup(buffer);
        i++;
        *wordCount += 1;
    }
}

void countFrequencies(char **words, int wordCount, WordFrequency *frequencies) {
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            if (frequencies[j].word[0] == '\0') {
                strcpy(frequencies[j].word, words[i]);
                frequencies[j].frequency = 1;
                break;
            } else if (strcmp(frequencies[j].word, words[i]) == 0) {
                frequencies[j].frequency++;
                break;
            }
        }
    }
}

void printFrequencies(WordFrequency *frequencies, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (frequencies[i].word[0]!= '\0') {
            printf("%s: %d\n", frequencies[i].word, frequencies[i].frequency);
        }
    }
}

int main() {
    char *filename;
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
    int wordCount = 0;
    readWords(file, words, &wordCount);

    WordFrequency frequencies[MAX_WORDS];
    countFrequencies(words, wordCount, frequencies);

    printFrequencies(frequencies, wordCount);

    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);

    fclose(file);
    return 0;
}