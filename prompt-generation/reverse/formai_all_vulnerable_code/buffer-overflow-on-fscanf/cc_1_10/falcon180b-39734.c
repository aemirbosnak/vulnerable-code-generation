//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(const char* filename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer)!= EOF) {
        int i = 0;
        while (i < strlen(buffer)) {
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                buffer[i] = c;
                i++;
            } else {
                buffer[i] = '\0';
            }
        }

        WordFrequency* currentWord = wordFrequencies;
        while (currentWord->word[0]!= '\0' && strcmp(buffer, currentWord->word)!= 0) {
            currentWord++;
        }

        if (currentWord->word[0] == '\0') {
            strcpy(currentWord->word, buffer);
            currentWord->frequency = 1;
        } else {
            currentWord->frequency++;
        }
    }

    fclose(file);
}

void writeFrequencies(const char* outputFilename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", outputFilename);
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].word[0]!= '\0') {
            fprintf(file, "%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readFile(argv[1], wordFrequencies);
    writeFrequencies(argv[2], wordFrequencies);

    return 0;
}