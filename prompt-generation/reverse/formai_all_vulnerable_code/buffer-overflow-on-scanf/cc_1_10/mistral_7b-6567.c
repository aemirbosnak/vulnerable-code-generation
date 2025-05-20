//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

Word wordList[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcasecmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return;
        }
    }

    if (numWords >= MAX_WORDS) {
        printf("Error: Reached maximum number of words.\n");
        exit(1);
    }

    strcpy(wordList[numWords].word, word);
    wordList[numWords].count = 1;
    numWords++;
}

int main() {
    char filename[100];
    FILE *file;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " ,.!?:;()\"'");
        while (token != NULL) {
            for (int i = 0; i < 26; i++) {
                token[tolower(token[i])] = (token[i] >= 'A' && token[i] <= 'Z') ? (char)(token[i] + 32) : token[i];
            }
            addWord(token);
            token = strtok(NULL, " ,.!?:;()\"'");
        }
    }

    fclose(file);

    printf("\nWord Frequency List:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    return 0;
}