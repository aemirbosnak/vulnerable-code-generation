//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM_LENGTH 32
#define MAX_BIN_LENGTH (MAX_NUM_LENGTH * 8)

void print_binary(unsigned int num, char* binary, int length) {
    int i;
    for (i = length - 1; i >= 0; i--) {
        binary[i] = (num & 1) + '0';
        num >>= 1;
    }
    binary[length] = '\0';
}

int main() {
    char input[MAX_NUM_LENGTH];
    char binary[MAX_BIN_LENGTH];
    int length;

    printf("Enter a decimal number: ");
    fgets(input, MAX_NUM_LENGTH, stdin);
    length = strlen(input);

    // remove newline character
    input[length - 1] = '\0';

    // check if input is a valid decimal number
    if (length == 0 || input[0] == '\0' || input[0] == '-' && length == 1) {
        printf("Invalid input.\n");
        return 1;
    }

    unsigned int num = 0;
    int i;
    for (i = 0; i < length; i++) {
        if (input[i] < '0' || input[i] > '9') {
            printf("Invalid input.\n");
            return 1;
        }
        num = num * 10 + input[i] - '0';
    }

    // convert decimal to binary
    print_binary(num, binary, MAX_BIN_LENGTH);
    printf("Binary: %s\n", binary);

    return 0;
}