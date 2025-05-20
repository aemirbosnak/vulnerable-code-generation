//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 64
#define MAX_BIN_LENGTH (MAX_NUM_LENGTH * 8)

void print_error(char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
    exit(1);
}

int is_valid_binary(char *binary_str) {
    for (int i = 0; i < strlen(binary_str); i++) {
        if (binary_str[i]!= '0' && binary_str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

int is_valid_decimal(char *decimal_str) {
    for (int i = 0; i < strlen(decimal_str); i++) {
        if (!isdigit(decimal_str[i])) {
            return 0;
        }
    }
    return 1;
}

int decimal_to_binary(char *decimal_str, char *binary_str) {
    int decimal_num = atoi(decimal_str);
    sprintf(binary_str, "%b", decimal_num);
    return strlen(binary_str);
}

int binary_to_decimal(char *binary_str, char *decimal_str) {
    int decimal_num = strtol(binary_str, NULL, 2);
    sprintf(decimal_str, "%d", decimal_num);
    return strlen(decimal_str);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_error("Invalid number of arguments");
    }

    char decimal_str[MAX_NUM_LENGTH];
    char binary_str[MAX_BIN_LENGTH];

    strcpy(decimal_str, argv[1]);
    int decimal_length = strlen(decimal_str);

    if (!is_valid_decimal(decimal_str)) {
        print_error("Invalid decimal number");
    }

    int binary_length = decimal_to_binary(decimal_str, binary_str);

    if (binary_length > MAX_BIN_LENGTH) {
        print_error("Decimal number too large to convert to binary");
    }

    strcpy(argv[1], binary_str);
    printf("Binary number: %s\n", argv[1]);

    return 0;
}