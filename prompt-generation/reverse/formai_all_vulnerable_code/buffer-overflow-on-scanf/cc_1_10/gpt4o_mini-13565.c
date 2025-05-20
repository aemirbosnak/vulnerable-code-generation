//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>

void convertToHex(int num) {
    char hex[100];
    int index = 0;
    
    // Handle the zero case
    if (num == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    // Process each digit
    while (num > 0) {
        int rem = num % 16;
        if (rem < 10) {
            hex[index++] = rem + '0'; // Convert to char
        } else {
            hex[index++] = rem - 10 + 'A'; // Convert to char (A-F)
        }
        num /= 16;
    }

    // Print the hex representation in reverse order
    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("------------------------------------------------\n");
    while (1) {
        printf("Please enter a decimal number (enter -1 to quit): ");
        scanf("%d", &decimalNumber);

        // Break the loop if the user wants to quit
        if (decimalNumber == -1) {
            printf("Thank you for using the converter! Goodbye!\n");
            break;
        }

        // Validate the input
        if (decimalNumber < 0) {
            printf("Oops! Please enter a non-negative integer.\n");
            continue;
        }

        // Convert and print the hexadecimal equivalent
        convertToHex(decimalNumber);
    }

    return 0;
}