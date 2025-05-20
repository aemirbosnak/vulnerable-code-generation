//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_HEX_LENGTH 32
#define MAX_BIN_LENGTH 8

typedef struct {
    char hex[MAX_HEX_LENGTH];
    char bin[MAX_BIN_LENGTH];
} hexbin_t;

void init_hexbin(hexbin_t *hexbin) {
    memset(hexbin->hex, 0, MAX_HEX_LENGTH);
    memset(hexbin->bin, 0, MAX_BIN_LENGTH);
}

void hexbin_to_hex(hexbin_t *hexbin) {
    int i, j;
    char hex_table[] = "0123456789ABCDEF";
    for (i = 0, j = 0; i < strlen(hexbin->bin); i++) {
        if (isdigit(hexbin->bin[i])) {
            hexbin->hex[i] = hex_table[hexbin->bin[i] - '0'];
        } else {
            hexbin->hex[i] = hex_table[hexbin->bin[i] - 'A' + 10];
        }
    }
}

void hexbin_to_bin(hexbin_t *hexbin) {
    int i;
    for (i = 0; i < strlen(hexbin->hex); i++) {
        if (isdigit(hexbin->hex[i])) {
            hexbin->bin[i] = hexbin->hex[i] - '0';
        } else {
            hexbin->bin[i] = hexbin->hex[i] - 'A' + 10;
        }
    }
}

int main(int argc, char *argv[]) {
    hexbin_t hexbin;
    init_hexbin(&hexbin);
    char input[MAX_HEX_LENGTH];
    char output[MAX_HEX_LENGTH];
    char *endptr;
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_HEX_LENGTH, stdin);
    if (sscanf(input, "%s", output)!= 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (strlen(output) > MAX_HEX_LENGTH) {
        printf("Input too long\n");
        return 1;
    }
    int i;
    for (i = 0; i < strlen(output); i++) {
        if (!isxdigit(output[i])) {
            printf("Invalid input\n");
            return 1;
        }
    }
    hexbin_to_bin(&hexbin);
    printf("Binary representation: ");
    for (i = 0; i < strlen(hexbin.bin); i++) {
        printf("%d", hexbin.bin[i]);
    }
    printf("\n");
    hexbin_to_hex(&hexbin);
    printf("Hexadecimal representation: ");
    for (i = 0; i < strlen(hexbin.hex); i++) {
        printf("%c", hexbin.hex[i]);
    }
    printf("\n");
    return 0;
}