//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 64

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    char hex[10];
} Color;

Color colors[] = {
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Purple", "800080"},
    {"White", "FFFFFF"},
    {"Black", "000000"},
    {"Gray", "808080"},
    {"Orange", "FFA500"},
    {"Pink", "FFC0CB"}
};

int num_colors = sizeof(colors) / sizeof(Color);

void print_color_table() {
    printf("Color Name\t\tHEX Code\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%-20s\t\t%s\n", colors[i].name, colors[i].hex);
    }
}

char* get_color_hex(char* color_name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            return colors[i].hex;
        }
    }
    return NULL;
}

int main() {
    char color_name[MAX_COLOR_NAME_LEN];
    printf("Enter a color name:\n");
    scanf("%s", color_name);

    char* hex_code = get_color_hex(color_name);
    if (hex_code == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("HEX code for %s is %s\n", color_name, hex_code);

    return 0;
}