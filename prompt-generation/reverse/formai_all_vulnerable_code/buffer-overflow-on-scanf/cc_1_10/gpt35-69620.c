//FormAI DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32], index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    // Print the binary number in reverse order
    printf("Binary: ");
    for (int i = index-1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert binary to decimal
void binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary > 0) {
        int digit = binary % 10;
        binary /= 10;
        decimal += digit * base;
        base *= 2;
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice, num;
    printf("Welcome to the Binary Converter!\n");

    while (1) {
        printf("\nPlease choose an option:\n1. Convert decimal to binary\n2. Convert binary to decimal\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter a decimal number: ");
                scanf("%d", &num);
                decimalToBinary(num);
                break;
            case 2:
                printf("Please enter a binary number: ");
                scanf("%d", &num);
                binaryToDecimal(num);
                break;
            case 3:
                printf("Thank you for using the Binary Converter!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}