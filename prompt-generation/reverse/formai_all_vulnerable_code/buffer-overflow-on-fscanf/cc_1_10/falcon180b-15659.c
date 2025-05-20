//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words from file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", line)!= EOF) {
        int length = strlen(line);
        if (length > MAX_WORD_LENGTH) {
            printf("Error: word '%s' is too long.\n", line);
            exit(1);
        }

        strcpy(words[numWords].word, line);
        words[numWords].length = length;
        numWords++;
    }

    fclose(file);
}

void shuffleWords() {
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void displayWord(int index) {
    for (int i = 0; i < words[index].length; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    loadWords();
    shuffleWords();

    int totalWords = numWords;
    int correctWords = 0;
    int incorrectWords = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", totalWords);

    for (int i = 0; i < totalWords; i++) {
        printf("Word %d:\n", i+1);
        displayWord(i);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        } else {
            incorrectWords++;
        }

        printf("\n");
    }

    printf("You typed %d words correctly and %d words incorrectly.\n", correctWords, incorrectWords);

    return 0;
}