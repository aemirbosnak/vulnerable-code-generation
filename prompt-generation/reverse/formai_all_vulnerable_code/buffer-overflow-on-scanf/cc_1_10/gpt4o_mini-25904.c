//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an integer to binary and store it in a string
void intToBinary(int n, char *binary) {
    for (int i = 0; i < 32; i++) {
        binary[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binary[32] = '\0'; // Null-terminate the string
}

// Function to convert a binary string to an integer
int binaryToInt(const char *binary) {
    int value = 0;
    for (int i = 0; i < 32; i++) {
        if (binary[i] == '1') {
            value += (1 << (31 - i));
        }
    }
    return value;
}

// Function to display binary conversion options
void displayMenu() {
    printf("Binary Converter\n");
    printf("1. Convert Integer to Binary\n");
    printf("2. Convert Binary to Integer\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    int option, number;
    char binary[33]; // 32 bits + null terminator
    char binaryInput[33];

    while (1) {
        displayMenu();
        scanf("%d", &option);
        clearInputBuffer(); // Clear the input to handle buffer issues

        switch (option) {
            case 1:
                printf("Enter an integer to convert to binary: ");
                scanf("%d", &number);
                clearInputBuffer();
                intToBinary(number, binary);
                printf("Binary representation of %d is: %s\n", number, binary);
                break;

            case 2:
                printf("Enter a binary number (maximum 32 bits): ");
                fgets(binaryInput, sizeof(binaryInput), stdin);
                // Remove newline character from input
                binaryInput[strcspn(binaryInput, "\n")] = 0; 
                
                // Validate binary input
                if (strlen(binaryInput) > 32) {
                    printf("Error: Input exceeds 32 bits!\n");
                    break;
                }

                for (int i = 0; i < strlen(binaryInput); i++) {
                    if (binaryInput[i] != '0' && binaryInput[i] != '1') {
                        printf("Error: Invalid binary input!\n");
                        goto end;
                    }
                }

                number = binaryToInt(binaryInput);
                printf("Integer representation of %s is: %d\n", binaryInput, number);
                break;
            
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        end:;
    }

    return 0;
}