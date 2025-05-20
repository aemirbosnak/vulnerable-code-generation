//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_LENGTH 33

typedef struct {
    char binary[MAX_NUM_LENGTH];
    int decimal;
} Number;

void convertDecimalToBinary(int decimal, char* binary, int* length) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0';
    *length = i;
}

void convertBinaryToDecimal(char* binary, int* decimal) {
    int i = 0;
    while (binary[i]!= '\0') {
        *decimal = (*decimal << 1) | (binary[i] - '0');
        i++;
    }
}

int main() {
    int length;
    char input[MAX_NUM_LENGTH];
    Number number;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    convertDecimalToBinary(atoi(input), number.binary, &length);
    printf("Binary number: ");
    for (int i = 0; i < length; i++) {
        printf("%c", number.binary[i]);
    }
    printf("\n");

    convertBinaryToDecimal(number.binary, &number.decimal);
    printf("Decimal number: %d\n", number.decimal);

    return 0;
}