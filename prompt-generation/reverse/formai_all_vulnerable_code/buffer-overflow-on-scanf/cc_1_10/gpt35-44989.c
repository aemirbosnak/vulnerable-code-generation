//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lives = 6;
    char word[100] = "abracadabra";
    int word_length = strlen(word);
    char guessed[word_length];
    int guessed_letters = 0;

    for (int i = 0; i < word_length; i++) {
        guessed[i] = '_';
    }

    printf("Welcome to the game of Hangman!\n");
    printf("The word has %d letters.\n", word_length);

    while (lives > 0) {
        printf("You have %d lives left.\n", lives);
        printf("Word: ");
        for (int i = 0; i < word_length; i++) {
            printf("%c ", guessed[i]);
        }
        printf("\n");

        printf("Guess a letter: ");
        char guess;
        scanf("%c", &guess);

        int correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                guessed_letters++;
                correct_guess = 1;
            }
        }

        if (!correct_guess) {
            printf("Sorry, the letter '%c' is not in the word.\n", guess);
            lives--;
        } else if (guessed_letters == word_length) {
            printf("Congratulations, you guessed the word '%s'!\n", word);
            return 0;
        }

        getchar(); // Flush input buffer
    }

    printf("Sorry, you ran out of lives. The word was '%s'.\n", word);

    return 0;
}