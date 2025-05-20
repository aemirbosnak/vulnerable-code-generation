//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int numWords = 0;

void readWords(FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        words[numWords++] = strdup(word);
    }
}

void printWords() {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

void analyzeWords(char *filename) {
    FILE *file;
    char *extension;
    int i;

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    extension = strrchr(filename, '.');

    if (strcmp(extension, ".txt")!= 0) {
        printf("Error: File must be a text file.\n");
        exit(1);
    }

    readWords(file);

    for (i = 0; i < numWords; i++) {
        if (isalpha(words[i][0])) {
            printf("Word %d: %s\n", i+1, words[i]);
        } else {
            printf("Error: Word %d is not a valid word.\n", i+1);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    analyzeWords(argv[1]);

    return 0;
}