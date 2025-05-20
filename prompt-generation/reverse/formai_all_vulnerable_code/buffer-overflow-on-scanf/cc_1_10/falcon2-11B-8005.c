//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main() {
    char binary[MAX_SIZE];
    int decimal[MAX_SIZE], binary_length;
    int i, j;

    printf("Enter binary number: ");
    scanf("%s", binary);

    binary_length = strlen(binary);
    for (i = 0; i < binary_length; i++) {
        decimal[i] = binary[i] - '0';
    }

    for (i = binary_length - 1; i >= 0; i--) {
        binary_length *= 2;
        decimal[binary_length] = decimal[i] * 2;
        binary_length--;
    }

    printf("Decimal: ");
    for (i = 0; i < binary_length; i++) {
        printf("%d", decimal[i]);
        if (i!= binary_length - 1) {
            printf(" ");
        }
    }
    printf("\n");

    for (i = 0; i < binary_length; i++) {
        binary[i] = '0';
    }

    for (i = binary_length - 1; i >= 0; i--) {
        binary[i] = (decimal[i] % 2) + '0';
        decimal[i] /= 2;
    }

    printf("Binary: ");
    for (i = 0; i < binary_length; i++) {
        printf("%c", binary[i]);
        if (i!= binary_length - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}