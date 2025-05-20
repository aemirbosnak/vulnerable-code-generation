//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int multiply(int a, int b);
int divide(int a, int b);
int add(int a, int b);
int subtract(int a, int b);

int main() {
    int num1, num2, choice, result;
    
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);
    
    printf("Select an operation:\n");
    printf("1. Multiply\n2. Divide\n3. Add\n4. Subtract\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            result = multiply(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 2:
            if(num2 == 0) {
                printf("Cannot divide by zero.\n");
                exit(0);
            }
            result = divide(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 3:
            result = add(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 4:
            result = subtract(num1, num2);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            exit(0);
    }
    
    return 0;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}