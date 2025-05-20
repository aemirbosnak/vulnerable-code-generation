//FormAI DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>

// This function adds two integers and returns the result
int add(int x, int y) {
    int result = x + y;
    return result;
}

// This function subtracts two integers and returns the result
int subtract(int x, int y) {
    int result = x - y;
    return result;
}

// This function multiplies two integers and returns the result
int multiply(int x, int y) {
    int result = x * y;
    return result;
}

// This function divides two integers and returns the result
int divide(int x, int y) {
    int result = x / y;
    return result;
}

int main() {
    int num1, num2;
    char operator;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    int result;
    switch (operator) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}