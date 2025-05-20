//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32], index = 0;

    // Convert decimal to binary
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    // Print binary in reverse order
    printf("\nBinary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Function to convert binary to decimal
void binaryToDecimal(char binary[]) {
    int decimal = 0, power = 1, length = strlen(binary);

    // Convert binary to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    // Print decimal
    printf("\nDecimal: %d", decimal);
}

int main() {
    printf("Welcome to the Cyberpunk Binary Converter!");

    while (1) {
        printf("\nEnter 1 to convert decimal to binary");
        printf("\nEnter 2 to convert binary to decimal");
        printf("\nEnter 0 to exit");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter decimal: ");
            int decimal;
            scanf("%d", &decimal);
            decimalToBinary(decimal);
        } else if (choice == 2) {
            printf("\nEnter binary: ");
            char binary[32];
            scanf("%s", binary);
            binaryToDecimal(binary);
        } else if (choice == 0) {
            printf("\nExiting Cyberpunk Binary Converter...");
            exit(0);
        } else {
            printf("\nInvalid choice! Try again.");
        }
    }

    return 0;
}