//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to add two numbers and return the result
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers and return the result
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers and return the result
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers and return the result
int divide(int a, int b) {
    if (b == 0) {
        printf("Cannot divide by zero\n");
        exit(1);
    }
    return a / b;
}

int main() {
    int num1, num2, choice;
    char input[50];

    srand(time(0)); // Seed the random number generator with the current time

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Enter two numbers separated by a space:\n");
    scanf("%s", input);
    num1 = atoi(input);
    printf("Enter an operator (+, -, *, /):\n");
    scanf("%s", input);
    choice = input[0];
    num2 = generateRandomNumber(1, 100); // Generate a random number between 1 and 100

    switch (choice) {
        case '+':
            printf("The result is: %d\n", add(num1, num2));
            break;
        case '-':
            printf("The result is: %d\n", subtract(num1, num2));
            break;
        case '*':
            printf("The result is: %d\n", multiply(num1, num2));
            break;
        case '/':
            printf("The result is: %d\n", divide(num1, num2));
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}