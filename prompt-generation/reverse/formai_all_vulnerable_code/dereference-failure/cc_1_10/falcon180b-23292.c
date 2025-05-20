//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char *filename, WordFrequency *wordFrequencyArray) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Error: maximum number of words reached\n");
                exit(1);
            }
            strcpy(wordFrequencyArray[i].word, word);
            wordFrequencyArray[i].frequency = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void countWords(char *filename, WordFrequency *wordFrequencyArray) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (int j = 0; j < i; j++) {
                if (strcmp(wordFrequencyArray[j].word, word) == 0) {
                    wordFrequencyArray[j].frequency++;
                    break;
                }
            }
            if (i >= MAX_WORDS) {
                printf("Error: maximum number of words reached\n");
                exit(1);
            }
            strcpy(wordFrequencyArray[i].word, word);
            wordFrequencyArray[i].frequency = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void printWords(WordFrequency *wordFrequencyArray) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencyArray[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencyArray[i].word, wordFrequencyArray[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <count|read|print>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    WordFrequency wordFrequencyArray[MAX_WORDS];

    if (strcmp(argv[2], "count") == 0) {
        countWords(filename, wordFrequencyArray);
    } else if (strcmp(argv[2], "read") == 0) {
        readWords(filename, wordFrequencyArray);
    } else if (strcmp(argv[2], "print") == 0) {
        printWords(wordFrequencyArray);
    } else {
        printf("Error: invalid command\n");
        exit(1);
    }

    return 0;
}