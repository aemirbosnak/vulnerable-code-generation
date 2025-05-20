//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: romantic
/*
 * 💘 Romantic C Math Exercise 💘
 *
 * Write a program that takes two numbers as input and performs a series of mathematical operations on them.
 * The program should ask the user if they want to perform each operation, and if the user responds with "yes",
 * the operation should be performed and the result should be printed.
 *
 * If the user responds with "no", the program should skip that operation and move on to the next one.
 */

#include <stdio.h>

int main() {
    int num1, num2;

    // Get the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user if they want to perform each operation
    printf("Do you want to perform addition? (yes/no): ");
    char add_response[10];
    scanf("%s", add_response);

    // If the user responds with "yes", perform addition
    if (strcmp(add_response, "yes") == 0) {
        int result = num1 + num2;
        printf("The result of addition is: %d\n", result);
    }

    // Ask the user if they want to perform subtraction
    printf("Do you want to perform subtraction? (yes/no): ");
    char sub_response[10];
    scanf("%s", sub_response);

    // If the user responds with "yes", perform subtraction
    if (strcmp(sub_response, "yes") == 0) {
        int result = num1 - num2;
        printf("The result of subtraction is: %d\n", result);
    }

    // Ask the user if they want to perform multiplication
    printf("Do you want to perform multiplication? (yes/no): ");
    char mul_response[10];
    scanf("%s", mul_response);

    // If the user responds with "yes", perform multiplication
    if (strcmp(mul_response, "yes") == 0) {
        int result = num1 * num2;
        printf("The result of multiplication is: %d\n", result);
    }

    // Ask the user if they want to perform division
    printf("Do you want to perform division? (yes/no): ");
    char div_response[10];
    scanf("%s", div_response);

    // If the user responds with "yes", perform division
    if (strcmp(div_response, "yes") == 0) {
        int result = num1 / num2;
        printf("The result of division is: %d\n", result);
    }

    return 0;
}