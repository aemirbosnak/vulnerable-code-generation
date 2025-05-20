//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: dynamic
/*
 * Unique C Math Exercise Program
 *
 * This program generates a random math exercise with a dynamic style.
 * The exercise can be a basic arithmetic operation (+, -, *, /)
 * with two random integers between 1 and 10.
 * The user must input the correct answer to get a score.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT 10

int main() {
    srand(time(NULL));

    int num1, num2, answer, user_input;
    char operation;

    // Generate random integers and operation
    num1 = rand() % MAX_INT + 1;
    num2 = rand() % MAX_INT + 1;
    operation = rand() % 4;

    // Print the exercise
    printf("Solve the following exercise:\n");
    switch (operation) {
        case 0:
            printf("%d + %d = ", num1, num2);
            break;
        case 1:
            printf("%d - %d = ", num1, num2);
            break;
        case 2:
            printf("%d * %d = ", num1, num2);
            break;
        case 3:
            printf("%d / %d = ", num1, num2);
            break;
    }

    // Get user input
    scanf("%d", &user_input);

    // Calculate the answer
    switch (operation) {
        case 0:
            answer = num1 + num2;
            break;
        case 1:
            answer = num1 - num2;
            break;
        case 2:
            answer = num1 * num2;
            break;
        case 3:
            answer = num1 / num2;
            break;
    }

    // Check the answer
    if (user_input == answer) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", answer);
    }

    return 0;
}