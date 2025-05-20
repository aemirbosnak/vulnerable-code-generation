//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

WordFrequency words[MAX_NUM_WORDS];
int numWords = 0;

void addWord(char* word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (numWords == MAX_NUM_WORDS) {
        printf("Error: Maximum number of words reached.\n");
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
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
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

    int minFrequency;
    printf("Enter minimum frequency: ");
    scanf("%d", &minFrequency);

    printWords(minFrequency);

    return 0;
}