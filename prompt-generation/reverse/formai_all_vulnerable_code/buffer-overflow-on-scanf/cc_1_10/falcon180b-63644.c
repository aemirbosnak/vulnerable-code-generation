//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100

struct color_name {
    char* name;
    int value;
};

struct color_name color_names[MAX_COLOR_NAMES];
int num_color_names = 0;

void add_color_name(char* name, int value) {
    if (num_color_names >= MAX_COLOR_NAMES) {
        printf("Error: Too many color names defined.\n");
        return;
    }

    color_names[num_color_names].name = strdup(name);
    color_names[num_color_names].value = value;
    num_color_names++;
}

int main() {
    add_color_name("red", 0xff0000);
    add_color_name("green", 0x00ff00);
    add_color_name("blue", 0x0000ff);
    add_color_name("yellow", 0xffff00);
    add_color_name("orange", 0xffa500);
    add_color_name("cyan", 0x00ffff);
    add_color_name("magenta", 0xff00ff);

    char input[100];
    while (1) {
        printf("Enter a color name or value (or type 'exit' to quit):\n");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int value = 0;
        if (sscanf(input, "#%02x%02x%02x", &value, &value, &value) == 3) {
            for (int i = 0; i < num_color_names; i++) {
                if (color_names[i].value == value) {
                    printf("%s\n", color_names[i].name);
                    break;
                }
            }
        } else {
            for (int i = 0; i < num_color_names; i++) {
                if (strcmp(input, color_names[i].name) == 0) {
                    printf("%s\n", input);
                    break;
                }
            }
        }
    }

    return 0;
}