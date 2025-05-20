//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    // Using an array to store binary digits
    int binary[32]; 
    int index = 0;

    while (n > 0) {
        binary[index] = n % 2; // Store remainder
        n = n / 2;              // Update n
        index++;
    }

    // Print binary digits in reverse order
    printf("Binary: ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binaryToDecimal(char *binaryString) {
    int decimal = 0;
    int base = 1; // 2^0

    int len = strlen(binaryString);
    for (int i = len - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            decimal += base; // Add to decimal if binary digit is 1
        }
        base = base * 2; // Move to next binary place
    }
    return decimal;
}

// Main function
int main() {
    int choice, decimalNumber;
    char binaryString[32];

    printf("🎉 Welcome to the Cheerful C Binary Converter! 🎉\n");
    printf("------------------------------------------------\n");

    // Menu loop
    do {
        printf("Please select an action:\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Yay! Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Converting %d to binary...\n", decimalNumber);
                decimalToBinary(decimalNumber);
                break;

            case 2:
                printf("Hooray! Enter a binary number (only 0s and 1s): ");
                scanf("%s", binaryString);
                // Validate binary input
                if (strspn(binaryString, "01") == strlen(binaryString)) {
                    printf("Converting binary %s to decimal...\n", binaryString);
                    int decimalValue = binaryToDecimal(binaryString);
                    printf("Decimal: %d\n", decimalValue);
                } else {
                    printf("😱 Oops! That's not a valid binary number. Please use only 0s and 1s.\n");
                }
                break;

            case 3:
                printf("👋 Thank you for using the Cheerful C Binary Converter! Goodbye! 🌈\n");
                break;

            default:
                printf("❗ Invalid choice! Please select a valid option (1-3).\n");
                break;
        }

    } while (choice != 3);

    return 0;
}