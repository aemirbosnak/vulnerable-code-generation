//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    int sentenceCount = 0;
    int totalWords = 0;
    int i, j, k;
    struct Word words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        sentenceCount++;
        totalWords += strlen(line);

        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Warning: Word '%s' is too long and will be truncated.\n", token);
                strncpy(word, token, MAX_WORD_LENGTH);
            } else {
                strcpy(word, token);
            }

            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            for (j = 0; j < wordCount; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].frequency++;
                    break;
                }
            }

            if (j == wordCount) {
                if (wordCount >= MAX_WORDS) {
                    printf("Error: Maximum number of words (%d) reached.\n", MAX_WORDS);
                    exit(1);
                }
                strcpy(words[wordCount].word, word);
                words[wordCount].frequency = 1;
                wordCount++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fprintf(outputFile, "Total sentences: %d\n", sentenceCount);
    fprintf(outputFile, "Total words: %d\n", totalWords);

    for (i = 0; i < wordCount; i++) {
        fprintf(outputFile, "Word '%s' appears %d times.\n", words[i].word, words[i].frequency);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}