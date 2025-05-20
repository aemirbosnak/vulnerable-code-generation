//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAMES 16

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES] = {
    {"Black", "\033[30m"},
    {"Red", "\033[31m"},
    {"Green", "\033[32m"},
    {"Yellow", "\033[33m"},
    {"Blue", "\033[34m"},
    {"Purple", "\033[35m"},
    {"Cyan", "\033[36m"},
    {"White", "\033[37m"},
    {"Reset", "\033[0m"},
    {"Bold", "\033[1m"},
    {"Underline", "\033[4m"},
    {"Inverse", "\033[7m"},
    {"Strikethrough", "\033[9m"},
    {"Italic", "\033[3m"},
    {"Blink", "\033[5m"}
};

int main() {
    int numColors = sizeof(colors) / sizeof(Color);
    char input[MAX_COLOR_NAME_LENGTH];
    char output[MAX_COLOR_CODE_LENGTH + MAX_COLOR_NAME_LENGTH + 1];

    printf("Enter a color name or code to convert:\n");
    scanf("%s", input);

    for (int i = 0; i < numColors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            strcpy(output, colors[i].code);
        } else if (strcmp(input, colors[i].code) == 0) {
            strcpy(output, colors[i].name);
        }
    }

    if (output[0] == '\0') {
        printf("Invalid color name or code.\n");
    } else {
        printf("Converted color: %s\n", output);
    }

    return 0;
}