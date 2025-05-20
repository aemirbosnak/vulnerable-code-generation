//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define TYPING_TEST_DURATION 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        strcpy(words[i].word, word);
        words[i].length = length;
    }
}

int main() {
    srand(time(NULL));
    Word words[MAX_WORDS];
    int numWords = rand() % MAX_WORDS + 1;
    generateWords(words, numWords);

    printf("Welcome to the typing speed test!\n");
    printf("You will be typing %d words in 60 seconds.\n", numWords);
    printf("Press enter to begin...\n");
    fflush(stdout);
    getchar();

    clock_t start = clock();
    int correctWords = 0;
    while (clock() - start < CLOCKS_PER_SEC * TYPING_TEST_DURATION) {
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        for (int i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                correctWords++;
                break;
            }
        }
    }

    printf("Test complete!\n");
    printf("You typed %d words correctly.\n", correctWords);
    printf("Your typing speed is %d words per minute.\n", correctWords * 60 / TYPING_TEST_DURATION);

    return 0;
}