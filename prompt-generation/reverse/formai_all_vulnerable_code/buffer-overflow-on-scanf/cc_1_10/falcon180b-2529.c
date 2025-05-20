//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    WordCount words[MAX_WORDS];
    int numWords;
} WordFrequency;

int isValidWord(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void addWord(WordFrequency *freq, char *word) {
    int i;
    for (i = 0; i < freq->numWords; i++) {
        if (strcmp(freq->words[i].word, word) == 0) {
            freq->words[i].count++;
            return;
        }
    }
    if (freq->numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(freq->words[freq->numWords].word, word);
    freq->words[freq->numWords].count = 1;
    freq->numWords++;
}

void printFrequency(WordFrequency *freq) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < freq->numWords; i++) {
        printf("%s\t%d\n", freq->words[i].word, freq->words[i].count);
    }
}

int main() {
    char input[MAX_WORD_LEN] = "";
    WordFrequency freq = {0};
    while (1) {
        printf("Enter a word or type 'quit' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (!isValidWord(input)) {
            printf("Error: Invalid word.\n");
            continue;
        }
        addWord(&freq, input);
    }
    printFrequency(&freq);
    return 0;
}