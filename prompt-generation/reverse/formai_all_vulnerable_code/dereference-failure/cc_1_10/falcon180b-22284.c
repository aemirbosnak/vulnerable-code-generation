//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CODE_LENGTH 7
#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    int value;
} ColorName;

ColorName colorNames[MAX_COLOR_NAMES];
int numColorNames = 0;

void addColorName(char *name, int value) {
    if (numColorNames >= MAX_COLOR_NAMES) {
        printf("Error: Too many color names.\n");
        exit(1);
    }
    colorNames[numColorNames].name = strdup(name);
    colorNames[numColorNames].value = value;
    numColorNames++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_code>\n", argv[0]);
        return 1;
    }

    char *code = argv[1];
    int codeLength = strlen(code);

    if (codeLength < 1 || codeLength > MAX_CODE_LENGTH) {
        printf("Error: Invalid color code length.\n");
        return 1;
    }

    int value = 0;
    int i;

    for (i = 0; i < codeLength; i++) {
        char c = tolower(code[i]);

        if (c >= 'a' && c <= 'f') {
            value = (value << 4) | (c - 'a' + 10);
        } else if (c >= '0' && c <= '9') {
            value = (value << 4) | (c - '0');
        } else {
            printf("Error: Invalid color code character.\n");
            return 1;
        }
    }

    ColorName *colorName = NULL;
    for (i = 0; i < numColorNames; i++) {
        if (colorNames[i].value == value) {
            colorName = &colorNames[i];
            break;
        }
    }

    if (colorName == NULL) {
        printf("Error: Unknown color code.\n");
        return 1;
    }

    printf("%s\n", colorName->name);

    return 0;
}