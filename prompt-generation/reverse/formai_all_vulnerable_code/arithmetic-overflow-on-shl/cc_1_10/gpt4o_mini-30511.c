//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

// Function to add two numbers using bitwise operations
int add(int a, int b) {
    while (b != 0) {
        // carry now contains common set bits of a and b
        int carry = a & b;

        // Sum of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // Carry is shifted by one so that adding it to a gives the required sum
        b = carry << 1;
    }
    return a;
}

// Function to subtract two numbers using bitwise operations
int subtract(int a, int b) {
    while (b != 0) {
        // borrow contains common set bits of b and unset bits of a
        int borrow = (~a) & b;

        // Subtraction of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // Borrow is shifted by one so that subtracting it from a gives the required difference
        b = borrow << 1;
    }
    return a;
}

// Function to multiply two numbers using bitwise operations
int multiply(int a, int b) {
    int result = 0; // Initialize result

    // Iterate until b becomes 0
    while (b > 0) {
        // If the last bit of b is set, add a to result
        if (b & 1) {
            result = add(result, a);
        }

        // Shift a left by 1 (multiply by 2)
        a <<= 1;

        // Shift b right by 1 (divide by 2)
        b >>= 1;
    }
    return result;
}

// Function to divide two numbers using bitwise operations
int divide(int dividend, int divisor) {
    // Edge case for division by zero
    if (divisor == 0) {
        printf("Division by zero is undefined.\n");
        return 0;
    }

    // Edge case for overflow
    if (dividend == -2147483648 && divisor == -1) {
        printf("Overflow occurred.\n");
        return 2147483647; 
    }

    int quotient = 0;
    int temp = 1; 
    int value = divisor;

    // Shift divisor until it is less than or equal to dividend
    while (value <= dividend) {
        value <<= 1;
        temp <<= 1;
    }

    // Loop to calculate quotient
    while (temp > 1) {
        value >>= 1;
        temp >>= 1;

        if (dividend >= value) {
            dividend = subtract(dividend, value);
            quotient |= temp;
        }
    }
    return quotient;
}

// Helper function to print binary representation of a number
void print_binary(int num) {
    // Use 32 bits to represent the number
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

// Main function to demonstrate bitwise operations with input from user
int main() {
    int choice, a, b;

    while (true) {
        printf("Select an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        printf("Enter two integers:\n");
        scanf("%d %d", &a, &b);

        switch(choice) {
            case 1: {
                int sum = add(a, b);
                printf("Sum (%d + %d) = %d\n", a, b, sum);
                printf("Binary of sum: ");
                print_binary(sum);
                break;
            }
            case 2: {
                int difference = subtract(a, b);
                printf("Difference (%d - %d) = %d\n", a, b, difference);
                printf("Binary of difference: ");
                print_binary(difference);
                break;
            }
            case 3: {
                int product = multiply(a, b);
                printf("Product (%d * %d) = %d\n", a, b, product);
                printf("Binary of product: ");
                print_binary(product);
                break;
            }
            case 4: {
                int quotient = divide(a, b);
                printf("Quotient (%d / %d) = %d\n", a, b, quotient);
                printf("Binary of quotient: ");
                print_binary(quotient);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}