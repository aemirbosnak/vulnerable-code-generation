//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: visionary
// Embracing the Digital Divide: A Binary Odyssey

#include <stdio.h>
#include <stdlib.h>

// Unveiling the Secrets of Binary Code
typedef unsigned char Byte;
Byte binary[8] = {0};

// Guiding the Binary Explorer
void printBinary(Byte num) {
    for (int i = 7; i >= 0; i--) {
        binary[i] = (num >> i) & 1;
        printf("%d", binary[i]);
    }
}

// Embarking on a Binary Adventure
int main() {
    int decNum;
    printf("Unveil the Binary Code of Your Decimal Number:\n");
    scanf("%d", &decNum);

    // Transmuting Decimals into Binary Patterns
    printf("Behold, the Binary Tapestry of %d:\n", decNum);
    printBinary(decNum);
    printf("\n");

    // Unveiling the Binary Enigma
    Byte choice;
    printf("Delve Deeper into Binary: (1) Decimal to Binary, (2) Binary to Decimal, (3) Exit\n");
    scanf("%d", &choice);

    while (choice != 3) {
        switch (choice) {
            case 1:  // Decimal to Binary
                printf("Convert a Decimal Number: ");
                scanf("%d", &decNum);
                printBinary(decNum);
                break;
            case 2:  // Binary to Decimal
                printf("Unveil the Decimal Essence of a Binary Number: ");
                decNum = 0;
                for (int i = 7; i >= 0; i--) {
                    scanf("%d", &binary[i]);
                    decNum += binary[i] * (1 << i);
                }
                printf("%d\n", decNum);
                break;
            default:
                printf("Invalid Choice. Enter 1, 2, or 3.\n");
        }
        printf("\nDelve Deeper into Binary: (1) Decimal to Binary, (2) Binary to Decimal, (3) Exit\n");
        scanf("%d", &choice);
    }

    printf("Farewell, Binary Explorer. May Your Voyages Continue!\n");
    return 0;
}