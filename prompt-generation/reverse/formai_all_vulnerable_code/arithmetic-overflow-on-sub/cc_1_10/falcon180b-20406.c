//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char operation;

    // Prompt user to enter two integers and an operator
    printf("Enter two integers and an operator (+, -, *, /, &, |, ^, <<, >>): ");
    scanf("%d %c %d", &num1, &operation, &num2);

    // Perform bitwise operation based on user input
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
            result = num1 / num2;
            break;
        case '&':
            result = num1 & num2;
            break;
        case '|':
            result = num1 | num2;
            break;
        case '^':
            result = num1 ^ num2;
            break;
        case '<<':
            result = num1 << num2;
            break;
        case '>>':
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operator. Please use one of the following: +, -, *, /, &, |, ^, <<, >>\n");
            exit(1);
    }

    // Output result
    printf("Result: %d\n", result);

    return 0;
}