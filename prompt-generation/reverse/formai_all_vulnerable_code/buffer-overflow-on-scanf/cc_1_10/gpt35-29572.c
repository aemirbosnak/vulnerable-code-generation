//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int); // Function prototype for the main game function
void generateNumbers(int*, int, int); // Function prototype for generating random numbers
int checkGuess(int, int, int); // Function prototype for checking guess and returning result
void printScore(int, int); // Function prototype for printing final score

int main() {
    int level;
    
    printf("Welcome to the Number Guessing Game!\n\n");
    printf("Choose your level: \n");
    printf("1. Easy (0-10)\n");
    printf("2. Medium (0-50)\n");
    printf("3. Hard (0-100)\n");
    
    scanf("%d", &level);
    
    playGame(level); // Call main game function
    
    return 0;
}

void playGame(int level) {
    int max, num1, num2, guess, attempts_left = 5, score = 0;
    
    // Set max value based on level selected
    switch(level) {
        case 1:
            max = 10;
            break;
        case 2:
            max = 50;
            break;
        case 3:
            max = 100;
            break;
        default:
            printf("Invalid level selected. Please try again.");
            return;
    }
    
    int rand_nums[2]; // Array to store random numbers
    
    generateNumbers(rand_nums, max, 2); // Call function to generate random numbers
    
    num1 = rand_nums[0];
    num2 = rand_nums[1];
    
    printf("\nI'm thinking of two numbers between 0 and %d. Can you guess both of them?\n", max);
    
    while(attempts_left > 0) {
        printf("\nAttempts left: %d\n", attempts_left);
        printf("Guess no. 1: ");
        scanf("%d", &guess);
        
        if(checkGuess(guess, num1, max) == 0) {
            printf("Incorrect guess. Please try again.\n");
            attempts_left--;
            continue;
        } else {
            printf("Correct!\n");
        }
        
        printf("Guess no. 2: ");
        scanf("%d", &guess);
        
        if(checkGuess(guess, num2, max) == 0) {
            printf("Incorrect guess. Please try again.\n");
            attempts_left--;
            continue;
        } else {
            printf("Correct!\n");
        }
        
        printf("\nYou guessed both numbers correctly!\n");
        printf("Attempts left: %d, Score: %d\n", attempts_left, score++);
        generateNumbers(rand_nums, max, 2); // Generate new random numbers for next round
        num1 = rand_nums[0];
        num2 = rand_nums[1];
    }
    
    printScore(score, level); // Call function to print final score
}

void generateNumbers(int* arr, int max, int size) {
    srand(time(NULL)); // Seed random number generator with time
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = rand() % max + 1;
    }
}

int checkGuess(int guess, int num, int max) {
    if(guess < 0 || guess > max) { // Check if guess is within valid range
        return 0;
    } else if(guess == num) {
        return 1;
    } else {
        return 0;
    }
}

void printScore(int score, int level) {
    printf("\nGame over! Your final score is: %d\n", score);
    switch(level) {
        case 1:
            printf("You played on Easy mode.");
            break;
        case 2:
            printf("You played on Medium mode.");
            break;
        case 3:
            printf("You played on Hard mode.");
            break;
    }
}