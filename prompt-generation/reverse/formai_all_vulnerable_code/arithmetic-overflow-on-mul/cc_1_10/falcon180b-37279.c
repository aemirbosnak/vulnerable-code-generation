//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int is_hex(char c) {
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

int is_valid_hex(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!is_hex(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    if (is_valid_hex(input)) {
        int decimal = 0;
        int base = 1;
        int i;
        for (i = strlen(input) - 1; i >= 0; i--) {
            if (input[i] >= '0' && input[i] <= '9') {
                decimal += (input[i] - '0') * base;
            } else if (input[i] >= 'A' && input[i] <= 'F') {
                decimal += (input[i] - 'A' + 10) * base;
            } else if (input[i] >= 'a' && input[i] <= 'f') {
                decimal += (input[i] - 'a' + 10) * base;
            }
            base *= 16;
        }
        printf("The decimal value of %s is %d.\n", input, decimal);
    } else {
        printf("Invalid hexadecimal number.\n");
    }
    return 0;
}