//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>

int main() {
    int num1, num2, result;
    float num3, num4, result2;
    char operator;

    //Prompt user to enter operator
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    //Prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            }
            else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    //Prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%f %f", &num3, &num4);

    switch(operator) {
        case '+':
            result2 = num3 + num4;
            printf("Result: %.2f\n", result2);
            break;
        case '-':
            result2 = num3 - num4;
            printf("Result: %.2f\n", result2);
            break;
        case '*':
            result2 = num3 * num4;
            printf("Result: %.2f\n", result2);
            break;
        case '/':
            if(num4 == 0) {
                printf("Error: Division by zero\n");
            }
            else {
                result2 = num3 / num4;
                printf("Result: %.2f\n", result2);
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    return 0;
}