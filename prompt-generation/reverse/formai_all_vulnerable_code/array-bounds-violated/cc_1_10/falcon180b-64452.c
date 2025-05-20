//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
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

void readWords(FILE *file, WordFrequency words[], int *numWords) {
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int len;
    int i;

    i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }
        for (int j = 0; j < len; j++) {
            if (isalpha(line[j])) {
                word[j] = tolower(line[j]);
            } else {
                word[j] = '\0';
                break;
            }
        }
        for (int j = 0; j < strlen(word); j++) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                break;
            }
            if (isalpha(word[j])) {
                if (strlen(word) == 0) {
                    strcpy(words[i].word, &word[j]);
                } else {
                    strcat(words[i].word, &word[j]);
                }
            }
        }
        i++;
    }
    *numWords = i;
}

void countWords(WordFrequency words[], int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];
    int numWords;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    readWords(file, words, &numWords);
    fclose(file);

    countWords(words, numWords);

    return 0;
}