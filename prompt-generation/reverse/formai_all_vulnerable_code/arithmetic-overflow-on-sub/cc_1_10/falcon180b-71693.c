//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1, num2, result;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the arithmetic operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%d", &num2);

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
            if(num2!= 0) {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            } else {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid operator! Please try again.\n");
    }

    return 0;

}