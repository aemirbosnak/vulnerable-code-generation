//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>

void convertToHex(int decimal, char hex[]) {
    int i = 0;

    if (decimal == 0) {
        hex[i++] = '0';
    } else {
        while (decimal != 0) {
            int remainder = decimal % 16;

            // Check if we need to convert to a letter for hex
            if (remainder < 10) {
                hex[i++] = remainder + '0';
            } else {
                hex[i++] = (remainder - 10) + 'A'; // A = 10, B = 11, ...
            }
            decimal /= 16;
        }
    }

    // To make it a proper hex representation, we need to reverse the array
    hex[i] = '\0'; // Terminate the string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

int main() {
    int decimal;
    char hex[20]; // Enough space for a hex representation
    char choice;

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("===============================================\n");

    do {
        printf("Please enter a decimal number (0 to exit): ");
        scanf("%d", &decimal);

        if (decimal < 0) {
            printf("Oops! That negative number won't work.\n");
            continue;
        }

        if (decimal == 0) {
            printf("You entered zero; the hex is just 0. Goodbye!\n");
            break;
        }

        convertToHex(decimal, hex);
        printf("The hexadecimal equivalent of %d is: %s\n", decimal, hex);
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any leftover newline

    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for using the converter! Hex you later!\n");
    return 0;
}