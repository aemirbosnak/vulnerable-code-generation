//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int binary[32];
    int index = 0;

    // Fill the binary array in reverse order
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print the binary number in correct order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert a binary number to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    int base = 1; // 2^0

    int length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Increment the base for each position
    }
    return decimal;
}

// Menu function to display options
void showMenu() {
    printf("🌟 Welcome to the Cheerful Binary Converter! 🌟\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

// Main function
int main() {
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimalNumber;
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("You entered: %d\n", decimalNumber);
                decimalToBinary(decimalNumber);
                break;
            }
            case 2: {
                char binaryString[32];
                printf("Enter a binary number: ");
                scanf("%s", binaryString);
                int decimalValue = binaryToDecimal(binaryString);
                printf("You entered: %s\n", binaryString);
                printf("Decimal: %d\n", decimalValue);
                break;
            }
            case 3:
                printf("Bye-bye! Have a great day! 🎉\n");
                break;
            default:
                printf("Oops! Please choose a valid option! 🌈\n");
        }
        printf("\n");
    } while (choice != 3);
    
    return 0;
}