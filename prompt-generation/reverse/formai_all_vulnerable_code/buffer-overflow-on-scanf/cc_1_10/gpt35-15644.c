//FormAI DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdbool.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber) {
    int binaryNumber[32];
    int i = 0;
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
}

// Function to convert binary to decimal
int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

// Main function
int main() {
    int option = 0, decimalNumber;
    long long binaryNumber;
    bool isValid = true;

    // Display menu
    printf("------------- Binary Converter -------------\n");
    printf("1. Decimal to Binary Conversion.\n");
    printf("2. Binary to Decimal Conversion.\n");
    printf("3. Exit.\n");

    do {
        printf("\nEnter your option: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number!\n");
            scanf("%*[^\n]");
            isValid = false;
        } else {
            isValid = true;
        }        
        
        if (isValid) {
            switch (option) {
                case 1: // Decimal to Binary
                    printf("\nEnter a decimal number: ");
                    if (scanf("%d", &decimalNumber) != 1) {
                        printf("Invalid input. Please enter a number!\n");
                        scanf("%*[^\n]");
                    } else {
                        printf("\nBinary representation of %d is ", decimalNumber);
                        decimalToBinary(decimalNumber);
                        printf("\n");
                    }                
                    break;
                case 2: // Binary to Decimal
                    printf("\nEnter a binary number: ");
                    if (scanf("%lld", &binaryNumber) != 1) {
                        printf("Invalid input. Please enter a number!\n");
                        scanf("%*[^\n]");
                    } else {
                        if (binaryNumber > 0 && binaryNumber % 10 == 0) {
                            printf("\nDecimal representation of %lld is %d\n",
                                binaryNumber, binaryToDecimal(binaryNumber));
                        } else {
                            printf("\nInvalid binary number. Please enter a valid binary number!\n");
                        }
                    }                
                    break;
                case 3:
                    printf("\nGoodbye!\n");
                    break;
                default:
                    printf("\nInvalid option. Please enter a valid option!\n");
                    break;
            }
        }        
    } while(option != 3);
        
    return 0;
}