//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to the post-apocalyptic scientific calculator\n\n");

    while(1) {
        printf("Enter the first number: ");
        if(scanf("%lf", &num1)!= 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("Enter the second number: ");
        if(scanf("%lf", &num2)!= 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        printf("Enter the operator (+, -, *, /, sin, cos, tan, sqrt): ");
        scanf(" %c", &operator);

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
                    printf("Division by zero is not allowed.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            case's':
                result = sin(num1);
                break;
            case 'c':
                result = cos(num1);
                break;
            case 't':
                result = tan(num1);
                break;
            case 'r':
                result = sqrt(num1);
                break;
            default:
                printf("Invalid operator. Please try again.\n");
                continue;
        }

        printf("The result is: %lf\n\n", result);
    }

    return 0;
}