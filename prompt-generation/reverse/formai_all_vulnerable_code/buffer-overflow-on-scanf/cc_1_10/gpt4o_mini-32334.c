//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n, char *binary) {
    int index = 0;

    // If the number is zero, handle it immediately
    if (n == 0) {
        binary[index++] = '0';
        binary[index] = '\0'; // Null-terminate the string
        return;
    }

    // Process each bit
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Capture the remainder in binary
        n = n / 2; // Move to the next bit
    }
    binary[index] = '\0'; // Null-terminate

    // Reverse the string to get correct binary order
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }
}

void displayBinary(int n, const char *binary) {
    printf("Decimal: %d\n", n);
    printf("Binary : ");
    
    // Displaying in a formatted manner
    for (int i = 0; binary[i] != '\0'; i++) {
        putchar(binary[i]);
        if ((strlen(binary) - i - 1) % 4 == 0 && binary[i + 1] != '\0') {
            putchar(' '); // Space every 4 bits for readability
        }
    }
    putchar('\n');
}

int main() {
    int number;
    char binary[65]; // Enough for up to 64 bits

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Enter a decimal number (positive integer): ");

    while (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input! Please enter a non-negative integer: ");
        // Clear invalid input
        while (getchar() != '\n'); 
    }

    decimalToBinary(number, binary);
    displayBinary(number, binary);
    
    printf("Thank you for using the Decimal to Binary Converter! Goodbye!\n");
    return 0;
}