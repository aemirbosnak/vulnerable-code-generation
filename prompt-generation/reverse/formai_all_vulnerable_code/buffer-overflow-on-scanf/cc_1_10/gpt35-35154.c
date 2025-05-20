//FormAI DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void decToBinary(unsigned int);
unsigned int binaryToDec(char*);
int isBinary(char*);

int main() {
    int choice;
    unsigned int dec;
    char binary[33];

    printf("***** Binary Converter *****\n");
    do {
        printf("\n1. Convert Decimal to Binary");
        printf("\n2. Convert Binary to Decimal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter a Decimal Number: ");
                scanf("%u", &dec);
                decToBinary(dec);
                break;
            case 2:
                printf("\nEnter a Binary Number: ");
                scanf("%s", binary);
                if (isBinary(binary)) {
                    printf("Decimal: %u\n", binaryToDec(binary));
                } else {
                    printf("Invalid Binary Number\n");
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

/* Function Definitions */

/**
 * Convert Decimal to Binary
 * @param dec - Decimal number to convert
 */
void decToBinary(unsigned int dec) {
    unsigned int quotient, remainder;
    char binary[33] = "00000000000000000000000000000000";
    int i = 31;

    while(dec != 0) {
        quotient = dec / 2;
        remainder = dec % 2;
        if (remainder == 1) {
            binary[i] = '1';
        }
        dec = quotient;
        i--;
    }
    printf("Binary: %s\n", binary);
}

/**
 * Convert Binary to Decimal
 * @param binary - Binary number to convert
 * @return The decimal equivalent
 */
unsigned int binaryToDec(char* binary) {
    unsigned int dec = 0, power = 1;
    int i;

    for (i = strlen(binary)-1; i >= 0; i--) {
        if (binary[i] == '1') {
            dec += power;
        }
        power *= 2;
    }
    return dec;
}

/**
 * Check if a string is a valid binary number
 * @param binary - The string to check
 * @return 1 if binary, 0 if not
 */
int isBinary(char* binary) {
    int i;

    for (i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return 0;
        }
    }
    return 1;
}