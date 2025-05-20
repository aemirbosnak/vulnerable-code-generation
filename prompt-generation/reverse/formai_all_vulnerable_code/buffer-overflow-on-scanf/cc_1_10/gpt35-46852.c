//FormAI DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdint.h>

// Function to convert decimal to binary
void decimalToBinary(uint8_t num) {

    int binaryNum[8];

    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }

    // Print the binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// Function to convert binary to decimal
uint8_t binaryToDecimal(uint8_t binary[]) {

    uint8_t decimal = 0;

    // Iterate over each bit of the binary number
    for (int i = 0; i < 8; i++) {
        if (binary[i] == 1)
            decimal += (1 << (7 - i));
    }

    return decimal;
}

int main() {

    int choice;
    uint8_t decimalNum, binaryNum[8];

    printf("Welcome to the binary converter!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter decimal number (0-255): ");
                scanf("%hhu", &decimalNum);

                printf("Binary representation: ");
                decimalToBinary(decimalNum);
                printf("\n");

                break;
            case 2:
                printf("\nEnter binary number (8 bits): ");
                for (int i = 0; i < 8; i++)
                    scanf("%hhu", &binaryNum[i]);

                printf("Decimal representation: %hhu\n", binaryToDecimal(binaryNum));

                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice != 3);

    return 0;
}