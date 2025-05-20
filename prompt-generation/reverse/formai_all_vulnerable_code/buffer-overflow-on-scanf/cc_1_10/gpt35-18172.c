//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// function to convert decimal to hexadecimal
void decimal_to_hexadecimal(unsigned int decimal_num) {
    char hexadecimal_num[100];
    int remainder, quotient, i = 1, j;
    while (decimal_num != 0) {
        remainder = decimal_num % 16;
        quotient = decimal_num / 16;
        if (remainder < 10)
            hexadecimal_num[i++] = remainder + 48;
        else
            hexadecimal_num[i++] = remainder + 55;
        decimal_num = quotient;
    }
    printf("Hexadecimal number: ");
    for (j = i; j > 0; j--) {
        printf("%c", hexadecimal_num[j]);
    }
}

// function to convert hexadecimal to decimal
void hexadecimal_to_decimal(char hexadecimal_num[]) {
    int decimal_num = 0, i, value, length;
    length = strlen(hexadecimal_num);
    for (i = 0; hexadecimal_num[i] != '\0'; i++) {
        if (hexadecimal_num[i] >= '0' && hexadecimal_num[i] <= '9') {
            value = hexadecimal_num[i] - 48;
        } else if (hexadecimal_num[i] >= 'a' && hexadecimal_num[i] <= 'f') {
            value = hexadecimal_num[i] - 97 + 10;
        } else if (hexadecimal_num[i] >= 'A' && hexadecimal_num[i] <= 'F') {
            value = hexadecimal_num[i] - 65 + 10;
        } else {
            printf("Invalid hexadecimal number.");
            return;
        }
        decimal_num = decimal_num * 16 + value;
    }
    printf("Decimal number: %d", decimal_num);
}

// main function
int main() {
    int choice;
    unsigned int decimal_num;
    char hexadecimal_num[100];
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the decimal number: ");
            scanf("%u", &decimal_num);
            decimal_to_hexadecimal(decimal_num);
            break;
        case 2:
            printf("Enter the hexadecimal number: ");
            scanf("%s", hexadecimal_num);
            hexadecimal_to_decimal(hexadecimal_num);
            break;
        default:
            printf("Invalid choice.");
    }
    return 0;
}