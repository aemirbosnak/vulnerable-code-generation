//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number within given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to check if a character is present in an array
bool contains(char arr[], int size, char c) {
    for(int i=0; i<size; i++) {
        if(arr[i] == c) {
            return true;
        }
    }
    return false;
}

// function to prompt user for a letter
char promptLetter() {
    char c;
    printf("\nEnter a letter (a-z): ");
    scanf(" %c", &c);
    return c;
}

// function to print current status of game
void printGameStatus(char guessedLetters[], int numGuesses, char word[], int numSpaces) {
    printf("\nWord: ");
    for(int i=0; i<numSpaces; i++) {
        if(contains(guessedLetters, numGuesses, word[i])) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\nGuessed Letters: ");
    for(int i=0; i<numGuesses; i++) {
        printf("%c ", guessedLetters[i]);
    }
    printf("\nNumber of Guesses Left: %d\n", 10-numGuesses);
}

int main() {
    // initialize variables
    srand(time(NULL));
    char words[][6] = {"space", "ship", "alien", "planet", "orbit"}; // list of possible words
    int numWords = sizeof(words) / sizeof(words[0]); // calculate number of words
    char word[6]; // chosen word
    strcpy(word, words[generateRandomNumber(0, numWords-1)]); // choose random word from list
    
    char guessedLetters[10]; // array to hold guessed letters
    int numGuesses = 0; // number of guesses made
    
    int numSpaces = strlen(word); // number of spaces in word
    
    // main game loop
    while(numGuesses < 10) {
        printGameStatus(guessedLetters, numGuesses, word, numSpaces);
        char c = promptLetter(); // prompt user for letter
        
        if(contains(guessedLetters, numGuesses, c)) { // check if user already guessed letter
            printf("\nYou already guessed that letter!");
            continue;
        }
        
        guessedLetters[numGuesses] = c; // store guessed letter in array
        numGuesses++; // increment number of guesses made
        
        if(contains(word, numSpaces, c)) { // check if letter is in word
            printf("\nYou guessed a letter correctly!");
        } else {
            printf("\nYou guessed a letter incorrectly.");
        }
        
        bool allLettersGuessed = true;
        for(int i=0; i<numSpaces; i++) {
            if(!contains(guessedLetters, numGuesses, word[i])) {
                allLettersGuessed = false;
                break;
            }
        }
        
        if(allLettersGuessed) { // check if all letters have been guessed
            printf("\nCongratulations, you guessed the word!");
            break;
        }
    }
    
    printf("\nThe word was: %s", word);
    
    return 0;
}