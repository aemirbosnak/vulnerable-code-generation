//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Define variables
    int num1, num2, result;
    float num3, num4, sum;
    char operator;

    // Prompt user for input
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    printf("Enter the first float: ");
    scanf("%f", &num3);
    printf("Enter the second float: ");
    scanf("%f", &num4);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform arithmetic operations
    switch(operator) {
        case '+':
            result = num1 + num2;
            sum = num3 + num4;
            printf("%.2f + %.2f = %.2f\n", num3, num4, sum);
            printf("%d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            sum = num3 - num4;
            printf("%.2f - %.2f = %.2f\n", num3, num4, sum);
            printf("%d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            sum = num3 * num4;
            printf("%.2f * %.2f = %.2f\n", num3, num4, sum);
            printf("%d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = num1 / num2;
                sum = num3 / num4;
                printf("%.2f / %.2f = %.2f\n", num3, num4, sum);
                printf("%d / %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator entered!\n");
    }

    return 0;
}