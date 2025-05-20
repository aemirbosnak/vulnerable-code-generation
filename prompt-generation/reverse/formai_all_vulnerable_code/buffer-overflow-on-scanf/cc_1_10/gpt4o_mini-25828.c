//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void decimalToBinary(int num);
void binaryToDecimal(const char *binaryStr);
void displayOptions();
void handleChoice(int choice);
void clearInputBuffer();

// Main function
int main() {
    int choice;

    while (1) {
        displayOptions();
        printf("Enter your choice (1-3, or 0 to exit): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            clearInputBuffer();
            continue;
        }
        
        if (choice == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        
        handleChoice(choice);
    }
    
    return 0;
}

// Function to display options to the user
void displayOptions() {
    printf("\n--- Binary Conversion Options ---\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Custom Binary Operations (AND, OR, NOT)\n");
    printf("0. Exit\n");
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n'); // Discards input until newline
}

// Function to handle user choices
void handleChoice(int choice) {
    switch (choice) {
        case 1: {
            int decimalNum;
            printf("Enter a decimal number: ");
            if (scanf("%d", &decimalNum) != 1 || decimalNum < 0) {
                printf("Invalid input. Please enter a non-negative integer.\n");
                clearInputBuffer();
                return;
            }
            decimalToBinary(decimalNum);
            break;
        }
        case 2: {
            char binaryStr[65]; // Enough for 64-bit binary number + null-terminator
            printf("Enter a binary number: ");
            clearInputBuffer(); // Clear buffer before reading string
            fgets(binaryStr, sizeof(binaryStr), stdin);
            binaryStr[strcspn(binaryStr, "\n")] = 0; // Remove newline
            binaryToDecimal(binaryStr);
            break;
        }
        case 3: {
            char operation;
            printf("Enter binary operations (e.g., 1010 AND 1100): ");
            char binary1[33], binary2[33];
            clearInputBuffer(); // Clear buffer
            scanf("%s %c %s", binary1, &operation, binary2);
            
            if (operation == 'A') {
                printf("Result: ");
                for (int i = 0; binary1[i] != '\0' && binary2[i] != '\0'; i++) {
                    printf("%d", (binary1[i] - '0') & (binary2[i] - '0'));
                }
                printf("\n");
            } else if (operation == 'O') {
                printf("Result: ");
                for (int i = 0; binary1[i] != '\0' && binary2[i] != '\0'; i++) {
                    printf("%d", (binary1[i] - '0') | (binary2[i] - '0'));
                }
                printf("\n");
            } else if (operation == 'N') {
                printf("NOT of %s: ", binary1);
                for (int i = 0; binary1[i] != '\0'; i++) {
                    printf("%d", 1 - (binary1[i] - '0'));
                }
                printf("\n");
            } else {
                printf("Invalid operation. Use A for AND, O for OR or N for NOT.\n");
            }
            break;
        }
        default:
            printf("Invalid choice. Please select a valid option.\n");
    }
}

// Function to convert decimal to binary
void decimalToBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    char binary[65];
    binary[64] = '\0'; // Null-terminate the binary string
    int index = 63;

    while (num > 0) {
        binary[index--] = (num % 2) + '0'; // Convert to char and store in array
        num /= 2;
    }

    printf("Binary: %s\n", &binary[index + 1]); // Skip leading zeros
}

// Function to convert binary string to decimal
void binaryToDecimal(const char *binaryStr) {
    unsigned long long decimal = 0;
    while (*binaryStr) {
        decimal = (decimal << 1) + (*binaryStr++ - '0'); // Left shift results and add next bit
    }
    printf("Decimal: %llu\n", decimal);
}