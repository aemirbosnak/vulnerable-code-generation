//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num) {
    // Base case of recursion
    if (num == 0) {
        return;
    }
    
    // Recursive call to divide the number by 2
    decimalToBinary(num / 2);

    // Print the remainder in the binary representation
    printf("%d", num % 2);
}

void binaryToDecimal(const char *binaryStr) {
    int decimalValue = 0;
    int base = 1; // Base of binary number is 2

    // Iterate over the binary string from the end
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        // Update base for each position, starting from the right
        if (binaryStr[i] == '1') {
            decimalValue += base;
        }
        base *= 2; // Update the base by doubling
    }
    
    printf("%s in decimal is: %d\n", binaryStr, decimalValue);
}

int main() {
    int choice = 0;

    do {
        // Mathematical prompt to the user
        printf("\n============== Binary Number Conversion ==============\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimalNumber;
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                
                printf("Binary representation of %d is: ", decimalNumber);
                if (decimalNumber == 0) {
                    printf("0");
                } else {
                    decimalToBinary(decimalNumber); // Call function to convert
                }
                printf("\n");
                break;
            }
            case 2: {
                char binaryStr[64]; // 64 bits to accommodate large binary values
                printf("Enter a binary number (only 0s and 1s allowed): ");
                scanf("%s", binaryStr);
                
                // Ensure only valid binary inputs
                for (int i = 0; binaryStr[i] != '\0'; i++) {
                    if (binaryStr[i] != '0' && binaryStr[i] != '1') {
                        printf("Invalid binary number!\n"); // Error message
                        goto case_3;
                    }
                }

                binaryToDecimal(binaryStr); // Call function to convert
                break;
            }
            case 3:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        case_3:;

    } while (choice != 3); // Continue until the user decides to exit

    return 0; // Return successful termination of the program
}