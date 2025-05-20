//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_COUNT 5
#define WORD_LEN 10

int main() {
    // Initialize the words list
    char *words[WORDS_COUNT];
    for (int i = 0; i < WORDS_COUNT; i++) {
        words[i] = malloc(WORD_LEN * sizeof(char));
        srand(time(NULL));
        for (int j = 0; j < WORD_LEN; j++) {
            words[i][j] = 'a' + (rand() % 26);
        }
    }

    // Reveal the words one by one
    for (int i = 0; i < WORDS_COUNT; i++) {
        printf("%d. %s\n", i + 1, words[i]);
        sleep(1);
    }

    // Ask the player to remember all the words
    printf("Now, can you remember all the words?\n");

    // Get the player's answer
    char memory[WORDS_COUNT][WORD_LEN];
    for (int i = 0; i < WORDS_COUNT; i++) {
        printf("Word %d: ", i + 1);
        fgets(memory[i], WORD_LEN, stdin);
    }

    // Check if the player remembered all the words
    for (int i = 0; i < WORDS_COUNT; i++) {
        for (int j = 0; j < WORD_LEN; j++) {
            if (memory[i][j] != words[i][j]) {
                printf("Oops, you forgot %c!\n", words[i][j]);
                return 1;
            }
        }
    }

    // Congratulations, you have an amazing memory! 😱
    printf("YESSSS! You did it! 🎉 You have an amazing memory! 😱\n");

    // Ask the player if they want to play again
    printf("Want to play again? (y/n): ");
    char playAgain = getchar();

    if (playAgain == 'y' || playAgain == 'Y') {
        // Start a new game
        for (int i = 0; i < WORDS_COUNT; i++) {
            free(words[i]);
        }
        words[0] = malloc(WORD_LEN * sizeof(char));
        srand(time(NULL));
        for (int j = 0; j < WORD_LEN; j++) {
            words[0][j] = 'a' + (rand() % 26);
        }
        printf("Here's the first word: %s\n", words[0]);
    } else {
        // Exit the program
        printf("Thanks for playing! 😊\n");
        return 0;
    }

    return 0;
}