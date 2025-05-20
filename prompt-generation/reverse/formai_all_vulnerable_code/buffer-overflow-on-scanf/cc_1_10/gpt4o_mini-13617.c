//GPT-4o-mini DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 5
#define MAX_WORD_LENGTH 20
#define WORD_LIST_SIZE 10

// Function to clear the screen
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to display the welcome message
void displayWelcomeMessage() {
    clearScreen();
    printf("*****************************************\n");
    printf("** Welcome to the Word Guessing Game! **\n");
    printf("*****************************************\n");
}

// Function to get the random word from the list
const char* getRandomWord() {
    const char* words[WORD_LIST_SIZE] = {
        "elephant", "giraffe", "kangaroo", "panda", "dolphin",
        "penguin", "tiger", "zebra", "hippopotamus", "rhino"
    };
    srand(time(0));
    return words[rand() % WORD_LIST_SIZE];
}

// Function to display the current state of the guessed word
void displayCurrentState(const char* secretWord, char* guessedWord) {
    printf("Current Word: ");
    for (int i = 0; i < strlen(secretWord); i++) {
        printf("%c ", guessedWord[i]);
    }
    printf("\n");
}

// Function to check if the guessed letter is in the secret word
int checkGuess(char guess, const char* secretWord, char* guessedWord) {
    int found = 0;
    for (int i = 0; i < strlen(secretWord); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
            found = 1;
        }
    }
    return found;
}

// Function to check if the player has guessed the word
int isWordGuessed(const char* secretWord, const char* guessedWord) {
    return strcmp(secretWord, guessedWord) == 0;
}

// The main game logic function
void playGame() {
    const char* secretWord = getRandomWord();
    char guessedWord[MAX_WORD_LENGTH + 1];
    char guess;
    int attempts = 0;

    // Initialize the guessed word with underscores
    for (int i = 0; i < strlen(secretWord); i++) {
        guessedWord[i] = '_';
    }
    guessedWord[strlen(secretWord)] = '\0'; // Null terminate the string

    while (attempts < MAX_GUESSES) {
        displayCurrentState(secretWord, guessedWord);
        printf("Attempts left: %d\n", MAX_GUESSES - attempts);
        printf("Enter a letter to guess: ");
        scanf(" %c", &guess); // Read a single character input

        // Check if the guessed letter is valid
        if (checkGuess(guess, secretWord, guessedWord)) {
            printf("Good guess!\n");
            if (isWordGuessed(secretWord, guessedWord)) {
                printf("Congratulations! You've guessed the word: %s\n", secretWord);
                return;
            }
        } else {
            printf("Oops! The letter '%c' is not in the word.\n", guess);
            attempts++;
        }
    }
    printf("Sorry! You've used all your attempts. The word was: %s\n", secretWord);
}

// Main function
int main() {
    char playAgain;

    do {
        displayWelcomeMessage();
        playGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing the Word Guessing Game! Goodbye!\n");
    return 0;
}