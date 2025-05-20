//FormAI DATASET v1.0 Category: Calculator ; Style: recursive
#include <stdio.h>

int addition(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return addition(num1 ^ num2, (num1 & num2) << 1);
}

int subtraction(int num1, int num2){
    if (num2 == 0) {
        return num1;
    }
    return subtraction(num1 ^ num2, (~num1 & num2) << 1);
}

int multiplication(int num1, int num2, int result) {
    if (num2 == 0) {
        return result;
    }
    if (num2 & 1) {
        result = addition(result, num1);
    }
    return multiplication(num1 << 1, num2 >> 1, result);
}

int division(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    if (dividend < divisor) {
        return 0;
    }
    return addition(division(subtraction(dividend, divisor), divisor), 1);
}

int main() {
    int choice, num1, num2, result;
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    switch(choice) {
        case 1:
            result = addition(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 2:
            result = subtraction(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 3:
            result = multiplication(num1, num2, 0);
            printf("Result: %d\n", result);
            break;
        case 4:
            result = division(num1, num2);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}