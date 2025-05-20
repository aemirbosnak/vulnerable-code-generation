//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, sum = 0;
    char operation;
    double result;

    printf("Welcome to the Arithmetic Calculator!\n");

    while(1) {
        printf("\nEnter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &operation);

        switch(operation) {
            case '+':
                sum = num1 + num2;
                printf("\nThe sum is %d.\n", sum);
                break;
            case '-':
                result = num1 - num2;
                printf("\nThe difference is %.2f.\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("\nThe product is %.2f.\n", result);
                break;
            case '/':
                if(num2 == 0) {
                    printf("\nCannot divide by zero.\n");
                } else {
                    result = (double)num1 / num2;
                    printf("\nThe quotient is %.2f.\n", result);
                }
                break;
            default:
                printf("\nInvalid operation. Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        char cont;
        scanf(" %c", &cont);
        if(cont == 'n' || cont == 'N') {
            break;
        }
    }

    printf("\nThank you for using the Arithmetic Calculator.\n");

    return 0;
}