//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        if (strcmp(word, "the") == 0) {
            strcpy(word, "a");
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS &&!found; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].count = 1;
        }
    }
}

void printWords(WordCount words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    WordCount words[MAX_WORDS];
    readWords(file, words);
    fclose(file);
    printWords(words);
    return 0;
}