//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decimalToBinary(int n);
void binaryToDecimal(const char *binaryStr);
void clearBuffer();

int main() {
    int choice, decimal;
    char binaryStr[65]; // 64 bits for the binary representation + null terminator

    // Display a menu for the user
    while (1) {
        printf("\n=== Binary Converter ===\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        // Get user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            clearBuffer();
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                
                // Read decimal number
                if (scanf("%d", &decimal) != 1 || decimal < 0) {
                    printf("Please enter a valid non-negative integer.\n");
                    clearBuffer();
                    break;
                }
                
                printf("Binary representation of %d is: ", decimal);
                decimalToBinary(decimal);
                break;

            case 2:
                printf("Enter a binary number: ");
                clearBuffer(); // Clear newline from previous input
                fgets(binaryStr, sizeof(binaryStr), stdin);
                
                // Remove newline character if present
                size_t len = strlen(binaryStr);
                if (len > 0 && binaryStr[len-1] == '\n') {
                    binaryStr[len-1] = '\0';
                }

                printf("Decimal representation of binary %s is: ", binaryStr);
                binaryToDecimal(binaryStr);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose a number between 1 and 3.\n");
        }
    }
    return 0;
}

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }

    char binary[65];
    int index = 63; // Starting from the end of the array
    binary[index] = '\0'; // Null terminate the string

    // Convert from decimal to binary
    while (n > 0) {
        binary[--index] = (n % 2) + '0'; // Store the binary digit as a char
        n /= 2; // Divide n by 2
    }

    // Print the binary representation without leading zeros
    printf("%s\n", &binary[index]);
}

// Function to convert a binary string to decimal
void binaryToDecimal(const char *binaryStr) {
    int decimal = 0;
    int base = 1; // Base value for binary (2^0)

    // Calculate length of the binary string
    size_t len = strlen(binaryStr);
    for (int i = len - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimal += base; // Add the decimal equivalent of the binary digit
        } else if (binaryStr[i] != '0') {
            printf("Invalid binary input. Please enter binary digits (0 or 1) only.\n");
            return;
        }
        base *= 2; // Increment the base (2^n)
    }

    printf("%d\n", decimal); // Output the decimal value
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}