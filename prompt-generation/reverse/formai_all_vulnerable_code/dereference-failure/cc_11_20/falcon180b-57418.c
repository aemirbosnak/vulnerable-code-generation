//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 64
#define BIN_NUM_SIZE 8

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    char *num = argv[1];
    int num_len = strlen(num);

    if (num_len > MAX_NUM_SIZE) {
        printf("Number is too large.\n");
        return 1;
    }

    int decimal = 0;
    int power = 0;
    int i = 0;

    while (num[i]!= '\0') {
        if (num[i] == '-') {
            i++;
        } else if (num[i] == '.') {
            printf("Decimal numbers are not supported.\n");
            return 1;
        } else if (num[i] < '0' || num[i] > '9') {
            printf("Invalid character found.\n");
            return 1;
        }

        decimal = decimal * 10 + (num[i] - '0');
        power++;

        if (power == BIN_NUM_SIZE) {
            printf("Binary number is too large.\n");
            return 1;
        }

        i++;
    }

    char *binary_num = malloc(MAX_NUM_SIZE);

    if (binary_num == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    i = 0;
    while (decimal > 0) {
        int rem = decimal % 2;
        binary_num[i] = rem + '0';
        decimal /= 2;
        i++;
    }

    while (i < BIN_NUM_SIZE) {
        binary_num[i] = '0';
        i++;
    }

    printf("Binary representation of %s is %s\n", argv[1], binary_num);

    free(binary_num);
    return 0;
}