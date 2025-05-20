//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

WordFrequency words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].frequency = 1;
    numWords++;
}

void printWords() {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char word[MAX_WORD_LEN];
    FILE* file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(word);
    }
    fclose(file);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
    }
    fclose(file);

    printWords();

    return 0;
}