//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
// This program generates a unique C Math exercise example program in an optimized style.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generating random seed
    srand(time(NULL));

    // Initializing variables
    double num1, num2, result;
    char operator, choice;

    do {
        // Generating random numbers
        num1 = (double) rand() / RAND_MAX * 10.0;
        num2 = (double) rand() / RAND_MAX * 10.0;

        // Generating random operator
        int opIndex = rand() % 4;
        if (opIndex == 0) {
            operator = '+';
            result = num1 + num2;
        } else if (opIndex == 1) {
            operator = '-';
            result = num1 - num2;
        } else if (opIndex == 2) {
            operator = '*';
            result = num1 * num2;
        } else {
            operator = '/';
            result = num1 / num2;
        }

        printf("What is %.2f %c %.2f? ", num1, operator, num2);

        // Taking user input
        double userAnswer;
        scanf("%lf", &userAnswer);

        // Checking user answer
        if (fabs(userAnswer - result) < 0.0001) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %.2f\n", result);
        }

        // Asking to continue
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}