//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void displayMenu();
void convertToBinary(int number);
void convertToDecimal(char binary[]);
void clearInputBuffer();

int main() {
    int choice, number;
    char binary[64];

    do {
        displayMenu();
        printf("Enter your choice (1-3, or 0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer to avoid issues with reading strings

        switch (choice) {
            case 1: // Convert Decimal to Binary
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                clearInputBuffer();
                printf("Binary representation of %d is: ", number);
                convertToBinary(number);
                printf("\n");
                break;

            case 2: // Convert Binary to Decimal
                printf("Enter a binary number: ");
                fgets(binary, sizeof(binary), stdin);
                // Remove newline character if present
                binary[strcspn(binary, "\n")] = 0;
                printf("Decimal representation of %s is: ", binary);
                convertToDecimal(binary);
                printf("\n");
                break;

            case 3: // Exit the program
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option (1-3).\n");
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("---- Binary Converter ----\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

void convertToBinary(int number) {
    if (number < 0) {
        printf("Negative numbers are not supported.\n");
        return;
    }
    
    int binary[64] = {0};
    int i = 0;

    while (number > 0) {
        binary[i] = number % 2;
        number /= 2;
        i++;
    }

    // Print the binary array in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

void convertToDecimal(char binary[]) {
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);

    // Iterate over the string in reverse to calculate decimal value
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] < '0' || binary[i] > '1') {
            printf("Invalid binary number.\n");
            return;
        }
        
        decimal += (binary[i] - '0') * base;
        base *= 2;
    }
    printf("%d", decimal);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear until newline is found
}