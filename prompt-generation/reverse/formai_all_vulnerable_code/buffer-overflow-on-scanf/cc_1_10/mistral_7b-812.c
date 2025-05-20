//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 256

void itob(unsigned char binary[], unsigned int base, unsigned int *decimal) {
    unsigned int i = 0, temp = 0, power = 0;

    for (; binary[i] != '\0'; i++) {
        if (binary[i] == '1')
            temp += pow(base, power);
        power++;
    }

    *decimal = temp;
}

void reverse(char binary[]) {
    int i = 0, j = strlen(binary) - 1;
    char temp;

    for (; i < j; i++, j--) {
        temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }
}

void binary_to_decimal(char binary[]) {
    unsigned int decimal = 0;
    unsigned char binary_arr[MAX_BINARY_LENGTH];

    int i = 0;
    for (; binary[i] != '\0'; i++) {
        binary_arr[i] = binary[i] - '0';
    }

    itob(binary_arr, 2, &decimal);
    printf("Decimal Equivalent: %u\n", decimal);
}

int main() {
    char binary[MAX_BINARY_LENGTH];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    reverse(binary);
    binary_to_decimal(binary);

    return 0;
}