//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 1000 // maximum size of input string

int is_valid_hex(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_binary(char c) {
    if (c == '0' || c == '1') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_SIZE];
    int i, j, size, checksum;
    char* hex_digits = "0123456789ABCDEF";
    char* binary_digits = "01";

    printf("Enter a string to calculate its checksum: ");
    scanf("%s", input);
    size = strlen(input);

    if (size > MAX_SIZE) {
        printf("Error: Input string too long.\n");
        return 1;
    }

    for (i = 0; i < size; i++) {
        if (!is_valid_hex(input[i]) &&!is_valid_binary(input[i])) {
            printf("Error: Invalid character in input string.\n");
            return 1;
        }
    }

    checksum = 0;
    for (i = 0; i < size; i++) {
        if (is_valid_hex(input[i])) {
            checksum += input[i] - '0';
        } else if (is_valid_binary(input[i])) {
            checksum += input[i] - '0';
        } else {
            printf("Error: Invalid character in input string.\n");
            return 1;
        }
    }

    printf("Checksum: %X\n", checksum);

    return 0;
}