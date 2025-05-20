//GPT-4o-mini DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 10
#define WORD_LENGTH 20
#define WORD_LIST_SIZE 5

// Function to display the current state of the guessed word
void displayWord(char *word, int *guessed) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Function to check if the word has been fully guessed
int isWordGuessed(int *guessed, int length) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) {
            return 0; // Word not fully guessed
        }
    }
    return 1; // Word fully guessed
}

// Function to get a random word from the word list
void getRandomWord(char *word) {
    const char *wordList[WORD_LIST_SIZE] = {
        "programming",
        "linux",
        "computer",
        "developer",
        "challenge"
    };
    
    int randomIndex = rand() % WORD_LIST_SIZE;
    strcpy(word, wordList[randomIndex]);
}

// Function to initialize the guessed array
void initializeGuessedArray(int *guessed, int length) {
    for (int i = 0; i < length; i++) {
        guessed[i] = 0; // Initialize all letters as not guessed
    }
}

// Function to play the game
void playGame() {
    char word[WORD_LENGTH];
    getRandomWord(word);
    int length = strlen(word);
    int guessed[length];
    int remainingGuesses = MAX_GUESSES;
    
    initializeGuessedArray(guessed, length);
    
    printf("Welcome to the Word Guessing Game!\n");
    printf("You have %d guesses to find the word.\n", MAX_GUESSES);
    
    while (remainingGuesses > 0 && !isWordGuessed(guessed, length)) {
        printf("Current word: ");
        displayWord(word, guessed);
        
        char guess;
        printf("Enter a letter to guess: ");
        scanf(" %c", &guess);
        
        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                guessed[i] = 1; // Mark letter as guessed
                found = 1;
            }
        }
        
        if (!found) {
            remainingGuesses--;
            printf("Wrong guess! Remaining guesses: %d\n", remainingGuesses);
        } else {
            printf("Good guess!\n");
        }
        
        if (isWordGuessed(guessed, length)) {
            printf("Congratulations! You've guessed the word: %s\n", word);
            break;
        }
    }
    
    if (remainingGuesses == 0) {
        printf("Sorry, you've run out of guesses. The word was: %s\n", word);
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    playGame();
    return 0;
}