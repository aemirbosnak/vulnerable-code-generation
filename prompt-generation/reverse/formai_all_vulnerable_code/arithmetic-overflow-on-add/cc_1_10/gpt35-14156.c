//FormAI DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include <stdio.h>

// function to add two numbers
int addNumbers(int a, int b) {
    return a + b;   
}

// function to subtract two numbers
int subNumbers(int a, int b) {
    return a - b;   
}

// function to multiply two numbers
int mulNumbers(int a, int b) {
    return a * b;   
}

int main() {
    printf("Enter two numbers:\n");
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            int result = addNumbers(num1, num2);
            printf("The result of addition is %d\n", result);
            break;
        }
        case 2: {
            int result = subNumbers(num1, num2);
            printf("The result of subtraction is %d\n", result);
            break;
        }
        case 3: {
            int result = mulNumbers(num1, num2);
            printf("The result of multiplication is %d\n", result);
            break;
        }
        default: {
            printf("Invalid choice!\n");
            break;
        }
    }
    
    return 0;
}