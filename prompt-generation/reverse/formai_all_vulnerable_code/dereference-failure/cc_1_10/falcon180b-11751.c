//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 3

typedef struct {
    char *word;
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

void countWords(char *text) {
    char *word;
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word = (char *) malloc(sizeof(char) * (strlen(text) - i + 1));
            strncpy(word, &text[i], strlen(text) - i);
            word[strlen(text) - i] = '\0';
            addWord(word);
        }
    }
}

void printWords(int threshold) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (words[i].frequency >= threshold) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *text = NULL;
    size_t textSize = 0;
    if (argc == 1) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    textSize = ftell(file);
    rewind(file);
    text = (char *) malloc(sizeof(char) * (textSize + 1));
    fread(text, sizeof(char), textSize, file);
    fclose(file);
    countWords(text);
    printWords(3);
    free(text);
    return 0;
}