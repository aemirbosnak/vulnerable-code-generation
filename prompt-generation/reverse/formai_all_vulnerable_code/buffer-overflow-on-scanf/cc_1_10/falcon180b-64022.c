//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33]; // Binary string can have maximum 32 bits + 1 for null character
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0'; // Add null character at the end
    printf("Binary equivalent: %s\n", binary);
}

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, power = 0;
    while (*binary) {
        if (*binary!= '0' && *binary!= '1') {
            printf("Invalid binary number!\n");
            return -1;
        }
        decimal += (*binary - '0') * pow(2, power++);
        binary++;
    }
    return decimal;
}

int main() {
    char input[100];
    int choice, decimal;

    printf("Welcome to the Binary Converter!\n");
    do {
        printf("Enter your choice:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", input);
                decimal = binaryToDecimal(input);
                if (decimal!= -1)
                    printf("Decimal equivalent: %d\n", decimal);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}