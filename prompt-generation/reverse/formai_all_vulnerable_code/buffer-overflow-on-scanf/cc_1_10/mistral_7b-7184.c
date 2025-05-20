//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BINARY_LENGTH 32

void itob(unsigned char b[], int dec) {
    int i, j, k;
    unsigned char temp[BINARY_LENGTH];

    for (i = 0; dec > 0; i++) {
        temp[i] = dec % 2 + '0';
        dec /= 2;
    }

    for (j = i, k = 0; j > 0; j--, k++)
        b[k] = temp[j];
}

bool validate_binary(unsigned char bin[]) {
    int i;
    for (i = 0; bin[i] != '\0'; i++) {
        if (bin[i] != '0' && bin[i] != '1')
            return false;
    }
    return true;
}

int main() {
    unsigned char bin[BINARY_LENGTH];

    printf("Enter binary number: ");
    scanf("%s", bin);

    if (strlen(bin) > BINARY_LENGTH) {
        printf("Binary number too long!\n");
        return 1;
    }

    if (!validate_binary(bin)) {
        printf("Invalid binary number!\n");
        return 1;
    }

    int decimal;
    itob(bin, &decimal);

    printf("Decimal equivalent of binary number %s is %d.\n", bin, decimal);

    return 0;
}