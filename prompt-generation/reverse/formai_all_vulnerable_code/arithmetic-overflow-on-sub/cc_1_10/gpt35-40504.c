//FormAI DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a set of random math exercises and allows the user
   to solve them. The user can choose the number of exercises and the maximum
   value for the operands. */

int main() {
    int num_exercises, max_value, i, j, operator, operand1, operand2, answer, input;

    srand(time(0)); // seed random number generator

    printf("How many exercises would you like to generate?\n");
    scanf("%d", &num_exercises);

    printf("What is the maximum value for the operands?\n");
    scanf("%d", &max_value);

    printf("\n");

    for (i = 0; i < num_exercises; i++) {
        operator = rand() % 3;
        operand1 = rand() % max_value + 1;
        operand2 = rand() % max_value + 1;

        switch (operator) {
            case 0: // addition
                printf("%d + %d = ", operand1, operand2);
                answer = operand1 + operand2;
                break;
            case 1: // subtraction
                if (operand1 < operand2) { // swap operands
                    int temp = operand1;
                    operand1 = operand2;
                    operand2 = temp;
                }
                printf("%d - %d = ", operand1, operand2);
                answer = operand1 - operand2;
                break;
            case 2: // multiplication
                printf("%d * %d = ", operand1, operand2);
                answer = operand1 * operand2;
                break;
        }

        scanf("%d", &input);

        if (input == answer) {
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is %d.\n", answer);
        }

        printf("\n");
    }

    return 0;
}