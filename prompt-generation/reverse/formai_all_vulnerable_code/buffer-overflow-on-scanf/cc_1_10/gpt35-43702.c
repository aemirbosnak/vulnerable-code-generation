//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_game(int guesses_left, char* word, char* guessed_letters) {
    printf("\nGuesses left: %d\n", guesses_left);
    printf("Word: ");
    for (int i=0; word[i] != '\0'; i++) {
        // if the letter has already been guessed
        if (strchr(guessed_letters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\nGuessed letters: %s\n", guessed_letters);
}

int main(void) {
    srand(time(0)); // seed the random number generator
    char *words[] = {"linux", "kernel", "opensource", "ubuntu", "terminal", "gcc", "gnu", "bash", "filesystem", "ssh", "sudo"};
    int num_words = sizeof(words)/sizeof(words[0]);
    int rand_index = rand() % num_words; // generate random index for word selection
    char *word = words[rand_index];
    int word_length = strlen(word);
    char guessed_letters[26] = ""; // initialize array to store guessed letters
    int guesses_left = 6;

    printf("Welcome to the Linus Torvalds-inspired Hangman game!\n");

    while(guesses_left > 0) {
        display_game(guesses_left, word, guessed_letters);

        // check if player has won
        int won = 1;
        for (int i=0; i<word_length; i++) {
            if (strchr(guessed_letters, word[i]) == NULL) {
                won = 0;
                break;
            }
        }
        if (won) {
            printf("\nCongratulations, you have won!\n");
            return 0;
        }

        char guess;
        printf("\nPlease enter a letter guess: ");
        scanf(" %c", &guess);
        if (strchr(guessed_letters, guess) != NULL) {
            printf("You already guessed that letter! Please try again.\n");
        } else {
            guessed_letters[strlen(guessed_letters)] = guess; // add letter to guessed letters array
            if (strchr(word, guess) == NULL) {
                printf("Sorry, the letter '%c' is not in the word.\n", guess);
                guesses_left--;
            }
        }
    }

    printf("\nSorry, you have run out of guesses. The word was '%s'.\n", word);
    return 0;
}