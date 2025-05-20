//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void decimalToBinary(int n);
void binaryToDecimal(char binaryString[]);
void displayMenu();
void clearInputBuffer();

int main() {
    int choice, decimalNumber;
    char binaryString[33]; // Max of 32 bits + null terminator

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                clearInputBuffer();
                printf("Binary equivalent: ");
                decimalToBinary(decimalNumber);
                printf("\n");
                break;
                
            case 2:
                printf("Enter a binary number: ");
                fgets(binaryString, sizeof(binaryString), stdin);
                clearInputBuffer();
                // Remove whitespace and newline from the input if any
                binaryString[strcspn(binaryString, "\n")] = 0;
                binaryToDecimal(binaryString);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n > 1)
        decimalToBinary(n / 2);
    printf("%d", n % 2);
}

// Function to convert binary to decimal
void binaryToDecimal(char binaryString[]) {
    int decimalNumber = 0;
    int length = strlen(binaryString);
    
    for (int i = 0; i < length; i++) {
        // Check if character is either 0 or 1
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            printf("Invalid binary input: %s\n", binaryString);
            return;
        }
        decimalNumber = (decimalNumber << 1) + (binaryString[i] - '0');
    }
    
    printf("Decimal equivalent: %d\n", decimalNumber);
}

// Function to display menu options
void displayMenu() {
    printf("\n========================\n");
    printf("   Binary Converter     \n");
    printf("========================\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}