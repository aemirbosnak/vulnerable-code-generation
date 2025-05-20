//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LENGTH 7
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"Black", "\033[30m"},
    {"Red", "\033[31m"},
    {"Green", "\033[32m"},
    {"Yellow", "\033[33m"},
    {"Blue", "\033[34m"},
    {"Magenta", "\033[35m"},
    {"Cyan", "\033[36m"},
    {"White", "\033[37m"},
    {"Reset", "\033[0m"}
};

int main() {
    int numColors = sizeof(colors) / sizeof(Color);
    char input[MAX_COLOR_NAME_LENGTH + 1];
    char output[MAX_COLOR_CODE_LENGTH + 1];
    char colorCode[MAX_COLOR_CODE_LENGTH + 1];
    int i;

    printf("Enter a color name: ");
    scanf("%s", input);

    for (i = 0; i < numColors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            strcpy(colorCode, colors[i].code);
            break;
        }
    }

    if (i == numColors) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Enter the text to color: ");
    scanf("%s", output);

    printf("%s%s%s\n", colorCode, output, colors[0].code);

    return 0;
}