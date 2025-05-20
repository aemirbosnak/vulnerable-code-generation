//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER 1000000000
#define MIN_NUMBER -1000000000

int main() {
    int i, j, k;
    long long int a, b, c, d, e, f;
    char op;

    printf("Welcome to the Arithmetic Labyrinth!\n");

    // Initialize the variables
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%lld", &a);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%lld", &b);

    // Get the operation from the user (e.g., +, -, *, /)
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '*':
            c = a * b;
            break;
        case '/':
            c = a / b;
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return 1;
    }

    // Check if the result is within the valid range
    if (c < MIN_NUMBER || c > MAX_NUMBER) {
        printf("The result is out of range. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("The result of %lld + %lld is %lld\n", a, b, c);

    // Get the next number from the user
    printf("Enter the next number: ");
    scanf("%lld", &d);

    // Repeat the operation until the user wants to exit
    while (d != 0) {
        // Perform the operation again
        switch (op) {
            case '+':
                e = d + c;
                break;
            case '-':
                e = d - c;
                break;
            case '*':
                e = d * c;
                break;
            case '/':
                e = d / c;
                break;
            default:
                printf("Invalid operation. Please try again.\n");
                return 1;
        }

        // Check if the result is within the valid range
        if (e < MIN_NUMBER || e > MAX_NUMBER) {
            printf("The result is out of range. Please try again.\n");
            return 1;
        }

        // Print the result
        printf("The result of %lld + %lld is %lld\n", d, c, e);

        // Get the next number from the user
        printf("Enter the next number: ");
        scanf("%lld", &f);
    }

    // Print the final result
    printf("The final result is %lld\n", e);

    return 0;
}