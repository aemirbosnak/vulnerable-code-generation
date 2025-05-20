//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Function to convert a decimal number to binary string
void decimalToBinary(int n, char *binaryStr) {
    binaryStr[0] = '0';
    binaryStr[1] = 'b'; // Prefix to denote binary format
    for (int i = 31; i >= 0; i--) {
        binaryStr[32 - i + 1] = (n & (1 << i)) ? '1' : '0';
    }
    binaryStr[33] = '\0'; // Null-terminate the string
}

// Function to convert binary string to decimal
int binaryToDecimal(const char *binaryStr) {
    int decimalValue = 0;
    int binLength = 0;
    
    // Calculate length of binary string
    while (binaryStr[binLength] != '\0') {
        binLength++;
    }

    // Convert binary string to decimal
    for (int i = 2; i < binLength; i++) { // Start from index 2 to skip '0b'
        decimalValue = (decimalValue << 1) | (binaryStr[i] - '0');
    }
    
    return decimalValue;
}

// Function to display menu
void displayMenu() {
    printf("Welcome to the Binary Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

// Function to handle user input for conversion 
void processUserChoice() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int decimalNum;
            char binaryStr[34]; // 32 bits + '0b' + '\0'
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            decimalToBinary(decimalNum, binaryStr);
            printf("Decimal: %d -> Binary: %s\n\n", decimalNum, binaryStr);
        } else if (choice == 2) {
            char binaryInput[34];
            printf("Enter a binary number (e.g., 0b1011): ");
            scanf("%s", binaryInput);
            int decimalOutput = binaryToDecimal(binaryInput);
            printf("Binary: %s -> Decimal: %d\n\n", binaryInput, decimalOutput);
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
        } else {
            printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 3);
}

int main() {
    processUserChoice();
    return 0;
}