//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within the given range
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, result;
    char operator;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the arithmetic operator from the user
    printf("Enter the arithmetic operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform the arithmetic operation and display the result
    switch(operator) {
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
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }

    printf("The result of %d %c %d is %d.\n", num1, operator, num2, result);

    return 0;
}