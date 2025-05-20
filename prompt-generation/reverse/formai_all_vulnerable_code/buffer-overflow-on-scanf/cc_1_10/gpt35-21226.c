//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    
    int level = 1; // current level
    int guessLimit = 10; // number of guesses allowed per level
    
    int numDigits = 2; // number of digits in the secret number
    int maxNum = 99; // maximum possible value for the secret number
    
    while (level <= 10) { // play 10 levels
        
        int secretNumber = rand() % maxNum + 1; // generate secret number
        
        printf("Level %d\n", level); // display level number
        
        int guessCount = 0; // number of guesses so far
        
        while (guessCount < guessLimit) { // play until out of guesses
            
            printf("Guess a number between 1 and %d (%d guesses left): ", maxNum, guessLimit - guessCount);
            int guess;
            scanf("%d", &guess); // get user's guess
            
            if (guess < 1 || guess > maxNum) { // guess is out of range
                printf("Invalid guess. Please guess a number between 1 and %d.\n", maxNum);
                continue; // go back to the start of the loop
            }
            
            guessCount++; // increment guess count
            
            if (guess == secretNumber) { // guess is correct
                printf("Congratulations! You have won this level.\n");
                break; // exit loop
            } else if (guess < secretNumber) { // guess is too low
                printf("Too low. ");
            } else { // guess is too high
                printf("Too high. ");
            }
            
            if (guessCount == guessLimit) { // out of guesses
                printf("Sorry, you lose. The secret number was %d.\n", secretNumber);
            }
        }
        
        level++; // increment level
        
        if (level == 6) { // increase difficulty halfway through
            numDigits = 3;
            maxNum = 999;
            guessLimit = 15;
            printf("Difficulty increased!\n");
        }
    }
    
    printf("Congratulations! You have beaten all %d levels.\n", level - 1);
    return 0;
}