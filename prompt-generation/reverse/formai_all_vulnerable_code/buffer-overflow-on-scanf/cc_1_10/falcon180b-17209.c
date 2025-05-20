//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_USER_INPUT_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;

void loadWords(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[length - 1] = '\0';
        }
        strcpy(words[numWords].word, line);
        words[numWords].length = length;
        numWords++;
    }

    fclose(file);
}

void displayWords() {
    printf("Words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

void generateRandomString(char* string, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        string[i] = c;
    }
    string[length] = '\0';
}

int main() {
    srand(time(NULL));

    char filename[MAX_USER_INPUT_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    loadWords(filename);

    printf("Words loaded:\n");
    displayWords();

    int totalWords = numWords;
    int correctWords = 0;
    int wrongWords = 0;

    char input[MAX_USER_INPUT_LENGTH];
    int inputLength;

    for (int i = 0; i < numWords; i++) {
        printf("Word %d:\n", i + 1);
        Word word = words[i];
        generateRandomString(input, word.length);
        input[word.length] = '\0';

        printf("Word: %s\n", word.word);
        printf("Input: ");
        scanf("%s", input);
        inputLength = strlen(input);

        if (strcmp(input, word.word) == 0) {
            correctWords++;
        } else {
            wrongWords++;
        }

        printf("Correct: %s\n", input);
        printf("\n");
    }

    printf("Total words: %d\n", totalWords);
    printf("Correct words: %d\n", correctWords);
    printf("Wrong words: %d\n", wrongWords);

    return 0;
}