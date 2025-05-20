//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32

void binary_to_decimal(char binary[], int decimal[]) {
    int i, j, k, len;
    char* temp;

    len = strlen(binary);
    temp = (char*) malloc(len + 1);
    strcpy(temp, binary);
    temp[len] = '\0';

    for (i = 0; i < len; i++) {
        if (temp[i] == '1') {
            decimal[i] = 1;
        } else {
            decimal[i] = 0;
        }
    }

    for (i = 0, j = len - 1; i < len; i++, j--) {
        k = decimal[i] + (2 * decimal[j]);
        decimal[j] = k % 10;
        decimal[i] = k / 10;
    }
}

void decimal_to_binary(int decimal, char binary[]) {
    int i, j, k, len;

    len = 0;
    while (decimal > 0) {
        k = decimal % 2;
        binary[len++] = k + '0';
        decimal /= 2;
    }
    binary[len] = '\0';
    for (i = 0, j = strlen(binary) - 1; i < j; i++, j--) {
        char temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }
}

int main() {
    char binary[MAX_NUM_LENGTH];
    int decimal[MAX_NUM_LENGTH];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    binary_to_decimal(binary, decimal);

    printf("Decimal equivalent: ");
    for (int i = 0; i < strlen(binary); i++) {
        printf("%d", decimal[i]);
    }

    printf("\n");

    decimal_to_binary(strlen(binary), binary);

    printf("Binary equivalent: ");
    for (int i = 0; i < strlen(binary); i++) {
        printf("%c", binary[i]);
    }

    return 0;
}