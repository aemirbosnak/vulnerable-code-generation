//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, choice;
    char operator;

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform arithmetic operation based on operator
    switch(operator) {
        case '+':
            printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("The difference between %d and %d is %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("The product of %d and %d is %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2!= 0) {
                printf("The quotient of %d and %d is %.2f\n", num1, num2, (float)num1 / num2);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    // Prompt user for another calculation
    printf("Do you want to perform another calculation? (y/n): ");
    scanf(" %c", &choice);

    // Loop until user wants to quit
    while(choice == 'y' || choice == 'Y') {
        // Repeat calculation process
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &operator);

        switch(operator) {
            case '+':
                printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("The difference between %d and %d is %d\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("The product of %d and %d is %d\n", num1, num2, num1 * num2);
                break;
            case '/':
                if(num2!= 0) {
                    printf("The quotient of %d and %d is %.2f\n", num1, num2, (float)num1 / num2);
                } else {
                    printf("Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid operator.\n");
        }

        // Prompt user for another calculation
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}