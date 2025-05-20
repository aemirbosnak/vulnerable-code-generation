//FormAI DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void convertDecimalToBinary(int decimal_number) {
    int binary_number[20];
    int i = 0;
    while (decimal_number > 0) {
        binary_number[i] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_number[j]);
    }
}

void convertBinaryToDecimal(char binary_string[]) {
    int decimal_number = 0;
    int binary_position = 1;
    int binary_digit;
    for (int i = 7; i >= 0; i--) {
        binary_digit = binary_string[i] - '0';
        decimal_number += binary_digit * binary_position;
        binary_position *= 2;
    }
    printf("%d\n", decimal_number);
}

int main() {
    int choice;
    printf("Choose Binary Conversion\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Your Choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            int decimal_number;
            printf("Enter decimal number: ");
            scanf("%d", &decimal_number);
            printf("The binary equivalent is: ");
            convertDecimalToBinary(decimal_number);
            printf("\n");
            break;
        }
        case 2: {
            char binary_string[8];
            printf("Enter binary number (8 digits): ");
            scanf("%s", binary_string);
            printf("The decimal equivalent is: ");
            convertBinaryToDecimal(binary_string);
            break;
        }
        default:
            printf("Invalid Choice!\n");
            break;
    }
    return 0;
}