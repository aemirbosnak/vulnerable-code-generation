//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a range
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform basic arithmetic operations
void perform_arithmetic(int num1, int num2, char operator) {
    int result = 0;
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            return;
    }
    printf("Result: %d\n", result);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    // Prompt the user to enter two numbers and an operator
    int num1, num2;
    char operator;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Generate a random number and perform the selected operation on it
    int random_num = rand_int(1, 100);
    printf("Random number generated: %d\n", random_num);
    perform_arithmetic(random_num, num1, operator);
    perform_arithmetic(random_num, num2, operator);

    return 0;
}