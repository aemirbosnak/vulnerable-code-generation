//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_CHARS 8

bool is_hex(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else if (c >= 'a' && c <= 'f') {
        return true;
    } else if (c >= 'A' && c <= 'F') {
        return true;
    }
    return false;
}

void print_hex(char* hex, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02X ", hex[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    char input_line[MAX_LINE_LENGTH];
    char hex_output[MAX_LINE_LENGTH];

    printf("Enter a string to convert to hexadecimal: ");
    fgets(input_line, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input
    int input_length = strlen(input_line);
    input_line[input_length - 1] = '\0';

    int hex_length = 0;
    for (int i = 0; i < input_length; i++) {
        char c = input_line[i];
        if (is_hex(c)) {
            if (hex_length >= MAX_NUM_CHARS) {
                printf("Error: Input string contains more than %d hexadecimal characters\n", MAX_NUM_CHARS);
                return 1;
            }
            strncat(hex_output, &c, 1);
            hex_length++;
        } else {
            printf("Error: Input string contains non-hexadecimal characters\n");
            return 1;
        }
    }

    printf("Hexadecimal representation: ");
    print_hex(hex_output, hex_length);

    return 0;
}