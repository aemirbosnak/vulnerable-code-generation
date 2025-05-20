//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER 1000
#define MAX_STRLEN 100

// Innovative Arithmetic Program

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char str1[MAX_STRLEN], str2[MAX_STRLEN];
    char op;

    printf("Welcome to the Innovative Arithmetic Program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /, %): ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        case '%':
            mod = num1 % num2;
            break;
        default:
            printf("Invalid operation! Please try again.\n");
            return 0;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Print the numbers in a poetic format
    printf("The first number is %d, a gleaming star in the sky\n", num1);
    printf("The second number is %d, a shining light in the night\n", num2);
    printf("The operation is %c, a magical connection between the two\n", op);
    printf("The result is %d, a beautiful creation born from the union\n", sum);

    // Get the user's input again
    printf("Would you like to run the program again? (y/n): ");
    scanf(" %c", &op);

    return 0;
}