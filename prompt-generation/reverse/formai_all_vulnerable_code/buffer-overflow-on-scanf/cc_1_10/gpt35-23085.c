//FormAI DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <math.h>

void decimal_to_binary(int decimal_num) { // function to convert decimal to binary
    int binary_num[32];
    int index = 0;

    while (decimal_num > 0) { // find the binary number
        binary_num[index] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        index++;
    }

    printf("Binary Representation: ");

    for (int i = index - 1; i >= 0; i--) { // print the binary number
        printf("%d", binary_num[i]);
    }

    printf("\n");
}

void binary_to_decimal(char* binary_num) { // function to convert binary to decimal
    int len = strlen(binary_num);
    int decimal_num = 0;
    int power = 0;

    for (int i = len - 1; i >= 0; i--) { // find the decimal number
        if (binary_num[i] == '1') {
            decimal_num += pow(2, power);
        }
        power++;
    }

    printf("Decimal Representation: %d\n", decimal_num);
}

int main() {
    int choice;
    int decimal_num;
    char binary_num[32];

    printf("Welcome to Binary Converter Program\n");
    printf("1. Decimal to Binary Converter\n");
    printf("2. Binary to Decimal Converter\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal_num);
            decimal_to_binary(decimal_num);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", &binary_num);
            binary_to_decimal(binary_num);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}