//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 32
#define BINARY_SIZE 8

int main(int argc, char *argv[]) {
    char num[MAX_NUM_SIZE];
    char binary[BINARY_SIZE + 1];
    int i, j, num_size, binary_size;
    int decimal_value;

    printf("Enter a decimal number: ");
    fgets(num, sizeof(num), stdin);
    num_size = strlen(num);

    // Check for leading zeros
    if (num[0] == '0' && num[1]!= '.' && num[1]!= '\0') {
        printf("Error: Leading zeros are not allowed\n");
        return 1;
    }

    // Check for non-numeric characters
    for (i = 0; i < num_size; i++) {
        if (num[i] < '0' || num[i] > '9') {
            printf("Error: Non-numeric character found\n");
            return 1;
        }
    }

    // Check for negative numbers
    if (num[0] == '-') {
        printf("Error: Negative numbers are not allowed\n");
        return 1;
    }

    // Convert decimal to binary
    i = 0;
    j = num_size - 1;
    while (j >= 0) {
        decimal_value = num[j] - '0';
        binary[i] = decimal_value % 2 + '0';
        i++;
        j--;
        decimal_value /= 2;
    }

    // Pad the binary string with leading zeros if necessary
    binary_size = i;
    for (i = binary_size; i < BINARY_SIZE; i++) {
        binary[i] = '0';
    }
    binary[BINARY_SIZE] = '\0';

    // Print the binary string
    printf("Binary equivalent: %s\n", binary);

    return 0;
}