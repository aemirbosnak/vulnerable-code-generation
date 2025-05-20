//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimal, char *binary);
int binaryToDecimal(const char *binary);
void printBinary(const char *binary);
void printDecimal(int decimal);
void displayMenu();
void handleConversion(int choice);
void clearInputBuffer();

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer to avoid issues with scanf
        handleConversion(choice);
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\nBinary Converter Menu:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void handleConversion(int choice) {
    if (choice == 1) {
        int decimal;
        char binary[33]; // 32 bits for int + 1 for null terminator
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        clearInputBuffer();
        decimalToBinary(decimal, binary);
        printDecimal(decimal);
        printBinary(binary);
    } else if (choice == 2) {
        char binary[33]; // Max 32 bits binary string
        printf("Enter a binary number: ");
        fgets(binary, sizeof(binary), stdin);
        binary[strcspn(binary, "\n")] = 0; // Remove newline character
        int decimal = binaryToDecimal(binary);
        if (decimal != -1) {
            printBinary(binary);
            printDecimal(decimal);
        }
    } else if (choice != 3) {
        printf("Invalid choice. Please try again.\n");
    }
}

void decimalToBinary(int decimal, char *binary) {
    binary[32] = '\0'; // Null-terminate the string
    for (int i = 31; i >= 0; i--) {
        binary[i] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    }
}

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    for (size_t i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary number.\n");
            return -1;
        }
        decimal = (decimal << 1) | (binary[i] - '0');
    }
    return decimal;
}

void printBinary(const char *binary) {
    printf("Binary representation: %s\n", binary);
}

void printDecimal(int decimal) {
    printf("Decimal representation: %d\n", decimal);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}