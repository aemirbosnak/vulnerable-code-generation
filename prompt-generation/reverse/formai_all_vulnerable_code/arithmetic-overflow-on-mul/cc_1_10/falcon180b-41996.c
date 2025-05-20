//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

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

void hex_to_dec(char* hex, int* dec) {
    int i = 0;
    int j = 0;
    int len = strlen(hex);
    while (i < len) {
        if (is_hex(hex[i])) {
            if (hex[i] >= '0' && hex[i] <= '9') {
                *dec += hex[i] - '0';
            } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                *dec += hex[i] - 'A' + 10;
            } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                *dec += hex[i] - 'a' + 10;
            }
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            return;
        }
        i++;
        j++;
        if (j >= MAX_LENGTH) {
            printf("Hexadecimal string too long.\n");
            return;
        }
    }
    *dec = *dec * 16;
    while (j < MAX_LENGTH) {
        printf("0");
        j++;
    }
    printf("\n");
}

int main() {
    char hex[MAX_LENGTH];
    int dec;
    printf("Enter a hexadecimal string: ");
    if (fgets(hex, MAX_LENGTH, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    hex[strcspn(hex, "\n")] = '\0';
    if (strlen(hex) == 0) {
        printf("Empty input.\n");
        return 1;
    }
    hex_to_dec(hex, &dec);
    return 0;
}