//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants and variables
const int MAGIC_NUMBER = 42;
int randomNumber = 0;
int mathOperand1 = 0;
int mathOperand2 = 0;
int result = 0;

// Function to generate a random number between 1 and 10
int getRandomNumber() {
    srand(time(NULL));
    randomNumber = (rand() % 10) + 1;
    return randomNumber;
}

// Function to perform a math operation (addition, subtraction, multiplication, or division)
int performMathOperation(int operand1, int operand2, char operation) {
    if (operation == '+') {
        result = operand1 + operand2;
    } else if (operation == '-') {
        result = operand1 - operand2;
    } else if (operation == '*') {
        result = operand1 * operand2;
    } else if (operation == '/') {
        result = operand1 / operand2;
    }
    return result;
}

int main() {
    // Prompt the user for input
    printf("Welcome to Math Adventure Land!\n");
    printf("Please enter a math operation (+, -, *, or /): ");
    char operation;
    scanf("%c", &operation);

    // Prompt the user for the first operand
    printf("Please enter the first operand: ");
    int operand1 = getRandomNumber();
    printf("You entered: %d\n", operand1);

    // Prompt the user for the second operand
    printf("Please enter the second operand: ");
    int operand2 = getRandomNumber();
    printf("You entered: %d\n", operand2);

    // Perform the math operation
    result = performMathOperation(operand1, operand2, operation);

    // Print the result
    printf("The result of %d %c %d is %d\n", operand1, operation, operand2, result);

    // Check if the result is equal to MAGIC_NUMBER
    if (result == MAGIC_NUMBER) {
        printf("Congratulations, you have found the magic number!\n");
    } else {
        printf("Bummer, you didn't find the magic number. Better luck next time!\n");
    }

    return 0;
}