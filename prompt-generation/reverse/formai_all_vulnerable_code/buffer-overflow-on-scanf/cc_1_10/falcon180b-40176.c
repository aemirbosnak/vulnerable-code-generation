//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

WordFrequency words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
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

void printWords(int limit) {
    int i;
    for (i = 0; i < numWords && i < limit; i++) {
        printf("%s %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    char input[MAX_WORD_LENGTH];
    int i, j;

    printf("Enter text to count word frequencies:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, ",.?!;:");
    while (token!= NULL) {
        for (i = 0; i < strlen(token); i++) {
            if (isalpha(token[i])) {
                token[i] = tolower(token[i]);
            }
        }
        addWord(token);
        token = strtok(NULL, ",.?!;:");
    }

    printf("Enter limit for number of words to print:\n");
    scanf("%d", &i);
    printWords(i);

    return 0;
}