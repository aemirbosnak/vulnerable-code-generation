//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void convert_binary_to_decimal(char binary[], int length, int *decimal) {
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (binary[i] == '1') {
            j += pow(2, length - i - 1);
        }
    }
    *decimal = j;
}

void convert_decimal_to_binary(int decimal, char binary[]) {
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        binary[i] = '0';
    }
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            strcat(binary, "1");
        } else {
            strcat(binary, "0");
        }
        decimal /= 2;
    }
}

int main() {
    char binary[MAX_LENGTH];
    int decimal, length;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    length = strlen(binary);

    if (length > MAX_LENGTH) {
        printf("Error: Binary number is too long.\n");
        return 1;
    }

    convert_binary_to_decimal(binary, length, &decimal);

    printf("Decimal equivalent: %d\n", decimal);

    convert_decimal_to_binary(decimal, binary);

    printf("Binary equivalent: %s\n", binary);

    return 0;
}