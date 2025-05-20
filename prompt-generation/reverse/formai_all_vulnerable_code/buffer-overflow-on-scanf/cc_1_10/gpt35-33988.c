//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void convert_decimal_to_binary(int decimal_number) {
    int remainder;
    int binary_number[1000], i=0;

    while(decimal_number > 0) {
        remainder = decimal_number % 2;
        binary_number[i] = remainder;
        decimal_number = decimal_number / 2;
        i++;
    }

    printf("Binary output: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_number[j]);
    }
}

void convert_bin_to_decimal(char binary[]) {
    int decimal = 0;
    int weight = 1;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += weight;
        }
        weight *= 2;
    }

    printf("Decimal output: %d\n", decimal);
}

int main() {
    int choice = 0;
    int decimal_number;
    char binary_number[1000];

    printf("Welcome! Please choose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("Please enter a decimal number: ");
        scanf("%d", &decimal_number);
        convert_decimal_to_binary(decimal_number);
    } else if (choice == 2) {
        printf("Please enter a binary number: ");
        scanf("%s", &binary_number);
        convert_bin_to_decimal(binary_number);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}