//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 25
#define MAX_ATTEMPTS 10

int main() {
    char typed_word[MAX_WORD_LENGTH];
    char random_word[MAX_WORD_LENGTH];
    int i, j, mistakes, word_length, word_index;
    int words_count = 10;
    char words[10][MAX_WORD_LENGTH] = {
        "programming",
        "algorithm",
        "computer",
        "data",
        "logic",
        "syntax",
        "variable",
        "function",
        "compiler",
        "debugging"
    };

    srand(time(0));

    printf("Welcome to the typing speed test program!\n");
    printf("You will be given a series of words to type. You need to type each word as quickly and accurately as possible.\n");
    printf("Type 'start' to begin the test: ");

    scanf("%s", typed_word);

    if (strcmp(typed_word, "start") != 0) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\n\n\n");

    for (i = 0; i < words_count; i++) {
        // Select a random word from the list
        word_index = rand() % words_count;
        strcpy(random_word, words[word_index]);

        word_length = strlen(random_word);
        mistakes = 0;

        printf("Type the word: %s\n", random_word);

        for (j = 0; j < MAX_ATTEMPTS; j++) {
            printf("Attempt #%d: ", j+1);
            scanf("%s", typed_word);

            if (strcmp(typed_word, random_word) == 0) {
                printf("You typed the word correctly in %d attempts!\n", j+1);
                break;
            } else {
                mistakes++;
                printf("Incorrect typing! Please try again (mistakes: %d)\n", mistakes);
            }
        }

        if (mistakes == MAX_ATTEMPTS) {
            printf("You didn't type the word correctly in %d attempts! The correct word was: %s\n", mistakes, random_word);
        }

        printf("\n\n");
    }

    printf("Thank you for taking the typing speed test!\n");

    return 0;
}