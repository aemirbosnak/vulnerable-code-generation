//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;
int timeLeft;

void init() {
    srand(time(NULL));
    for (int i = 0; i < MAX_WORDS; i++) {
        char *word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
        sprintf(word, "word%d", i);
        strcpy(words[i].word, word);
        words[i].length = strlen(word);
        free(word);
    }
    numWords = rand() % MAX_WORDS + 1;
    timeLeft = MAX_TIME;
}

void printWords() {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
    }
}

int main() {
    init();
    printf("Welcome to the Happy Typing Speed Test!\n");
    printf("You will have %d seconds to type the following words:\n", MAX_TIME);
    printWords();
    printf("\nPress enter when you are ready to begin.\n");
    getchar();
    timeLeft = MAX_TIME;
    while (timeLeft > 0) {
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        int inputLength = strlen(input);
        if (inputLength > 0 && tolower(input[0]) == tolower(words[0].word[0])) {
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(input, words[j].word) == 0) {
                    break;
                }
            }
            if (j == numWords) {
                printf("Incorrect word!\n");
            } else {
                printf("Correct!\n");
            }
        } else {
            printf("Incorrect word!\n");
        }
        timeLeft--;
    }
    printf("Time is up!\n");
    printf("You typed %d words correctly.\n", numWords);
    return 0;
}