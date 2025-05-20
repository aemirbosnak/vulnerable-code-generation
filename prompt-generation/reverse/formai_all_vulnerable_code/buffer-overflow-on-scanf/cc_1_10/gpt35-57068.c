//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int generateRandomNumber(int min, int max){
    return (rand() % (max + 1 - min)) + min;
}

int main(){
    // Setting up variables
    int number, guess, numGuesses = 0, min = 1, max = 100;
    
    // Setting up random seed
    srand(time(NULL));
    
    // Generating random number between 1 and 100
    number = generateRandomNumber(min, max);
    
    printf("Welcome to the Number Guessing Game!\n\n");
    printf("I'm thinking of a number between %d and %d. Can you guess what it is?\n\n", min, max);
    
    // Loop until correct guess is made
    while(1){
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        // Check if guess is within range
        if(guess < min || guess > max){
            printf("\nInvalid guess. Your guess must be between %d and %d.\n\n", min, max);
            continue;
        }
        
        numGuesses++;
        
        // Check if guess is correct
        if(guess == number){
            printf("\nCongratulations! You guessed the number in %d tries.\n", numGuesses);
            break;
        }
        else if(guess < number){
            printf("Sorry, your guess is too low. Try again.\n\n");
        }
        else{
            printf("Sorry, your guess is too high. Try again.\n\n");
        }
    }
    
    printf("\nThanks for playing!");
    
    return 0;
}