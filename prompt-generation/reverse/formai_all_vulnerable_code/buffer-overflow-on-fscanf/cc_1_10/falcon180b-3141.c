//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }

    fclose(file);
}

void sortWords(WordFrequency* words) {
    int i, j;
    char temp[MAX_WORD_LENGTH];

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = 0; j < MAX_WORDS - i - 1; j++) {
            if (words[j].count > words[j + 1].count) {
                strcpy(temp, words[j].word);
                strcpy(words[j].word, words[j + 1].word);
                strcpy(words[j + 1].word, temp);

                int tempCount = words[j].count;
                words[j].count = words[j + 1].count;
                words[j + 1].count = tempCount;
            }
        }
    }
}

void printWords(WordFrequency* words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char inputFilename[MAX_WORD_LENGTH];
    char outputFilename[MAX_WORD_LENGTH];
    strcpy(inputFilename, argv[1]);
    strcpy(outputFilename, argv[2]);

    WordFrequency words[MAX_WORDS];

    readWords(inputFilename, words);
    sortWords(words);
    printWords(words);

    return 0;
}