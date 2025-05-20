//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int found = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].count = 1;
        }
    }

    fclose(file);
}

void writeWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    readWords(filename, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            numWords++;
        }
    }

    writeWords(words, numWords);

    return 0;
}