//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char string[100];
    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    printf("Please enter the operator (+, -, *, /): ");
    scanf("%c", &operator);
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            }
            break;
        default:
            printf("Error: Invalid operator entered.\n");
            break;
    }
    printf("Would you like to perform another calculation? (y/n): ");
    scanf(" %c", &operator);
    while(operator == 'y' || operator == 'Y') {
        printf("\n");
        printf("Please enter the first number: ");
        scanf("%d", &num1);
        printf("Please enter the second number: ");
        scanf("%d", &num2);
        printf("Please enter the operator (+, -, *, /): ");
        scanf("%c", &operator);
        switch(operator) {
            case '+':
                result = num1 + num2;
                printf("The result is: %d\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("The result is: %d\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("The result is: %d\n", result);
                break;
            case '/':
                if(num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("The result is: %d\n", result);
                }
                break;
            default:
                printf("Error: Invalid operator entered.\n");
                break;
        }
        printf("Would you like to perform another calculation? (y/n): ");
        scanf(" %c", &operator);
    }
    return 0;
}