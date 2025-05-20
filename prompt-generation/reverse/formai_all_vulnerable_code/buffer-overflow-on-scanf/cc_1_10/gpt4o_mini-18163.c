//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_BITS 32

void convert_to_binary(int num, char *binary) {
    int index = MAX_BITS - 1; // Start placing bits from the end
    binary[index--] = '\0';   // Null-terminate the string

    // Fill the binary array with '0's
    for (int i = index; i >= 0; i--) {
        binary[i] = '0';
    }

    // Convert the number to binary
    while (num > 0 && index >= 0) {
        binary[index--] = (num % 2) ? '1' : '0'; // Store '0' or '1'
        num /= 2; // Divide number by 2
    }
}

void print_binary(char *binary) {
    int leading_zero = 1; // Flag for leading zeros
    for (int i = 0; i < MAX_BITS; i++) {
        if (binary[i] == '1') {
            leading_zero = 0; // First '1' found, stop skipping
        }
        if (!leading_zero) {
            printf("%c", binary[i]); // Print non-zero bits
        }
    }
    if (leading_zero) {
        printf("0"); // Case for zero input
    }
    printf("\n");
}

int main() {
    int decimal;
    char binary[MAX_BITS];

    printf("Decimal to Binary Converter\n");
    printf("============================\n");
    printf("Enter a decimal number: ");
    
    if (scanf("%d", &decimal) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Exit with an error code
    }
    
    if (decimal < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit with an error code
    }

    convert_to_binary(decimal, binary);
    
    printf("Binary representation of %d is: ", decimal);
    print_binary(binary);

    return 0; // Successful completion
}