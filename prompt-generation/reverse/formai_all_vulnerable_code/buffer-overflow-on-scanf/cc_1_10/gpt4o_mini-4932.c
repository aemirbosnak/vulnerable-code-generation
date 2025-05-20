//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(unsigned int n) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to demonstrate bitwise operations
void bitwiseAdventure(unsigned int a, unsigned int b) {
    printf("Welcome to Bitland!\n");

    // Display the original numbers
    printf("You have two numbers:\n");
    printf("a = %u, b = %u\n", a, b);
    printf("In binary, this looks like:\n");
    printf("a = ");
    printBinary(a);
    printf("b = ");
    printBinary(b);
    
    // Bitwise AND
    unsigned int and_result = a & b;
    printf("Adventurers unite with the power of AND!\n");
    printf("a & b = %u\nBinary: ", and_result);
    printBinary(and_result);

    // Bitwise OR
    unsigned int or_result = a | b;
    printf("But sometimes they need to combine forces with OR!\n");
    printf("a | b = %u\nBinary: ", or_result);
    printBinary(or_result);

    // Bitwise XOR
    unsigned int xor_result = a ^ b;
    printf("In times of conflict, they wield the power of XOR!\n");
    printf("a ^ b = %u\nBinary: ", xor_result);
    printBinary(xor_result);

    // Bitwise NOT
    unsigned int not_a = ~a;
    unsigned int not_b = ~b;
    printf("Sometimes an adventurer needs a disguise - behold NOT!\n");
    printf("~a = %u\nBinary: ", not_a);
    printBinary(not_a);
    printf("~b = %u\nBinary: ", not_b);
    printBinary(not_b);

    // Left Shift
    unsigned int left_shift_a = a << 1;
    unsigned int left_shift_b = b << 1;
    printf("Watch the characters grow stronger with a Left Shift!\n");
    printf("a << 1 = %u\nBinary: ", left_shift_a);
    printBinary(left_shift_a);
    printf("b << 1 = %u\nBinary: ", left_shift_b);
    printBinary(left_shift_b);

    // Right Shift
    unsigned int right_shift_a = a >> 1;
    unsigned int right_shift_b = b >> 1;
    printf("And with a Right Shift, they can swiftly retreat!\n");
    printf("a >> 1 = %u\nBinary: ", right_shift_a);
    printBinary(right_shift_a);
    printf("b >> 1 = %u\nBinary: ", right_shift_b);
    printBinary(right_shift_b);

    // Mixing it up
    unsigned int magical_combination = (a & b) | ((~a) ^ (b << 1));
    printf("In a moment of magic, they create a new adventurer!\n");
    printf("Magical combination = %u\nBinary: ", magical_combination);
    printBinary(magical_combination);

    // Conclusion
    printf("And so, our adventurers have explored the wonders of bitwise operations!\n");
    printf("Remember, brave traveler, the power lies within the bits!\n");
}

int main() {
    unsigned int a, b;

    // Take input from the user
    printf("Enter the first number (a): ");
    scanf("%u", &a);
    printf("Enter the second number (b): ");
    scanf("%u", &b);

    // Start the bitwise adventure
    bitwiseAdventure(a, b);

    return 0;
}