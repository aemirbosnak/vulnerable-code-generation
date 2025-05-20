//FormAI DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimal) {
    int binary[32], i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    printf("The Binary Conversion is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

int binaryToDecimal(char binary[]) {
    int decimal = 0, base = 1, length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

int main() {
    printf("Welcome to the Binary Converter Program!\n");
    printf("Choose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int decimal;
            printf("Enter a Decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        }
        case 2: {
            char binary[100];
            printf("Enter a Binary number: ");
            scanf("%s", binary);
            int decimal = binaryToDecimal(binary);
            printf("The Decimal Conversion is: %d\n", decimal);
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}