//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to demonstrate bitwise AND operation
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to demonstrate bitwise OR operation
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to demonstrate bitwise XOR operation
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to demonstrate bitwise NOT operation
int bitwise_not(int a) {
    return ~a;
}

// Function to demonstrate left shift operation
int left_shift(int a, int positions) {
    return a << positions;
}

// Function to demonstrate right shift operation
int right_shift(int a, int positions) {
    return a >> positions;
}

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to calculate power of 2
int power_of_two(int n) {
    return 1 << n;  // Equivalent to 2^n
}

int main() {
    int a, b;
    int choice, positions;

    printf("Bitwise Operations Program\n");
    printf("===========================\n");

    while(1) {
        printf("\nEnter two integers (a and b): ");
        scanf("%d %d", &a, &b);

        printf("\nSelect a bitwise operation to perform:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT (a only)\n");
        printf("5. Left Shift (a)\n");
        printf("6. Right Shift (a)\n");
        printf("7. Print Binary Representation of a and b\n");
        printf("8. Power of 2\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Result of %d AND %d = %d\n", a, b, bitwise_and(a, b));
                break;
            case 2:
                printf("Result of %d OR %d = %d\n", a, b, bitwise_or(a, b));
                break;
            case 3:
                printf("Result of %d XOR %d = %d\n", a, b, bitwise_xor(a, b));
                break;
            case 4:
                printf("Result of NOT %d = %d\n", a, bitwise_not(a));
                break;
            case 5:
                printf("Enter positions to left shift: ");
                scanf("%d", &positions);
                printf("Result of %d left shifted by %d = %d\n", a, positions, left_shift(a, positions));
                break;
            case 6:
                printf("Enter positions to right shift: ");
                scanf("%d", &positions);
                printf("Result of %d right shifted by %d = %d\n", a, positions, right_shift(a, positions));
                break;
            case 7:
                printf("Binary representation of %d: ", a);
                print_binary(a);
                printf("Binary representation of %d: ", b);
                print_binary(b);
                break;
            case 8:
                printf("Enter n to calculate 2^n: ");
                scanf("%d", &positions);
                printf("2^%d = %d\n", positions, power_of_two(positions));
                break;
            case 0:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Ask for completion of next operation
        printf("\nPress Enter to continue...");
        getchar(); // Clear newline from buffer
        getchar(); // Wait for user to press enter
    }

    return 0;
}