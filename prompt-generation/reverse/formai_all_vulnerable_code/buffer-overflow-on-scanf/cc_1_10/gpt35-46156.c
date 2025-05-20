//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the factorial of a number
int factorial(int num) {
    if(num <= 1) {
        return 1;
    } else {
        return num * factorial(num-1);
    }
}

int main() {
    int num, option, count=0;
    float guess, answer, error;
    srand(time(0));   // Seed for random number generator
    
    printf("Welcome to the Math Exercise Program\n");
    printf("Choose an option:\n");
    printf("1. Factorial Exercise\n");
    printf("2. Guess the Number Exercise\n");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            // Factorial Exercise
            printf("\nFactorial Exercise\n");
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("Calculate %d!\n", num);
            answer = factorial(num);
            printf("Answer: %.f\n", answer);
            break;
            
        case 2:
            // Guess the Number Exercise
            printf("\nGuess the Number Exercise\n");
            printf("Guess a number between 1 and 100\n");
            int random = rand() % 100 + 1;   // Generate random number
            do {
                scanf("%f", &guess);
                error = guess - random;
                if(error < 0) {
                    error = error * -1;   // Convert to absolute value
                }
                count++;   // Increment number of tries
                if(guess < random) {
                    printf("Too low, try again!\n");
                } else if(guess > random) {
                    printf("Too high, try again!\n");
                } else {
                    printf("Congratulations, you guessed the number in %d tries!\n", count);
                }
            } while(guess != random);
            break;
        
        default:
            printf("Invalid option, try again!\n");
            break;
    }
    return 0;
}