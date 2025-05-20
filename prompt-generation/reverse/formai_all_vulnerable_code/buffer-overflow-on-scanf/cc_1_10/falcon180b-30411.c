//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct wordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void readFile(FILE *file, struct wordFrequency *wordFrequencies, int *numWords) {
    char line[MAX_WORD_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, ",.?!;:\"'");

        while (token!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }

            strcpy(wordFrequencies[i].word, token);
            wordFrequencies[i].frequency = 1;
            i++;

            token = strtok(NULL, ",.?!;:\"'");
        }
    }

    *numWords = i;
}

void printWordFrequencies(int numWords, struct wordFrequency *wordFrequencies) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    struct wordFrequency wordFrequencies[MAX_WORDS];
    int numWords;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    readFile(file, wordFrequencies, &numWords);

    printf("Word Frequencies:\n");
    printWordFrequencies(numWords, wordFrequencies);

    return 0;
}