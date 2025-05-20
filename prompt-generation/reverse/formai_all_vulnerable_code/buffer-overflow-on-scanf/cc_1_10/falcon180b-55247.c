//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform arithmetic operation
int arithmetic_op(int num1, int num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

int main() {
    int num1, num2, result, operation;
    char choice;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Loop until user chooses to quit
    while(1) {
        // Generate random numbers
        num1 = rand_num(1, 100);
        num2 = rand_num(1, 100);

        // Ask user for arithmetic operation
        printf("Enter arithmetic operation (+, -, *, /): ");
        scanf("%c", &operation);

        // Perform arithmetic operation and display result
        result = arithmetic_op(num1, num2, operation);
        printf("Result: %d\n", result);

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        // If user chooses to quit, break out of loop
        if(choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}