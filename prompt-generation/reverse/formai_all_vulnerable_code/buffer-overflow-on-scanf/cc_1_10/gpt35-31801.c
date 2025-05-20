//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <string.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binaryString) {
    int decimal = 0, base = 1, length = strlen(binaryString);
    for (int i = length - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimalValue) {
    int binary[100], n = 0;

    while(decimalValue != 0) {
        binary[n++] = decimalValue % 2;
        decimalValue /= 2;
    }

    printf("\nBinary equivalent: ");
    for(int i = n-1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int choice, decimal;
    char binaryString[100];

    printf("Welcome to the Binary Converter program.\n");
    printf("Choose an option: \n");
    printf("1. Binary to Decimal Conversion\n");
    printf("2. Decimal to Binary Conversion\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter binary number: ");
            scanf("%s", binaryString);
            decimal = binaryToDecimal(binaryString);
            printf("\nDecimal equivalent: %d", decimal);
            break;
        case 2:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        default:
            printf("Invalid input");
            break;
    }

    return 0;
}