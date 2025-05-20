//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numExercises, minValue, maxValue, operation, i, num1, num2, result, answer, correctCount = 0, wrongCount = 0;
    srand(time(NULL)); // seed the random number generator

    // prompt user for number of exercises to generate
    printf("How many exercises would you like to generate? ");
    scanf("%d", &numExercises);

    // prompt user for range of values to use in exercises
    printf("What is the minimum value to use in exercises? ");
    scanf("%d", &minValue);
    printf("What is the maximum value to use in exercises? ");
    scanf("%d", &maxValue);

    // prompt user for type of operation to use
    printf("What type of operation would you like to use?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &operation);

    // generate exercises and prompt user for answers
    for (i = 0; i < numExercises; i++) {
        // generate two random numbers within the specified range
        num1 = rand() % (maxValue - minValue + 1) + minValue;
        num2 = rand() % (maxValue - minValue + 1) + minValue;

        switch (operation) {
            case 1: // addition
                result = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case 2: // subtraction
                result = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case 3: // multiplication
                result = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
            case 4: // division
                result = num1 / num2;
                printf("%d / %d = ", num1, num2);
                break;
            default:
                printf("Invalid operation selected. Please try again.\n");
                i--; // decrement i to repeat this exercise
                continue;
        }

        scanf("%d", &answer);
        if (answer == result) {
            printf("Correct!\n");
            correctCount++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", result);
            wrongCount++;
        }
    }

    // print final results
    printf("You completed %d exercises with %d correct and %d incorrect answers.\n", numExercises, correctCount, wrongCount);

    return 0;
}