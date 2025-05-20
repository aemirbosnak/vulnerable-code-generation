//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROBLEMS 5

// Function to generate random numbers within a specified range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to formulate a basic arithmetic problem
void generateProblem(int *num1, int *num2, char *operator) {
    *num1 = generateRandomNumber(1, 100);
    *num2 = generateRandomNumber(1, 100);
    int op_choice = generateRandomNumber(1, 3); // 1: add, 2: subtract
    
    if (op_choice == 1) {
        *operator = '+';
    } else {
        *operator = '-';
    }
}

// Function to calculate the answer based on the operator
int calculateAnswer(int num1, int num2, char operator) {
    if (operator == '+') {
        return num1 + num2;
    } else {
        return num1 - num2;
    }
}

// Main treasure hunt function
void treasureHunt() {
    int score = 0;
    int num1, num2, answer, userAnswer;
    char operator;
    
    printf("Welcome to the Treasure Hunt!\n");
    printf("You will solve %d arithmetic problems to gather treasures!\n\n", NUM_PROBLEMS);
    
    // Seed the random number generator
    srand(time(NULL));
    
    for (int i = 1; i <= NUM_PROBLEMS; i++) {
        generateProblem(&num1, &num2, &operator);
        answer = calculateAnswer(num1, num2, operator);
        
        printf("Problem %d: What is %d %c %d? ", i, num1, operator, num2);
        scanf("%d", &userAnswer);
        
        if (userAnswer == answer) {
            printf("Correct! You've uncovered a treasure!\n\n");
            score += 20; // Each correct answer enhances the score
        } else {
            printf("Oops! The correct answer was %d.\n\n", answer);
        }
    }
    
    printf("Your total score is: %d\n", score);
    
    // Calculate treasure chests based on the score
    int treasureChests = score / 20; // Each 20 points gives one treasure chest
    printf("You earned %d treasure chests!\n", treasureChests);
}

int main() {
    treasureHunt();
    printf("\nThank you for playing! Safe travels on your next adventure\n");
    return 0;
}