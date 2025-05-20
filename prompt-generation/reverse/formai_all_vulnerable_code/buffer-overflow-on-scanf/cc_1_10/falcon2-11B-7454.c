//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calculate(int num1, int num2, char operation) {
    int result = 0;
    switch (operation) {
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
                return;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator!\n");
            return;
    }
    printf("Result: %d\n", result);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int num1 = rand() % 100; // Generate a random number between 0 and 99
    int num2 = rand() % 100; // Generate a random number between 0 and 99

    char operation;
    while (1) {
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &operation);

        if (operation == 'q') {
            break; // Exit the program
        }

        calculate(num1, num2, operation);
    }

    return 0;
}