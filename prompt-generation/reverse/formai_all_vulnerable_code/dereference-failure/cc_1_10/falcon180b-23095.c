//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE* file, char* buffer) {
    int ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            buffer[i++] = tolower(ch);
        } else if (i > 0) {
            buffer[i] = '\0';
            i = 0;
        }
    }

    if (i > 0) {
        buffer[i] = '\0';
    }
}

void countWords(char* text, WordFrequency* frequencies, int numWords) {
    char word[MAX_WORD_LENGTH];
    int j = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            if (j > 0) {
                int k;
                for (k = 0; k < numWords; k++) {
                    if (strcmp(frequencies[k].word, word) == 0) {
                        frequencies[k].count++;
                        break;
                    }
                }
                if (k == numWords) {
                    strcpy(frequencies[j].word, word);
                    frequencies[j].count = 1;
                    j++;
                }
                memset(word, 0, sizeof(word));
            }
        } else {
            strncat(word, &text[i], 1);
        }
    }
}

void sortFrequencies(WordFrequency* frequencies, int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (frequencies[j].count > frequencies[i].count) {
                WordFrequency temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;
            }
        }
    }
}

void printFrequencies(WordFrequency* frequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    char buffer[MAX_WORD_LENGTH];
    readFile(file, buffer);

    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    countWords(buffer, frequencies, numWords);
    sortFrequencies(frequencies, numWords);
    printFrequencies(frequencies, numWords);

    return 0;
}