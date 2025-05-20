//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE* file, WordFrequency* frequencies) {
    char word[MAX_WORD_LENGTH];
    char ch;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[0] = tolower(ch);
            int i = 1;

            while ((ch = fgetc(file))!= EOF && isalpha(ch)) {
                word[i++] = tolower(ch);
            }

            word[i] = '\0';

            int index = hash(word);

            if (index < MAX_WORDS) {
                frequencies[index].count++;
            }
        }
    }
}

int hash(char* word) {
    int hash = 0;

    for (int i = 0; i < strlen(word); i++) {
        hash = (hash * 31) + word[i];
    }

    return hash % MAX_WORDS;
}

void printFrequencies(WordFrequency* frequencies) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i].count > 0) {
            printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency frequencies[MAX_WORDS];

    readFile(file, frequencies);

    fclose(file);

    printFrequencies(frequencies);

    return 0;
}