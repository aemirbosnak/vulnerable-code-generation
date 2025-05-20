//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// This function transforms decimal to hexadecimal!
void decimalToHexadecimal(int decimal) {
    // The array to hold the hexadecimal representation
    char hex[20];
    int index = 0;

    // The magic happens here! Convert decimal to hexadecimal!
    while (decimal != 0) {
        int rem = decimal % 16; // Get the remainder

        // Determine the hexadecimal character
        if (rem < 10) {
            hex[index++] = rem + '0'; // '0'-'9'
        } else {
            hex[index++] = rem - 10 + 'A'; // 'A'-'F'
        }

        decimal /= 16; // Reduce decimal value by a factor of 16
    }
    
    // Print formatting to enchant the view!
    printf("Hexadecimal representation is: ");
    
    // As the hex is currently reversed, we must reverse it back
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    putchar('\n'); // Add a newline for a clean appearance
}

// This function transforms hexadecimal to decimal!
void hexadecimalToDecimal(const char* hex) {
    int decimal = 0;
    int base = 1; // Start with 16^0

    // Begin the hex magic from the last character
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        // Current character
        char ch = hex[i];

        // Compute the decimal value based on the character
        int val;
        if (ch >= '0' && ch <= '9') {
            val = ch - '0'; // '0'-'9'
        } else if (ch >= 'A' && ch <= 'F') {
            val = ch - 'A' + 10; // 'A'-'F'
        } else {
            printf("Invalid hexadecimal digit '%c'. Please use A-F or 0-9.\n", ch);
            return;
        }
        
        // Increase the decimal value
        decimal += val * base; // Add power of 16
        base *= 16; // Move to next power of 16
    }

    // Behold! The decimal representation!
    printf("Decimal representation is: %d\n", decimal);
}

// The main function for our puzzling adventure!
int main() {
    // The puzzle begins with a choice of conversion
    int choice;
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Choose an option:\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Your choice (1-3): ");
    
    // Capture the user's choice
    scanf("%d", &choice);

    // The iterative journey for conversions
    while (choice != 3) {
        if (choice == 1) {
            int decimalNumber;
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            decimalToHexadecimal(decimalNumber);
        } else if (choice == 2) {
            char hexNumber[20];
            printf("Enter a hexadecimal number (only A-F and 0-9): ");
            scanf("%s", hexNumber);
            hexadecimalToDecimal(hexNumber);
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
        
        // Prompt for the next choice
        printf("\nChoose again (1-3): ");
        scanf("%d", &choice);
    }

    // Farewell, my mathematical friend!
    printf("Thank you for using the Hexadecimal Converter. Goodbye!\n");
    return 0;
}