//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bitwise operations
void bitwise_operations(int a, int b, int operation) {
    switch(operation) {
        case 0: // AND operation
            printf("Result: %d\n", a & b);
            break;
        case 1: // OR operation
            printf("Result: %d\n", a | b);
            break;
        case 2: // XOR operation
            printf("Result: %d\n", a ^ b);
            break;
        case 3: // NOT operation
            printf("Result: %d\n", ~a);
            break;
        case 4: // Left shift operation
            printf("Result: %d\n", a << b);
            break;
        case 5: // Right shift operation
            printf("Result: %d\n", a >> b);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

// Function to generate random numbers
int generate_random_number() {
    return rand() % 10; // Generates a random number between 0 and 9
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int num1, num2, operation;

    // Get user input for two numbers and operation
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter operation (0-5): ");
    scanf("%d", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}