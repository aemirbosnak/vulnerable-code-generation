//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

// Function prototypes 
void* calculate(void* arg);
void add(double x, double y);
void subtract(double x, double y);
void multiply(double x, double y);
void divide(double x, double y);
void power(double x, double y);
void square_root(double x);
void modulus(double x, double y);

int main() {
    char operation;
    double x, y;
    pthread_t tid;

    do {
        // Ask for the operation and numbers
        printf("\nEnter the operation to perform (+, -, *, /, ^, r, %%) or x to exit: ");
        scanf(" %c", &operation);

        if(operation != 'x') {
            printf("Enter the first number: ");
            scanf("%lf", &x);

            if(operation != 'r') {
                printf("Enter the second number: ");
                scanf("%lf", &y);
            }

            // Spawn a thread for the current calculation
            pthread_create(&tid, NULL, calculate, &((double[]){x, y, operation}));
        }
        
    } while(operation != 'x');

    // Wait for all threads to finish
    pthread_exit(NULL);
}

// Function to handle each calculation
void* calculate(void* arg) {
    double* params = (double*)arg;
    double x = params[0];
    double y = params[1];
    char operation = (char)params[2];

    switch(operation) {
        case '+': add(x, y); break;
        case '-': subtract(x, y); break;
        case '*': multiply(x, y); break;
        case '/': divide(x, y); break;
        case '^': power(x, y); break;
        case 'r': square_root(x); break;
        case '%': modulus(x, y); break;
        default: printf("Invalid operation!\n");
    }

    // Exit thread
    pthread_exit(NULL);
}

// Function definitions
void add(double x, double y) {
    printf("Result: %lf\n", x+y);
}

void subtract(double x, double y) {
    printf("Result: %lf\n", x-y);
}

void multiply(double x, double y) {
    printf("Result: %lf\n", x*y);
}

void divide(double x, double y) {
    if(y != 0) {
        printf("Result: %lf\n", x/y);
    } else {
        printf("Error: division by zero!\n");
    }
}

void power(double x, double y) {
    printf("Result: %lf\n", pow(x, y));
}

void square_root(double x) {
    if(x >= 0) {
        printf("Result: %lf\n", sqrt(x));
    } else {
        printf("Error: square root of a negative number!\n");
    }
}

void modulus(double x, double y) {
    printf("Result: %d\n", (int)x%(int)y);
}