//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option = 0;
    int num1 = 0, num2 = 0, result = 0;
    char symbol = '+';

    while (option != 4) {
        printf("\nMenu\n");
        printf("1. Enter First Number\n");
        printf("2. Enter Second Number\n");
        printf("3. Perform Operation\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter first number: ");
                scanf("%d", &num1);
                break;
            case 2:
                printf("Enter second number: ");
                scanf("%d", &num2);
                break;
            case 3:
                printf("Enter operation symbol (+,-,*,/): ");
                scanf(" %c", &symbol);
                switch (symbol) {
                    case '+':
                        result = num1 + num2;
                        printf("Result: %d", result);
                        break;
                    case '-':
                        result = num1 - num2;
                        printf("Result: %d", result);
                        break;
                    case '*':
                        result = num1 * num2;
                        printf("Result: %d", result);
                        break;
                    case '/':
                        if (num2 == 0) {
                            printf("Division by zero error\n");
                        } else {
                            result = num1 / num2;
                            printf("Result: %d", result);
                        }
                        break;
                    default:
                        printf("Invalid operation symbol\n");
                        break;
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}