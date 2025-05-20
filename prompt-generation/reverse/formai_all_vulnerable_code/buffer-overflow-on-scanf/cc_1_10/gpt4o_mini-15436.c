//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char* hex) {
    if (decimal == 0) {
        sprintf(hex, "0");
        return;
    }

    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;

        // Converting remainder to hexadecimal character
        if (remainder < 10)
            hex[index++] = remainder + '0';
        else
            hex[index++] = (remainder - 10) + 'A';

        decimal = decimal / 16;
    }

    hex[index] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

void hexadecimalToDecimal(const char* hex, int* decimal) {
    int len = strlen(hex);
    *decimal = 0;

    for (int i = 0; i < len; i++) {
        char ch = hex[i];

        // Convert character to its decimal value
        int value;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        } else {
            fprintf(stderr, "Invalid hexadecimal character: %c\n", ch);
            exit(EXIT_FAILURE);
        }
        
        *decimal = (*decimal * 16) + value;
    }
}

void printMenu() {
    printf("Hexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    while (1) {
        printMenu();

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int decimal;
            char hex[20];

            printf("Enter a decimal number: ");
            scanf("%d", &decimal);

            decimalToHexadecimal(decimal, hex);
            printf("Hexadecimal: %s\n", hex);

        } else if (choice == 2) {
            char hex[20];
            int decimal;

            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);

            hexadecimalToDecimal(hex, &decimal);
            printf("Decimal: %d\n", decimal);

        } else if (choice == 3) {
            printf("Exiting the program.\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid choice. Please select again.\n");
        }

        printf("\n");
    }

    return 0;
}