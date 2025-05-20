//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n) {
    // An array to store the binary number.
    int binary[32];
    int index = 0;

    // Edge case for zero.
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Convert decimal to binary.
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print binary representation in reverse order.
    printf("Binary: ");
    for (index = index - 1; index >= 0; index--) {
        printf("%d", binary[index]);
    }
    printf("\n");
}

void binaryToDecimal(const char *binaryStr) {
    int decimal = 0;
    int base = 1;
    int length = 0;

    // Calculate the length of the string.
    while (binaryStr[length] != '\0') {
        length++;
    }
    
    // Iterate over the string in reverse.
    for (int i = length - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice;
    int decimalNum;
    char binaryStr[32];

    while (1) {
        printf("------- Binary Converter -------\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNum);
                decimalToBinary(decimalNum);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryStr);

                // Validate input: all characters must be '0' or '1'.
                int isValid = 1;
                for (int i = 0; binaryStr[i] != '\0'; i++) {
                    if (binaryStr[i] != '0' && binaryStr[i] != '1') {
                        isValid = 0;
                        break;
                    }
                }

                if (isValid) {
                    binaryToDecimal(binaryStr);
                } else {
                    printf("Invalid binary number input.\n");
                }
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
        printf("\n");
    }
    
    return 0;
}