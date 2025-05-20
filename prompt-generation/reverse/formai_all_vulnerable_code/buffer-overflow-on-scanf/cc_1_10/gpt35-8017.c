//FormAI DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void welcome();
void convertToBinary(unsigned int);
void goodbye();

int main() {
    unsigned int num;

    // Print welcome message
    welcome();

    // Get user input
    printf("Enter a number to convert to binary: ");
    scanf("%u", &num);

    // Call conversion function
    convertToBinary(num);

    // Print goodbye message
    goodbye();

    return 0;
}

// Function that prints a welcome message
void welcome() {
    printf("\n###################################################\n");
    printf("#                                                 #\n");
    printf("#         Welcome to the happy Binary Converter    #\n");
    printf("#                                                 #\n");
    printf("###################################################\n\n");
}

// Function that converts a decimal number to binary
void convertToBinary(unsigned int num) {
    int bitCount = 0;
    int bits[32];

    while (num > 0) {
        bits[bitCount++] = num % 2;
        num /= 2;
    }

    printf("\nBinary Equivalent: ");
    for (int i = bitCount - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n\n");
}

// Function that prints a goodbye message
void goodbye() {
    printf("\n###################################################\n");
    printf("#                                                 #\n");
    printf("#               May the bits be with you!          #\n");
    printf("#                                                 #\n");
    printf("###################################################\n\n");
}