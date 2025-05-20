//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and n-1
int rand_int(int n) {
    return rand() % n;
}

// Function to perform bitwise operations on two integers
void bitwise_operations(int num1, int num2, int operation) {
    switch (operation) {
        case 0: // AND operation
            printf("Bitwise AND: %d\n", num1 & num2);
            break;
        case 1: // OR operation
            printf("Bitwise OR: %d\n", num1 | num2);
            break;
        case 2: // XOR operation
            printf("Bitwise XOR: %d\n", num1 ^ num2);
            break;
        case 3: // Left shift operation
            printf("Left shift by %d: %d\n", num2, num1 << num2);
            break;
        case 4: // Right shift operation
            printf("Right shift by %d: %d\n", num2, num1 >> num2);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    int num1, num2, operation;

    // Generate two random integers
    num1 = rand_int(100);
    num2 = rand_int(100);

    // Ask user for the bitwise operation to perform
    printf("Enter the bitwise operation to perform (0 = AND, 1 = OR, 2 = XOR, 3 = Left shift, 4 = Right shift): ");
    scanf("%d", &operation);

    // Perform the bitwise operation and print the result
    bitwise_operations(num1, num2, operation);

    return 0;
}