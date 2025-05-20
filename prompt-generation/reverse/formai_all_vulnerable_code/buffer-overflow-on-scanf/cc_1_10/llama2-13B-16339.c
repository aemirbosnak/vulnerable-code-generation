//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BINARY_LEN 1024
#define MAX_INT 2147483647

void binary_to_dec(char *binary, int *dec) {
    int i, j, sum = 0;
    for (i = 0; i < BINARY_LEN; i++) {
        j = binary[i] - '0';
        sum += j * pow(2, i);
    }
    *dec = sum;
}

void dec_to_binary(int dec, char *binary) {
    int i, j = 0;
    while (dec != 0) {
        binary[j] = dec % 2 == 0 ? '0' : '1';
        dec /= 2;
        j++;
    }
    binary[j] = '\0';
}

int main() {
    int dec, i;
    char binary[BINARY_LEN];

    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    printf("Binary representation of %d: ", dec);
    binary_to_dec(binary, &dec);
    printf("%s\n", binary);

    printf("Enter a binary string (max %d characters): ", BINARY_LEN);
    fgets(binary, BINARY_LEN, stdin);

    dec = 0;
    for (i = 0; i < BINARY_LEN; i++) {
        dec_to_binary(binary[i] - '0', &dec);
    }

    printf("Decimal representation of %s: %d\n", binary, dec);

    return 0;
}