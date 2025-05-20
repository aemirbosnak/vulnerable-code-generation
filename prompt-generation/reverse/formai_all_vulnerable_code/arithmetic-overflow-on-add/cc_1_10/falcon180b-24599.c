//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void binary_to_decimal(char* binary_num, int decimal_num) {
    int i = 0;
    while (binary_num[i]!= '\0') {
        if (binary_num[i] == '1') {
            decimal_num += pow(2, MAX_SIZE - 1 - i);
        }
        i++;
    }
}

void decimal_to_binary(int decimal_num, char* binary_num) {
    char temp_binary_num[MAX_SIZE];
    int i = 0, j = 0;
    while (decimal_num > 0) {
        if (decimal_num % 2 == 1) {
            temp_binary_num[i++] = '1';
        } else {
            temp_binary_num[i++] = '0';
        }
        decimal_num /= 2;
    }
    for (i = 0; i < MAX_SIZE - strlen(temp_binary_num); i++) {
        binary_num[j++] = '0';
    }
    for (i = 0; i < strlen(temp_binary_num); i++) {
        binary_num[j++] = temp_binary_num[i];
    }
    binary_num[j] = '\0';
}

int main() {
    char binary_num[MAX_SIZE];
    int decimal_num;
    printf("Enter a binary number: ");
    scanf("%s", binary_num);
    binary_to_decimal(binary_num, decimal_num);
    printf("Decimal equivalent of %s is %d\n", binary_num, decimal_num);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    decimal_to_binary(decimal_num, binary_num);
    printf("Binary equivalent of %d is %s\n", decimal_num, binary_num);

    return 0;
}