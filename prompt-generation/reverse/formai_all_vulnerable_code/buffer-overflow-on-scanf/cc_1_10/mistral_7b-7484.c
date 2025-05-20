//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BINARY_SIZE 32
#define BITS_PER_BYTE 8

void binToDec(char binary[BINARY_SIZE]) {
    int decNum = 0, i, power = 0;

    for (i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decNum += pow(2, power);
        power++;
    }

    printf("\nThe decimal equivalent of the binary number %s is %d.\n", binary, decNum);
}

int main() {
    char binary[BINARY_SIZE];
    int choice;

    printf("\n\n***** BINARY TO DECIMAL CONVERTER *****\n");
    printf("Welcome to the exciting world of binary numbers!\n");

    while (1) {
        printf("\n\n1. Convert binary to decimal\n2. Quit\nEnter your choice: ");
        scanf("%d%*c", &choice);

        if (choice == 1) {
            printf("\nEnter the binary number (max 32 bits): ");
            scanf("%s", binary);

            binToDec(binary);
        } else if (choice == 2) {
            printf("\nThanks for using our binary to decimal converter! See you soon.\n");
            break;
        } else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Helper function to calculate power of 2
int pow(int base, int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; i++)
        result *= base;

    return result;
}