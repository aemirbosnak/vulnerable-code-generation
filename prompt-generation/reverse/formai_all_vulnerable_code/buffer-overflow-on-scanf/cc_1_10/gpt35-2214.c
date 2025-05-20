//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define max and min values for random number generator
#define MAX_VAL 20
#define MIN_VAL 1

int main() {
    int x, y, answer, user_answer, correct_answers = 0;

    // Seed random number generator
    srand(time(NULL));

    // Generate 5 random math problems
    for (int i = 0; i < 5; i++) {
        // Generate two random numbers between MIN_VAL and MAX_VAL
        x = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
        y = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;

        // Choose random operation
        int op = rand() % 4;

        // Create math problem based on random operation
        if (op == 0) {
            // Addition
            answer = x + y;
            printf("%d + %d = ", x, y);
        } else if (op == 1) {
            // Subtraction
            answer = x - y;
            printf("%d - %d = ", x, y);
        } else if (op == 2) {
            // Multiplication
            answer = x * y;
            printf("%d * %d = ", x, y);
        } else {
            // Division
            // Make sure y is not 0
            while (y == 0) {
                y = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
            }
            answer = x / y;
            printf("%d / %d = ", x, y);
        }

        // Get user's input
        scanf("%d", &user_answer);

        // Check if user's answer is correct, print message, and update correct_answers counter
        if (user_answer == answer) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %d\n", answer);
        }
    }

    // Print final score
    printf("You got %d out of 5 questions correct.\n", correct_answers);

    return 0;
}