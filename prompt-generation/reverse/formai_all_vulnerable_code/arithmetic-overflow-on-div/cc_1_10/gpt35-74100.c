//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int main() {
    /* Declare variables */
    int num1, num2, num3, result;
    char operator1, operator2;

    /* Prompt user to enter three numbers and two operators */
    printf("Enter 3 numbers and 2 operators separated by spaces: ");
    scanf("%d %c %d %c %d", &num1, &operator1, &num2, &operator2, &num3);

    /* Use switch statements to perform arithmetic operations */
    switch(operator1) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        /* If operator1 is invalid, terminate the program */
        default:
            printf("Error: invalid operator %c\n", operator1);
            return 0;
    }

    switch(operator2) {
        case '+':
            result += num3;
            break;
        case '-':
            result -= num3;
            break;
        case '/':
            result /= num3;
            break;
        case '*':
            result *= num3;
            break;
        /* If operator2 is invalid, terminate the program */
        default:
            printf("Error: invalid operator %c\n", operator2);
            return 0;
    }

    printf("Result: %d\n", result);

    return 0;
}