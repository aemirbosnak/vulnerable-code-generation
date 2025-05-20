//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 7

typedef struct {
    char *hex;
    int len;
} ColorCode;

ColorCode *newColorCode(char *hex) {
    ColorCode *code = malloc(sizeof(ColorCode));
    code->hex = strdup(hex);
    code->len = strlen(hex);
    return code;
}

void deleteColorCode(ColorCode *code) {
    free(code->hex);
    free(code);
}

int hexToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

int isValidHex(char *hex) {
    int len = strlen(hex);
    if (len!= MAX_CODE_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        int c = hexToInt(hex[i]);
        if (c == -1) {
            return 0;
        }
    }
    return 1;
}

void printColorCode(ColorCode *code) {
    printf("#%s\n", code->hex);
}

int main() {
    char input[MAX_CODE_LEN + 1];
    printf("Enter a hex color code: ");
    scanf("%s", input);

    ColorCode *code = newColorCode(input);

    if (isValidHex(code->hex)) {
        printColorCode(code);
    } else {
        printf("Invalid color code.\n");
    }

    deleteColorCode(code);
    return 0;
}