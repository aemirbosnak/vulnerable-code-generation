//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_DIGITS 20

int main() {
    int num_operations;
    int operation;
    int i, j, k;
    int num1, num2;
    int result;
    char input[MAX_DIGITS];
    char operation_string[MAX_DIGITS];
    char *endptr;

    // Prompt user for number of operations
    printf("Enter the number of operations: ");
    scanf("%d", &num_operations);

    // Perform specified number of operations
    for (i = 0; i < num_operations; i++) {
        // Prompt user for operation type
        printf("Enter operation type (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ");
        scanf("%d", &operation);

        // Prompt user for two numbers
        printf("Enter the first number: ");
        fgets(input, MAX_DIGITS, stdin);
        num1 = atoi(input);
        printf("Enter the second number: ");
        fgets(input, MAX_DIGITS, stdin);
        num2 = atoi(input);

        // Perform operation and print result
        switch (operation) {
            case 1:
                result = num1 + num2;
                printf("The result is: %d\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("The result is: %d\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("The result is: %d\n", result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("The result is: %d\n", result);
                }
                break;
            default:
                printf("Invalid operation type.\n");
        }
    }

    return 0;
}