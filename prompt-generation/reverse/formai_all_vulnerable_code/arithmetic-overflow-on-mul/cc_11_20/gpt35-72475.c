//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
    char input[MAX_INPUT_LENGTH];
    bool isValidInput = false;
    int num1 = 0, num2 = 0, result = 0;
    char operator = '\0';

    do {
        printf("Enter a mathematical expression: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input!\n");
            return 1;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check input for validity
        if (sscanf(input, "%d %c %d", &num1, &operator, &num2) == 3) {
            if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
                isValidInput = true;
            } else {
                printf("Invalid operator!\n");
            }
        } else {
            printf("Invalid input!\n");
        }
    } while (!isValidInput);

    switch (operator) {
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
                printf("Division by zero not allowed!\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}