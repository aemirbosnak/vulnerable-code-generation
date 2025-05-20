//FormAI DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the Math Puzzler!\n");
    printf("Enter an equation using +, -, *, /, or %%. Example: 5 + 3\n");

    while (1) {
        if (scanf("%d %c %d", &num1, &operator, &num2) != 3) {
            printf("Oops! Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

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
                    printf("Error: Division by zero is undefined.\n");
                    exit(1);
                }
                result = num1 / num2;
                break;
            case '%':
                if (num2 == 0) {
                    printf("Error: Modulo by zero is undefined.\n");
                    exit(1);
                }
                result = num1 % num2;
                break;
            default:
                printf("Error: Invalid operator.\n");
                exit(1);
        }

        printf("%d %c %d = %d\n", num1, operator, num2, result);
        printf("Enter another equation or enter 'q' to quit.\n");

        char input = getchar();
        if (input == 'q') {
            printf("Goodbye!\n");
            break;
        }

        while (getchar() != '\n');
    }

    return 0;
}