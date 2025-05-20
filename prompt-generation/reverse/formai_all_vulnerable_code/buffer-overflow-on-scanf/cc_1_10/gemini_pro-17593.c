//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: brave
// Embark on our Bitwise Adventure!

#include <stdio.h>
#include <stdint.h>

// Define our intrepid Bitwise Operators
#define AND &
#define OR |
#define XOR ^
#define NOT ~

// Summon our Heroes of Bit Manipulation
uint32_t num1, num2;
uint16_t result;

void displayResults(char *operation, uint32_t res) {
    printf("\n%s:\n\t", operation);
    for (int i = 31; i >= 0; i--) {
        if (res & (1 << i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {

    // Greet the User and Capture Their Bitwise Aspirations
    printf("Welcome to the Bitwise Labyrinth!\n");
    printf("Enter two 32-bit unsigned integers:\n");
    scanf("%u %u", &num1, &num2);

    // Begin our Bitwise Exploration

    // AND: A Symphony of Unity
    result = num1 AND num2;
    displayResults("AND", result);

    // OR: A Tapestry of Possibility
    result = num1 OR num2;
    displayResults("OR", result);

    // XOR: A Dance of Distinction
    result = num1 XOR num2;
    displayResults("XOR", result);

    // NOT: A Reversal of Fortunes
    result = NOT num1;
    displayResults("NOT(num1)", result);

    // Bit Shifting: A Journey Through Time
    printf("Shifting num1 8 bits to the right:\n");
    result = num1 >> 8;
    displayResults(">>", result);

    printf("Shifting num1 8 bits to the left:\n");
    result = num1 << 8;
    displayResults("<<", result);

    // Masking: A Selective Revelation
    uint16_t mask = 0x00FF;
    result = num1 & mask;
    displayResults("num1 masked with 0x00FF", result);

    // Arithmetic Operations with Bitwise Operations
    printf("num1 + num2 using Bitwise Operators:\n");
    result = num1 + num2;
    uint32_t carry = 0;
    while (carry || result) {
        uint32_t temp = result;
        result >>= 1;
        carry = temp & 1;
        result += carry;
    }
    displayResults("+", result);

    printf("num1 - num2 using Bitwise Operators:\n");
    if (num1 < num2) {
        printf("Cannot subtract a larger number from a smaller number.\n");
    }
    else {
        result = num1;
        while (num2) {
            uint32_t temp = ~num2 + 1;
            result += temp;
            num2 = temp >> 1;
        }
        displayResults("-", result);
    }

    printf("num1 * num2 using Bitwise Operators:\n");
    result = 0;
    while (num2) {
        if (num2 & 1) {
            result += num1;
        }
        num1 <<= 1;
        num2 >>= 1;
    }
    displayResults("*", result);

    // Farewell, Bitwise Adventurers!
    printf("\nMay your journey through the Bitwise Labyrinth be ever enlightening!\n");
    return 0;
}