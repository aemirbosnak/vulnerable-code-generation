//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec2bin(int num, char *bin) {
    int i = 0;
    int j;
    while (num > 0) {
        bin[i++] = (num % 2) + '0';
        num = num / 2;
    }
    for (j = 0; j < (i / 2); j++) {
        char temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }
    bin[i] = '\0';
}

void bin2dec(char *bin, int *num) {
    int i = 0;
    while (*bin) {
        if (*bin == '0')
            *num *= 2;
        else if (*bin == '1')
            *num = (*num * 2) + 1;
        else {
            printf("Error: Invalid binary input\n");
            exit(1);
        }
        bin++;
    }
}

int main(void) {
    char binary[100];
    int decimal;

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimal);

    dec2bin(decimal, binary);

    printf("Binary equivalent: %s\n", binary);

    printf("Enter a binary number to convert to decimal: ");
    scanf("%s", binary);

    bin2dec(binary, &decimal);

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}