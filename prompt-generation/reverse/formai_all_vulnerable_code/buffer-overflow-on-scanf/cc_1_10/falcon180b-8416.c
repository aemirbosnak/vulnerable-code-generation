//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define BASE 2

void convert_binary_to_decimal(char *binary_num) {
    int decimal_num = 0;
    int i = 0;
    int j = strlen(binary_num) - 1;
    while (j >= 0) {
        if (binary_num[j] == '1') {
            decimal_num += pow(BASE, i);
        }
        i++;
        j--;
    }
    printf("Decimal equivalent: %d\n", decimal_num);
}

void convert_decimal_to_binary(int decimal_num) {
    char binary_num[MAX_LENGTH];
    int i = 0;
    while (decimal_num > 0) {
        binary_num[i] = (decimal_num % BASE) + '0';
        i++;
        decimal_num /= BASE;
    }
    printf("Binary equivalent: %s\n", binary_num);
}

int main() {
    char binary_num[MAX_LENGTH];
    int decimal_num;
    while (1) {
        printf("Enter a binary number (max %d digits): ", MAX_LENGTH - 1);
        scanf("%s", binary_num);
        for (int i = 0; i < strlen(binary_num); i++) {
            if (!isdigit(binary_num[i])) {
                printf("Invalid input. Please enter a binary number.\n");
                continue;
            }
        }
        convert_binary_to_decimal(binary_num);
        printf("Enter a decimal number: ");
        scanf("%d", &decimal_num);
        convert_decimal_to_binary(decimal_num);
    }
    return 0;
}