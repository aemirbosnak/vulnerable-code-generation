//Code Llama-13B DATASET v1.0 Category: Game ; Style: shocked
/*
 * A shocking C game program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 5
#define MAX_WORD_LENGTH 10
#define ALPHABET_SIZE 26

char word[MAX_WORD_LENGTH];
char guessed_letters[ALPHABET_SIZE];

void print_board(void) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (guessed_letters[word[i]]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void play_game(void) {
    int i, j, guesses;
    char guess;

    // Generate a random word
    srand(time(NULL));
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word[i] = 'a' + rand() % ALPHABET_SIZE;
    }

    // Initialize the guessed letters array
    for (i = 0; i < ALPHABET_SIZE; i++) {
        guessed_letters[i] = 0;
    }

    // Play the game
    guesses = 0;
    while (guesses < MAX_GUESSES) {
        print_board();

        // Prompt the user to guess a letter
        printf("Guess a letter: ");
        scanf("%c", &guess);

        // Check if the letter is in the word
        for (i = 0; i < MAX_WORD_LENGTH; i++) {
            if (word[i] == guess) {
                guessed_letters[word[i]] = 1;
                break;
            }
        }

        // Check if the user has won the game
        if (guesses >= MAX_GUESSES) {
            printf("You lose!\n");
            break;
        } else if (guessed_letters[word[i]] == 1) {
            printf("You win!\n");
            break;
        }

        // Increment the number of guesses
        guesses++;
    }
}

int main(void) {
    play_game();
    return 0;
}