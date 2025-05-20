//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void DecimalToBinary(int decimal) {
    char binary[33]; // Maximum 32 bits + 1 for null terminator
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal & 1) + '0'; // Convert remainder to character and add to binary string
        decimal >>= 1; // Divide by 2 and discard remainder
    }
    binary[i] = '\0'; // Add null terminator
    printf("%s\n", binary); // Print binary string
}

// Function to convert binary to decimal
int BinaryToDecimal(char binary[33]) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        decimal = (decimal << 1) + (binary[i] - '0'); // Shift decimal by 1 and add binary digit
        i++;
    }
    return decimal;
}

int main() {
    int choice;
    char binary[33];

    do {
        printf("Enter your choice:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                DecimalToBinary(choice);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("Decimal equivalent: %d\n", BinaryToDecimal(binary));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}