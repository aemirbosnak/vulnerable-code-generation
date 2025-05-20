//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

void math_exercise(int *numbers, int num_questions, int *answers) {
    int i, j, k, random_number;
    double result;

    // Roll the dice to determine the order of operations
    srand(time(NULL));
    random_number = rand() % 3;

    for (i = 0; i < num_questions; i++) {
        // Generate a math problem
        switch (random_number) {
            case 0: // Addition
                numbers[i] = rand() % 100;
                answers[i] = numbers[i] + MAGIC_NUMBER;
                break;
            case 1: // Subtraction
                numbers[i] = rand() % 100;
                answers[i] = numbers[i] - MAGIC_NUMBER;
                break;
            case 2: // Multiplication
                numbers[i] = rand() % 100;
                answers[i] = numbers[i] * MAGIC_NUMBER;
                break;
        }

        // Print the math problem
        printf("Question %d: %d + %d = ?\n", i + 1, numbers[i], MAGIC_NUMBER);

        // Get the user's answer
        scanf("%d", &result);

        // Check if the user got it right
        if (result == answers[i]) {
            printf("Correct! The answer is %d\n", answers[i]);
        } else {
            printf("Oops, that's not correct. The answer is %d\n", answers[i]);
        }
    }
}

int main() {
    int num_questions = 5;
    int numbers[5] = {0};
    int answers[5] = {0};

    math_exercise(numbers, num_questions, answers);

    return 0;
}