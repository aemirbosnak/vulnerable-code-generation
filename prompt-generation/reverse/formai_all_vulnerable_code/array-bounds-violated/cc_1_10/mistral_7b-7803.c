//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_COLOR_SIZE 7

void convertHexToRgb(char hexColor[MAX_COLOR_SIZE]) {
    int r, g, b, i;
    char hex[3][2];

    hex[0][0] = hexColor[0];
    hex[0][1] = hexColor[1];
    hex[1][0] = hexColor[2];
    hex[1][1] = hexColor[3];
    hex[2][0] = hexColor[4];
    hex[2][1] = hexColor[5];
    hex[2][2] = hexColor[6];

    r = strtol(hex[0], NULL, 16);
    g = strtol(hex[1], NULL, 16);
    b = strtol(hex[2], NULL, 16);

    if (sscanf(hexColor + 6, "%2x%2x", &r, &b) == 2) {
        g = strtol(hexColor + 3, NULL, 16);
    }

    printf("RGB equivalent of %s is (%d, %d, %d)\n", hexColor, r, g, b);
}

int main() {
    char hexColor[MAX_COLOR_SIZE];

    printf("Enter a hexadecimal color value: ");
    fgets(hexColor, sizeof(hexColor), stdin);

    // Remove newline character from fgets input
    if (hexColor[strlen(hexColor) - 1] == '\n') {
        hexColor[strlen(hexColor) - 1] = '\0';
    }

    // Remove any whitespace characters from hexColor string
    for (int i = 0; hexColor[i] != '\0'; i++) {
        if (isspace(hexColor[i])) {
            for (int j = i; hexColor[j] != '\0'; j++) {
                hexColor[j] = hexColor[j + 1];
            }
            i--;
        }
    }

    if (strlen(hexColor) != 6) {
        printf("Invalid hexadecimal color value. Please enter a valid hexadecimal color value.\n");
        return 1;
    }

    convertHexToRgb(hexColor);

    return 0;
}