//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

WordFrequency words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].frequency = 1;
    numWords++;
}

void printWords(int minFrequency) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (words[i].frequency >= minFrequency) {
            printf("%s %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    char *token;
    int minFrequency = 1;

    printf("Enter minimum frequency: ");
    scanf("%d", &minFrequency);

    while (fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        token = strtok(word, ",.?!;:");
        while (token!= NULL) {
            addWord(token);
            token = strtok(NULL, ",.?!;:");
        }
    }

    printWords(minFrequency);

    return 0;
}