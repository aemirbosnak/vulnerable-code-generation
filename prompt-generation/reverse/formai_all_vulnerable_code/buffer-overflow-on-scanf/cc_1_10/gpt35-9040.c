//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
/*
 * Ada's Memory Game
 * Written by: [Your Name]
 * Date: [Date]
 * Description: A memory game where the user has to remember a sequence of numbers and repeat them back.
 * Ada Lovelace style program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Used to seed random number generator

#define MAX_SEQUENCE_LENGTH 10 //Maximum length of the number sequence
#define MAX_NUMBER 9 //Maximum value for each number in the sequence

//Function declarations
void generateSequence(int sequence[], int length);
void displaySequence(int sequence[], int length);
int getPlayerGuess(int guesses[], int length);
int checkGuess(int sequence[], int guess[], int length);

int main() {
    //Seed the random number generator with the current time
    srand(time(NULL));
    
    //Declare variables
    int sequence[MAX_SEQUENCE_LENGTH];
    int playerGuesses[MAX_SEQUENCE_LENGTH];
    int sequenceLength = 4;
    int round = 1;
    int correctGuesses;
    int i, j;
    
    //Game loop
    while(sequenceLength <= MAX_SEQUENCE_LENGTH) {
        printf("Round %d\n", round);
        
        //Generate and display the sequence
        generateSequence(sequence, sequenceLength);
        displaySequence(sequence, sequenceLength);
        
        //Get the player's guess for each number in the sequence
        correctGuesses = 0;
        for(i = 0; i < sequenceLength; i++) {
            playerGuesses[i] = getPlayerGuess(playerGuesses, i); //Player cannot repeat a guess
            if(playerGuesses[i] == sequence[i]) {
                correctGuesses++;
            }
        }
        
        //Check if the player guessed the sequence correctly
        if(correctGuesses == sequenceLength) {
            printf("Congratulations, you guessed the sequence correctly!\n");
            round++;
            sequenceLength++;
        } else {
            printf("Sorry, that was not the correct sequence.\n");
            printf("You got %d out of %d correct.\n", correctGuesses, sequenceLength);
        }
    }
    
    printf("Game over, you completed the sequence with length %d.\n", MAX_SEQUENCE_LENGTH);
    return 0;
}

/*
 * Generates a random number sequence of the specified length
 */
void generateSequence(int sequence[], int length) {
    int i;
    for(i = 0; i < length; i++) {
        sequence[i] = rand() % MAX_NUMBER + 1;
    }
}

/*
 * Displays the number sequence to the console
 */
void displaySequence(int sequence[], int length) {
    int i;
    printf("Memorize the sequence: ");
    for(i = 0; i < length; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

/*
 * Prompts the player for a guess and validates it
 */
int getPlayerGuess(int guesses[], int length) {
    int guess;
    do {
        printf("Enter your guess for the number at position %d: ", length + 1);
        scanf("%d", &guess);
    } while(guess < 1 || guess > MAX_NUMBER || duplicateGuess(guess, guesses, length));
    return guess;
}

/*
 * Checks if the player's guess is correct
 */
int checkGuess(int sequence[], int guess[], int length) {
    int i;
    int correctGuesses = 0;
    for(i = 0; i < length; i++) {
        if(guess[i] == sequence[i]) {
            correctGuesses++;
        }
    }
    return correctGuesses;
}

/*
 * Checks if the player has already guessed the current number
 */
int duplicateGuess(int guess, int guesses[], int length) {
    int i;
    for(i = 0; i < length; i++) {
        if(guess == guesses[i]) {
            printf("You already guessed that number, try again.\n");
            return 1;
        }
    }
    return 0;
}