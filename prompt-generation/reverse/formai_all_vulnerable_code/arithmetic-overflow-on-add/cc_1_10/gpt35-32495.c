//FormAI DATASET v1.0 Category: Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

// Function to handle the SIGINT signal
void handler(int sig){ 
    printf("\nInterrupted! Exiting calculator...\n"); 
    exit(0);
}

// Function to perform addition
void add(int a, int b){
    int sum = a + b;
    printf("The sum of %d and %d is: %d\n", a, b, sum);
}

// Function to perform subtraction
void subtract(int a, int b){
    int diff = a - b;
    printf("The difference between %d and %d is: %d\n", a, b, diff);
}

// Function to perform multiplication
void multiply(int a, int b){
    int product = a * b;
    printf("The product of %d and %d is: %d\n", a, b, product);
}

// Function to perform division
void divide(int a, int b){
    if (b == 0){
        printf("Cannot divide by zero. Please enter a valid divisor.\n");
    } else {
        float quotient = (float)a / (float)b;
        printf("The quotient of %d divided by %d is: %0.2f\n", a, b, quotient);
    }
}

// Main function
int main(){
    int a, b, choice;
    signal(SIGINT, handler);

    printf("Welcome to the calculator program!\n");
    while(true){
        printf("Please enter two numbers: ");
        scanf("%d %d", &a, &b);

        printf("\nSelect your preferred operation: \n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf(">> ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add(a, b);
                break;
            case 2:
                subtract(a, b);
                break;
            case 3:
                multiply(a, b);
                break;
            case 4:
                divide(a, b);
                break;
            case 5:
                printf("Exiting calculator program...\n");
                exit(0);
            default:
                printf("Invalid operation selected.\n");
                break;
        }
    }

    return 0;
}