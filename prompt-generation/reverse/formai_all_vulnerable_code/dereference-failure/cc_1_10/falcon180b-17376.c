//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 32
#define MAX_COLOR_CODE_LEN 8
#define NUM_COLORS 16

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    char code[MAX_COLOR_CODE_LEN];
} Color;

Color colors[NUM_COLORS] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"bold", "\033[1m"},
    {"italic", "\033[3m"},
    {"reverse", "\033[7m"},
    {"reset", "\033[0m"},
    {"underline", "\033[4m"},
    {"blink", "\033[5m"},
    {"invisible", "\033[8m"},
    {"strikethrough", "\033[9m"}
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <color_name> <text>\n", argv[0]);
        return 1;
    }

    char color_name[MAX_COLOR_NAME_LEN];
    strcpy(color_name, argv[1]);

    Color *color = NULL;
    for (int i = 0; i < NUM_COLORS; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    char text[MAX_COLOR_CODE_LEN + 1];
    strcpy(text, argv[2]);

    printf("%s%s%s\n", color->code, text, "\033[0m");

    return 0;
}