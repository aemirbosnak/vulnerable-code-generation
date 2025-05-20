//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform addition operation
int add(int a, int b) {
    return a + b;
}

// Function to perform subtraction operation
int subtract(int a, int b) {
    return a - b;
}

// Function to perform multiplication operation
int multiply(int a, int b) {
    return a * b;
}

// Function to perform division operation
int divide(int a, int b) {
    return a / b;
}

// Function to perform power operation
int power(int a, int b) {
    return a ^ b;
}

// Function to perform modulo operation
int modulo(int a, int b) {
    return a % b;
}

int main() {
    char operation;
    char operator[4];
    char number[100];
    int result;

    // Get the operator from the user
    printf("Please enter the operator (+, -, *, /, ^, %): ");
    scanf("%c", &operation);

    // Get the numbers from the user
    printf("Please enter the first number: ");
    scanf("%s", number);
    result = atoi(number);
    strcpy(operator, number);
    printf("Please enter the second number: ");
    scanf("%s", number);
    result *= atoi(number);
    strcat(operator, number);

    // Perform the operation
    switch (operation) {
        case '+':
            printf("The result of %s + %s is %d\n", operator, operator, result);
            break;
        case '-':
            printf("The result of %s - %s is %d\n", operator, operator, result);
            break;
        case '*':
            printf("The result of %s * %s is %d\n", operator, operator, result);
            break;
        case '/':
            if (result == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("The result of %s / %s is %d\n", operator, operator, result);
            }
            break;
        case '^':
            printf("The result of %s ^ %s is %d\n", operator, operator, result);
            break;
        case '%':
            printf("The result of %s %% %s is %d\n", operator, operator, result);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
}