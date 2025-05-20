//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
// Guess the Word Game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 20
#define MAX_NUM_TRIES 5

char *getRandomWord();

int main() {
    char *wordToGuess = getRandomWord();
    int wordLen = strlen(wordToGuess);
    char guessedWord[wordLen + 1]; // the current state of the guessed word
    for (int i = 0; i < wordLen; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLen] = '\0';
    int numTries = 0; // the number of tries the player has taken
    int numCorrectGuesses = 0; // the number of correct guesses made so far

    printf("Welcome to Guess the Word Game!\n");
    printf("You have %d tries to guess the word.", MAX_NUM_TRIES);
    printf("\n\n");
    printf("The word is:\n");
    printf("%s\n", guessedWord);
    printf("\n");

    while (numTries < MAX_NUM_TRIES && numCorrectGuesses < wordLen) {
        printf("Guess a letter: ");
        char guess[2];
        scanf("%s", guess);
        char letter = guess[0];

        // check if the letter has already been guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < wordLen; i++) {
            if (letter == guessedWord[i]) {
                alreadyGuessed = 1;
                printf("You already guessed that letter!\n");
                break;
            }
        }
        if (alreadyGuessed) {
            continue;
        }

        // check if the letter is in the word
        int letterFound = 0;
        for (int i = 0; i < wordLen; i++) {
            if (letter == wordToGuess[i]) {
                guessedWord[i] = letter;
                numCorrectGuesses++;
                letterFound = 1;
            }
        }
        if (letterFound) {
            printf("Correct!\n");
        } else {
            printf("Wrong! Try again.\n");
            numTries++;
        }

        printf("The word is now:\n");
        printf("%s\n", guessedWord);
        printf("\n");
    }

    if (numCorrectGuesses == wordLen) {
        printf("Congratulations! You guessed the word: %s", wordToGuess);
    } else {
        printf("Sorry, you ran out of tries. The word was: %s", wordToGuess);
    }

    return 0;
}

char *getRandomWord() {
    char *wordList[] = {"apple", "banana", "cherry", "orange", "pear", "grape", "strawberry",
                        "kiwi", "pineapple", "apricot", "blueberry", "lemon", "mango", "peach",
                        "plum", "watermelon", "pomegranate", "raspberry", "blackberry", "coconut"};
    int numWords = sizeof(wordList) / sizeof(char *);
    srand(time(NULL));
    int randomIndex = rand() % numWords;
    return wordList[randomIndex];
}