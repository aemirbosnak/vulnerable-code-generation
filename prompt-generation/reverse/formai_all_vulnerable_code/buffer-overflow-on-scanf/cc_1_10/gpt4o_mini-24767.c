//GPT-4o-mini DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_ATTEMPTS 5
#define MAX_WORD_LENGTH 20
#define WORDLIST_SIZE 10

// Function Prototypes
void printWelcomeMessage();
void getRandomWord(char *word, char wordList[][MAX_WORD_LENGTH]);
void playGame(char *word);
void displayCurrentState(char *word, char *guessedLetters);
int checkLetter(char letter, char *word, char *guessedLetters);

int main() {
    char wordList[WORDLIST_SIZE][MAX_WORD_LENGTH] = {
        "programming",
        "computer",
        "linux",
        "challenge",
        "hangman",
        "function",
        "variable",
        "pointer",
        "stack",
        "heap"
    };

    char randomWord[MAX_WORD_LENGTH];

    printWelcomeMessage();
    getRandomWord(randomWord, wordList);
    playGame(randomWord);

    return 0;
}

void printWelcomeMessage() {
    printf("*************************************\n");
    printf("*         Welcome to Hangman!       *\n");
    printf("*************************************\n");
    printf("Guess the word letter by letter!\n");
    printf("You have %d attempts to guess it right.\n", MAX_ATTEMPTS);
}

void getRandomWord(char *word, char wordList[][MAX_WORD_LENGTH]) {
    srand(time(0));
    int randomIndex = rand() % WORDLIST_SIZE;
    strcpy(word, wordList[randomIndex]);
}

void playGame(char *word) {
    int attemptsLeft = MAX_ATTEMPTS;
    int wordLength = strlen(word);
    char guessedLetters[26] = {0}; // Store the guessed letters
    int wrongGuesses = 0;

    while(attemptsLeft > 0 && wrongGuesses < wordLength) {
        displayCurrentState(word, guessedLetters);
        
        char guess;
        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);
        guess = tolower(guess); // Make the guess lowercase

        if (checkLetter(guess, word, guessedLetters)) {
            printf("Good guess!\n");
        } else {
            printf("Wrong guess. Try again!\n");
            wrongGuesses++;
            attemptsLeft--;
            printf("Attempts left: %d\n", attemptsLeft);
        }
    }

    if (wrongGuesses == wordLength) {
        printf("Sorry, you've lost! The word was: %s\n", word);
    } else {
        printf("Congratulations! You've guessed the word: %s\n", word);
    }
}

void displayCurrentState(char *word, char *guessedLetters) {
    printf("Current Word: ");
    for (int i = 0; i < strlen(word); i++) {
        if (strchr(guessedLetters, word[i])) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int checkLetter(char letter, char *word, char *guessedLetters) {
    if (strchr(guessedLetters, letter) != NULL) {
        printf("You already guessed that letter.\n");
        return 0;
    }

    // Add guessed letter to guessedLetters
    strncat(guessedLetters, &letter, 1);
    
    // Check if letter is in the word
    return (strchr(word, letter) != NULL);
}