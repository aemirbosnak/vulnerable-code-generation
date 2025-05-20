//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Function to perform arithmetic operations recursively
void arithmetic(int num1, int num2, char op, int *result) {
    switch(op) {
        case '+':
            *result = num1 + num2;
            break;
        case '-':
            *result = num1 - num2;
            break;
        case '*':
            *result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                exit(0);
            }
            *result = num1 / num2;
            break;
        case '%':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                exit(0);
            }
            *result = num1 % num2;
            break;
    }
}

int main() {
    int num1, num2, result;
    char op;

    // Get input from user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the arithmetic operation (+, -, *, /, %): ");
    scanf(" %c", &op);

    // Perform arithmetic operation recursively
    arithmetic(num1, num2, op, &result);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}