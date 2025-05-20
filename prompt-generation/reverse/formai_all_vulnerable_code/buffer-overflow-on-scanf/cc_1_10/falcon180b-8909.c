//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void hexToDec(char hex[], int size, int *dec) {
    int i, j, k = 0;
    for (i = size - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            (*dec) += (int)hex[i] - 48;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            (*dec) += (int)hex[i] - 55;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            (*dec) += (int)hex[i] - 87;
        } else {
            printf("Invalid hexadecimal character at position %d\n", i);
            exit(1);
        }
        k += 4;
        if (k == size) {
            break;
        }
    }
}

void decToHex(int dec, char hex[]) {
    int i = 0;
    while (dec > 0) {
        if (dec % 16 < 10) {
            hex[i++] = dec % 16 + 48;
        } else {
            hex[i++] = dec % 16 + 55;
        }
        dec /= 16;
    }
    hex[i] = '\0';
    int j = 0;
    while (i > j) {
        char temp = hex[j];
        hex[j] = hex[i];
        hex[i] = temp;
        i--;
        j++;
    }
}

int main() {
    char hex[MAX_SIZE];
    int size, dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    size = strlen(hex);

    if (size > MAX_SIZE) {
        printf("Hexadecimal number too large\n");
        exit(1);
    }

    dec = 0;
    hexToDec(hex, size, &dec);

    printf("Decimal equivalent: %d\n", dec);

    return 0;
}