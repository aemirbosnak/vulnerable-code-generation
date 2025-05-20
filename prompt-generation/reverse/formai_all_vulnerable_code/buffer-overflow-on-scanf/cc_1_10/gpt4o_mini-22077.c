//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char binary[32];
    int index = 0;

    while (n > 0) {
        binary[index] = (n % 2) + '0'; // Storing the remainder as a character
        n = n / 2; // Dividing by 2
        index++;
    }

    // Printing the binary representation in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
}

void displayMenu() {
    printf("Binary Converter Menu:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int binaryToDecimal(const char* binaryStr) {
    int decimalValue = 0;
    int base = 1; // 2^0

    // Start from the end of the string
    for (int i = strlen(binaryStr) - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimalValue += base;
        }
        base *= 2; // Increment base by a factor of 2
    }

    return decimalValue;
}

int main() {
    int option;
    char input[MAX_INPUT_SIZE];

    while (1) {
        displayMenu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input, please enter a number.\n");
            while (getchar() != '\n'); // Clear the buffer
            continue;
        }

        switch (option) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%s", input) != 1) {
                    printf("Invalid input, please enter a number.\n");
                    continue;
                }
                int decimalNum = atoi(input);
                printf("Binary representation of %d: ", decimalNum);
                decimalToBinary(decimalNum);
                printf("\n");
                break;
            case 2:
                printf("Enter a binary number: ");
                if (scanf("%s", input) != 1) {
                    printf("Invalid input, please enter a number.\n");
                    continue;
                }

                // Validate binary input
                for (int i = 0; i < strlen(input); i++) {
                    if (input[i] != '0' && input[i] != '1') {
                        printf("Invalid binary number.\n");
                        break;
                    }
                }

                int decimalResult = binaryToDecimal(input);
                printf("Decimal representation of %s: %d\n", input, decimalResult);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please choose a valid option from the menu.\n");
        }
    }
    return 0;
}