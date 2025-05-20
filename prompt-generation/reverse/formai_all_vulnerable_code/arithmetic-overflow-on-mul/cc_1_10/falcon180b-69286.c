//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, operator, result;
    char op;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for two numbers and an operator
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the arithmetic operation based on the operator
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    // Generate a random number and perform the same arithmetic operation on it
    int rand_num1 = rand_num(1, 100);
    int rand_num2 = rand_num(1, 100);
    int rand_result;

    switch (op) {
        case '+':
            rand_result = rand_num1 + rand_num2;
            break;
        case '-':
            rand_result = rand_num1 - rand_num2;
            break;
        case '*':
            rand_result = rand_num1 * rand_num2;
            break;
        case '/':
            if (rand_num2 == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            rand_result = rand_num1 / rand_num2;
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    // Print the results
    printf("Result: %d\n", result);
    printf("Random result: %d\n", rand_result);

    return 0;
}