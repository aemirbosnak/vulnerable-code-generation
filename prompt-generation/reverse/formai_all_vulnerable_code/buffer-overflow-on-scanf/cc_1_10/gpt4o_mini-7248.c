//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decimalToBinary(int n);
void binaryToDecimal(char* binaryStr);
void printMenu();
void clearInputBuffer();

int main() {
    int choice;
    char binaryStr[65];  // To hold up to 64 bits plus null terminator.

    printf("Welcome to the Fun Binary Converter!\n");
    printf("===================================\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer before taking string input.

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                int decimal;
                scanf("%d", &decimal);
                clearInputBuffer();
                printf("Binary representation of %d is: ", decimal);
                decimalToBinary(decimal);
                printf("\n\n");
                break;

            case 2:
                printf("Enter a binary number (up to 64 bits): ");
                fgets(binaryStr, sizeof(binaryStr), stdin);
                // Remove the trailing newline
                binaryStr[strcspn(binaryStr, "\n")] = '\0';
                printf("Decimal representation of %s is: ", binaryStr);
                binaryToDecimal(binaryStr);
                printf("\n\n");
                break;

            case 3:
                printf("Thank you for using the Fun Binary Converter!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
}

void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    char binary[65]; 
    int index = 0;

    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Convert to char
        n = n / 2;
    }

    // Print in reverse order
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
}

void binaryToDecimal(char* binaryStr) {
    int decimal = 0;
    int base = 1; // 2^0

    // Get the length of the binary string
    int length = strlen(binaryStr);
    for (int i = length - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimal += base;
        }
        base *= 2; // Increment the power of 2
    }
    printf("%d", decimal);
}

void printMenu() {
    printf("\nChoose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear stdin
}