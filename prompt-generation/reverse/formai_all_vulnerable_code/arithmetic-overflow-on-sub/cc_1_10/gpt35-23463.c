//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>
#include <math.h>

int main() {

    int num1, num2;
    float result = 0;
    char operation;

    printf("Welcome to Calculator 3000\n");

    printf("Please enter first number: ");
    scanf("%d", &num1);

    printf("Please enter second number: ");
    scanf("%d", &num2);

    printf("Please enter the operation(+, -, *, /): ");
    scanf(" %c", &operation);

    switch(operation) {
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
                printf("Error: Cannot divide by zero\n");
                return 1;
            } else {
                result = (float)num1 / num2;
                break;
            }
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    printf("The result is: %f\n", result);

    if(result >= 0) {
        printf("The absolute value of the result is: %f\n", fabs(result));
    } else {
        printf("The square root of the result is: %f\n", sqrt((float)fabs(result)));
    }

    printf("Thank you for using Calculator 3000\n");

    return 0;
}