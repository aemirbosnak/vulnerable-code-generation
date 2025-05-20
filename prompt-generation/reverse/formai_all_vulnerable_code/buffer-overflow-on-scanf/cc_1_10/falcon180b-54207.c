//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 50
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"reset", "\033[0m"}
};

int main() {
    int numColors = sizeof(colors) / sizeof(Color);
    char input[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a color name to get its code: ");
    scanf("%s", input);

    Color* color = NULL;
    for (int i = 0; i < numColors; i++) {
        if (strcmp(colors[i].name, input) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name\n");
    } else {
        strcpy(code, color->code);
        printf("The code for %s is %s\n", input, code);
    }

    return 0;
}