//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    int num1, num2, answer, userAnswer, numCorrect = 0, numIncorrect = 0;

    // Set the number of exercises to generate
    const int NUM_EXERCISES = 10;

    printf("Welcome to the Math Exercise Program!\n\n");

    for (int i = 1; i <= NUM_EXERCISES; i++) {
        // Generate two random numbers between 1 and 20
        num1 = rand() % 20 + 1;
        num2 = rand() % 20 + 1;

        // Generate a random number between 1 and 4 to determine the operation
        int operation = rand() % 4 + 1;

        switch(operation) {
            case 1: // Addition
                answer = num1 + num2;
                printf("%d) %d + %d = ", i, num1, num2);
                break;
            case 2: // Subtraction
                answer = num1 - num2;
                printf("%d) %d - %d = ", i, num1, num2);
                break;
            case 3: // Multiplication
                answer = num1 * num2;
                printf("%d) %d * %d = ", i, num1, num2);
                break;
            case 4: // Division
                // Ensure num2 is not 0
                while (num2 == 0) {
                    num2 = rand() % 20 + 1;
                }
                // Ensure the two numbers divide evenly
                num1 = num2 * (rand() % 20 + 1);
                answer = num1 / num2;
                printf("%d) %d / %d = ", i, num1, num2);
                break;
        }

        // Get the user's answer and compare to the correct answer
        scanf("%d", &userAnswer);

        if (userAnswer == answer) {
            printf("Great job! That's correct.\n\n");
            numCorrect++;
        } else {
            printf("Sorry, that's incorrect. The answer is %d.\n\n", answer);
            numIncorrect++;
        }
    }

    printf("You got %d exercises correct and %d exercises incorrect.\n", numCorrect, numIncorrect);

    return 0;
}