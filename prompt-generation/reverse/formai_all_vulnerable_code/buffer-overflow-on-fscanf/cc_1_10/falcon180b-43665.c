//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWords(FILE *inputFile, WordFrequency *words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        int length = strlen(word);
        if (length > 0 && isalpha(word[0])) {
            WordFrequency *found = NULL;
            for (int i = 0; i < MAX_WORDS; i++) {
                if (words[i].word == NULL) {
                    words[i].word = strdup(word);
                    words[i].frequency = 1;
                    break;
                } else if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    found = &words[i];
                    break;
                }
            }
            if (found == NULL) {
                for (int i = 0; i < MAX_WORDS; i++) {
                    if (words[i].word == NULL) {
                        words[i].word = strdup(word);
                        words[i].frequency = 1;
                        break;
                    }
                }
            }
        }
    }
}

void writeWords(FILE *outputFile, WordFrequency *words) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word!= NULL) {
            fprintf(outputFile, "%s %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
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