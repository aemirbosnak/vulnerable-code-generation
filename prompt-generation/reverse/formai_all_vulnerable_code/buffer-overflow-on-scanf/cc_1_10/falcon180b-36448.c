//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_LEN 32

char *hex_to_str(char *hex_str) {
    char *str = malloc(MAX_HEX_LEN * 3 + 1);
    int len = strlen(hex_str);
    int i = 0;
    for (i = 0; i < len; i++) {
        if (isxdigit(hex_str[i])) {
            if (isdigit(hex_str[i])) {
                sprintf(&str[i * 3], "%d", hex_str[i] - '0');
            } else {
                sprintf(&str[i * 3], "%c", hex_str[i]);
            }
        } else {
            sprintf(&str[i * 3], " ");
        }
    }
    str[len * 3] = '\0';
    return str;
}

char *str_to_hex(char *str) {
    char *hex_str = malloc(MAX_HEX_LEN + 1);
    int len = strlen(str);
    int i = 0;
    for (i = 0; i < len; i++) {
        if (isprint(str[i])) {
            sprintf(&hex_str[i * 3], "%02X", str[i]);
        } else {
            sprintf(&hex_str[i * 3], " ");
        }
    }
    hex_str[len * 3] = '\0';
    return hex_str;
}

int main() {
    char *input_str = malloc(MAX_HEX_LEN + 1);
    char *output_str = malloc(MAX_HEX_LEN + 1);
    int choice;

    do {
        printf("Enter a string to convert:\n");
        scanf("%s", input_str);

        printf("Enter 1 to convert from hex to string or 2 to convert from string to hex:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            strcpy(output_str, hex_to_str(input_str));
        } else if (choice == 2) {
            strcpy(output_str, str_to_hex(input_str));
        } else {
            printf("Invalid choice.\n");
        }

        printf("Input string: %s\n", input_str);
        printf("Output string: %s\n", output_str);

        printf("Do you want to convert another string? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}