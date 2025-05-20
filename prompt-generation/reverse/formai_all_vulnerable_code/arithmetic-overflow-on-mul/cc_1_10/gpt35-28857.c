//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

// function to add two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// function to subtract two numbers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// function to multiply two numbers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// function to divide two numbers
float divide(int num1, int num2) {
    if (num2 == 0) {
        printf("Cannot divide by zero\n");
        return -1;
    }
    return (float) num1 / num2;
}

int main() {
    int num1, num2;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    int sum = add(num1, num2);
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    
    int difference = subtract(num1, num2);
    printf("Difference of %d and %d is %d\n", num1, num2, difference);
    
    int product = multiply(num1, num2);
    printf("Product of %d and %d is %d\n", num1, num2, product);
    
    float quotient = divide(num1, num2);
    if (quotient != -1) {
        printf("Quotient of %d and %d is %.2f\n", num1, num2, quotient);
    }
    
    return 0;
}