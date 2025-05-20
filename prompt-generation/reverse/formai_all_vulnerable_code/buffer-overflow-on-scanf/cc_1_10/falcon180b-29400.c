//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *hex;
    int decimal;
} color_code;

color_code color_codes[] = {
    {"#000000", 0},
    {"#000080", 128},
    {"#0000A0", 160},
    {"#0000C8", 200},
    {"#0000FF", 255},
    {"#008000", 0},
    {"#008080", 128},
    {"#0080A0", 160},
    {"#0080C8", 200},
    {"#0080FF", 255},
    {"#800000", 0},
    {"#800080", 128},
    {"#8000A0", 160},
    {"#8000C8", 200},
    {"#8000FF", 255},
    {"#FF0000", 0},
    {"#FF0080", 128},
    {"#FF00A0", 160},
    {"#FF00C8", 200},
    {"#FF00FF", 255},
    {"#FFFF00", 0},
    {"#FFFF80", 128},
    {"#FFFFA0", 160},
    {"#FFFFC8", 200},
    {"#FFFFFF", 255}
};

int main() {
    int num_codes, i;
    char input[MAX_CODE_LENGTH + 1];

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input);

    num_codes = sizeof(color_codes) / sizeof(color_code);

    for (i = 0; i < num_codes; i++) {
        if (strcmp(input, color_codes[i].hex) == 0) {
            printf("RGB: %d, %d, %d\n", (color_codes[i].decimal >> 16) & 0xFF, (color_codes[i].decimal >> 8) & 0xFF, color_codes[i].decimal & 0xFF);
            return 0;
        }
    }

    printf("Invalid color code.\n");
    return 1;
}