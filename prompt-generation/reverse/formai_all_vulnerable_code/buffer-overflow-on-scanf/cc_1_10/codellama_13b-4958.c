//Code Llama-13B DATASET v1.0 Category: Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10
#define MAX_WORD_LENGTH 20

int main() {
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    int guesses_left = MAX_GUESSES;
    char guess[MAX_WORD_LENGTH];
    int correct_guesses = 0;

    // Generate a random word
    srand(time(NULL));
    int rand_word = rand() % 100;
    sprintf(word, "%d", rand_word);
    word_length = strlen(word);

    // Print the word with underscores
    for (int i = 0; i < word_length; i++) {
        printf("_ ");
    }
    printf("\n");

    // Loop for guessing
    while (guesses_left > 0) {
        printf("Guess a letter: ");
        scanf("%c", guess);
        guesses_left--;

        // Check if the guess is correct
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                printf("Correct!\n");
                correct_guesses++;
                break;
            }
        }

        // Print the word with underscores
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                printf("%c ", guess);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        // Check if the word is guessed correctly
        if (correct_guesses == word_length) {
            printf("Congratulations, you won!\n");
            break;
        }
    }

    // Print the number of guesses left
    printf("You have %d guesses left.\n", guesses_left);

    return 0;
}