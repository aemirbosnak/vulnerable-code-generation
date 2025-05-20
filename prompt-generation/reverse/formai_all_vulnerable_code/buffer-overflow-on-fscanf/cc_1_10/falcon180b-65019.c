//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE* file, WordFrequency* words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        if (strlen(word) > 0) { // ignore empty words
            int i;
            for (i = 0; i < MAX_WORDS && words[i].frequency!= 0; i++) {
                // check if word already exists in array
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                // add new word to array
                strcpy(words[i].word, word);
                words[i].frequency = 1;
            }
        }
    }
}

void writeWords(FILE* file, WordFrequency* words) {
    int i;
    for (i = 0; i < MAX_WORDS && words[i].frequency!= 0; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readWords(inputFile, words);
    writeWords(outputFile, words);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}