//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LEN 64
#define MAX_COLOR_CODE_LEN 8
#define MAX_COLOR_NAME_NUM 256
#define MAX_COLOR_CODE_NUM 16

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    char code[MAX_COLOR_CODE_LEN];
} Color;

Color colors[MAX_COLOR_NAME_NUM] = {
    {"Black", "\033[0;30m"},
    {"Red", "\033[0;31m"},
    {"Green", "\033[0;32m"},
    {"Yellow", "\033[0;33m"},
    {"Blue", "\033[0;34m"},
    {"Purple", "\033[0;35m"},
    {"Cyan", "\033[0;36m"},
    {"White", "\033[0;37m"},
    {"Gray", "\033[1;30m"},
    {"LightRed", "\033[1;31m"},
    {"LightGreen", "\033[1;32m"},
    {"LightYellow", "\033[1;33m"},
    {"LightBlue", "\033[1;34m"},
    {"LightPurple", "\033[1;35m"},
    {"LightCyan", "\033[1;36m"},
    {"LightWhite", "\033[1;37m"}
};

int main() {
    int num_colors = sizeof(colors) / sizeof(Color);
    char input_color[MAX_COLOR_NAME_LEN];
    char input_text[1024];

    printf("Enter a color name: ");
    scanf("%s", input_color);

    int color_index = -1;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(input_color, colors[i].name) == 0) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Enter the text to be colored: ");
    scanf("%s", input_text);

    printf("\033[0m"); // reset color
    printf("%s", input_text);

    return 0;
}