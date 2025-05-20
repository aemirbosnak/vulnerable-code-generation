//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform arithmetic operation on two numbers
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
            return -1; // Invalid operation
    }
}

int main() {
    int num1, num2, result, choice;
    char op;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate random numbers for num1 and num2
    num1 = rand_num(1, 100);
    num2 = rand_num(1, 100);

    // Prompt the user to choose an arithmetic operation
    printf("Enter the arithmetic operation (+, -, *, /): ");
    scanf("%c", &op);

    // Perform the chosen operation on num1 and num2
    result = arithmetic_op(num1, num2, op);

    // Display the result of the operation
    if(result!= -1) {
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operation.\n");
    }

    return 0;
}