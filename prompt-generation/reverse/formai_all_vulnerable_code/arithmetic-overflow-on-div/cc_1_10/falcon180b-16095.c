//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int num1, num2, operator, result;
    char choice;

    while (1) {
        printf("Enter 'c' to calculate or 'q' to quit: ");
        scanf("%c", &choice);
        if (choice == 'q') {
            break;
        }

        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("Enter the operator (+, -, *, /): ");
        scanf("%c", &operator);

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
                    printf("Error: Division by zero\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Error: Invalid operator\n");
                continue;
        }

        printf("Result: %d\n", result);
    }

    return 0;
}