//FormAI DATASET v1.0 Category: Educational ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to add two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two numbers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to divide two numbers
float divide(int num1, int num2) {
    return (float)num1 / num2;
}

// Function to find the factorial of a number
long long factorial(int num) {
    long long fact = 1;
    while(num > 1) {
        fact *= num;
        num--;
    }
    return fact;
}

// Function to find the power of a number
int power(int base, int exponent) {
    if(exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

// Function to find the square root of a number
float squareRoot(int num) {
    float root = num / 2;
    float temp = 0;
    while(root != temp) {
        temp = root;
        root = (num / temp + temp) / 2;
    }
    return root;
}

int main() {
    int num1, num2, operation;
    printf("Welcome to the mind-bending calculator!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    printf("Which operation would you like to perform?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("5. Factorial\n6. Power\n7. Square Root\n");
    printf("Please enter the operation number: ");
    scanf("%d", &operation);
    switch(operation) {
        case 1:
            printf("The result of %d + %d is %d.\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("The result of %d - %d is %d.\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("The result of %d * %d is %d.\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            printf("The result of %d / %d is %.2f.\n", num1, num2, divide(num1, num2));
            break;
        case 5:
            printf("The factorial of %d is %lld.\n", num1, factorial(num1));
            break;
        case 6:
            printf("%d to the power of %d is %d.\n", num1, num2, power(num1, num2));
            break;
        case 7:
            printf("The square root of %d is %.2f.\n", num1, squareRoot(num1));
            break;
        default:
            printf("Invalid operation selected. Please try again.\n");
    }

    return 0;
}