//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM_LENGTH 32
#define BINARY_NUM_LENGTH (MAX_NUM_LENGTH * 8 + 1)

int main(int argc, char *argv[]) {
    char *binary_num = NULL;
    char *decimal_num = NULL;
    int decimal_len = 0;
    int binary_len = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s decimal_number\n", argv[0]);
        exit(1);
    }

    decimal_num = argv[1];
    decimal_len = strlen(decimal_num);

    // Check if input is decimal
    for (i = 0; i < decimal_len; i++) {
        if (!isdigit(decimal_num[i])) {
            printf("Error: Input is not a decimal number.\n");
            exit(1);
        }
    }

    // Convert decimal to binary
    binary_num = malloc(BINARY_NUM_LENGTH * sizeof(char));
    if (binary_num == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    binary_len = 0;
    while (decimal_num[binary_len]!= '\0') {
        int digit = decimal_num[binary_len] - '0';
        int binary_digit = digit % 2;
        binary_num[binary_len] = (binary_digit + '0');
        binary_len++;
    }
    binary_num[binary_len] = '\0';

    // Print binary number
    printf("Binary number: %s\n", binary_num);

    free(binary_num);
    return 0;
}