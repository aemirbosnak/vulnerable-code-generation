//FormAI DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, guess, tries = 0;
    char operation;
    srand(time(0));  // Seed the random number generator

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given two randomly generated integers and an operation to perform.\n");
    printf("Your task is to guess the result of the operation in order to solve the equation.\n");
    printf("You have 3 tries to guess correctly and earn a point.\n\n");

    while(1) {
        // Generate two random numbers between 0 and 9
        num1 = rand() % 10;
        num2 = rand() % 10;

        // Generate a random operation: +, -, *, or /
        switch(rand() % 4) {
            case 0: operation = '+'; result = num1 + num2; break;
            case 1: operation = '-'; result = num1 - num2; break;
            case 2: operation = '*'; result = num1 * num2; break;
            case 3: operation = '/'; result = num1 / num2; break;
        }

        // Display the equation to the user
        printf("EQUATION %d:\n", tries+1);
        printf("%d %c %d = ?\n", num1, operation, num2);

        // Keep prompting the user to guess until they either get it right or run out of tries
        for(int i = 0; i < 3; i++) {
            printf("Guess #%d: ", i+1);
            scanf("%d", &guess);

            if(guess == result) {
                printf("Correct!\n");
                tries++;
                break;
            }
            else {
                printf("Incorrect.\n");
            }
        }

        // After 3 tries, display the correct answer and move on to the next equation
        printf("The correct answer was %d.\n", result);
        printf("On to the next equation!\n\n");
    }
    return 0;
}