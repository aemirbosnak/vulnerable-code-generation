//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 10

struct color_code {
    char *name;
    char *code;
};

struct color_code color_codes[] = {
    {"black", "0"},
    {"brown", "1"},
    {"red", "2"},
    {"orange", "3"},
    {"yellow", "4"},
    {"green", "5"},
    {"blue", "6"},
    {"violet", "7"},
    {"gray", "8"},
    {"white", "9"}
};

int main(void) {
    char color_code[MAX_COLOR_CODE_LENGTH];
    int i;
    int value = 0;

    printf("Enter a color code: ");
    scanf("%s", color_code);

    for (i = 0; i < strlen(color_code); i++) {
        int digit = color_code[i] - '0';
        if (digit < 0 || digit > 9) {
            printf("Invalid color code: %s\n", color_code);
            return EXIT_FAILURE;
        }
        value *= 10;
        value += digit;
    }

    for (i = 0; i < sizeof(color_codes) / sizeof(struct color_code); i++) {
        if (strcmp(color_code, color_codes[i].code) == 0) {
            printf("The color code %s represents the color %s.\n", color_code, color_codes[i].name);
            return EXIT_SUCCESS;
        }
    }

    printf("Invalid color code: %s\n", color_code);
    return EXIT_FAILURE;
}