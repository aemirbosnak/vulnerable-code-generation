//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimal, char hex[]) {
    int index = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = 48 + remainder; // 48 is ASCII for '0'
        } else {
            hex[index++] = 55 + remainder; // 65 is ASCII for 'A', hence 55 for 'A'
        }
        decimal /= 16;
    }
    hex[index] = '\0';

    // Reverse the hex string since it is generated in reverse order
    for (int j = 0; j < index / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[index - j - 1];
        hex[index - j - 1] = temp;
    }
}

int convertToDecimal(const char hex[]) {
    int decimal = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        decimal *= 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += hex[i] - 'a' + 10;
        } else {
            printf("Invalid hex character: %c\n", hex[i]);
            return -1; // Return an error code
        }
    }
    return decimal;
}

int main() {
    int choice, decimal;
    char hex[20];

    while (1) {
        printf("Hexadecimal Converter\n");
        printf("1. Convert Decimal to Hexadecimal\n");
        printf("2. Convert Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                // Check for negative decimal values
                if (decimal < 0) {
                    printf("Please enter a non-negative decimal number.\n");
                    continue;
                }
                convertToHex(decimal, hex);
                printf("Hexadecimal: %s\n", hex);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                int result = convertToDecimal(hex);
                if (result != -1) {
                    printf("Decimal: %d\n", result);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}