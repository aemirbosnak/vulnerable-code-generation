//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decimal_to_binary(int n) {
    int binary_num[32] = { 0 };
    int i = 0;

    while (n > 0) {
        binary_num[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("\nBinary Number: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary_num[j]);
}

void binary_to_decimal(char* binary_num) {
    int decimal_num = 0;
    int len = strlen(binary_num) - 1;
    int power = 0;

    for (int i = len; i >= 0; i--) {
        if (binary_num[i] == '1')
            decimal_num += pow(2, power);
        power++;
    }

    printf("\nDecimal Number: %d", decimal_num);
}

int main() {
    int choice;
    int decimal_num;
    char binary_num[32];

    printf("Welcome to Binary Converter\n");
    printf("===========================\n");

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Decimal to Binary Conversion\n");
        printf("2. Binary to Decimal Conversion\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter a decimal number: ");
            scanf("%d", &decimal_num);
            decimal_to_binary(decimal_num);
            printf("\n");
            break;
        case 2:
            printf("\nEnter a binary number: ");
            scanf("%s", binary_num);
            binary_to_decimal(binary_num);
            printf("\n");
            break;
        case 3:
            printf("\nThank you for using the Binary Converter!\n");
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}