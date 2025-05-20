//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_VALUE_LENGTH 7

struct color_name {
    char name[MAX_COLOR_VALUE_LENGTH];
    int value;
};

struct color_name color_names[MAX_COLOR_NAMES];
int num_color_names = 0;

void add_color_name(char* name, int value) {
    if (num_color_names >= MAX_COLOR_NAMES) {
        printf("Error: Too many color names.\n");
        exit(1);
    }
    strncpy(color_names[num_color_names].name, name, MAX_COLOR_VALUE_LENGTH);
    color_names[num_color_names].value = value;
    num_color_names++;
}

int main() {
    add_color_name("red", 0xFF0000);
    add_color_name("green", 0x00FF00);
    add_color_name("blue", 0x0000FF);

    char input[MAX_COLOR_VALUE_LENGTH];
    while (1) {
        printf("Enter a color name or value (or type 'exit' to quit):\n");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        int value = 0;
        if (sscanf(input, "#%06X", &value) == 1) {
            for (int i = 0; i < num_color_names; i++) {
                if (color_names[i].value == value) {
                    printf("%s\n", color_names[i].name);
                    break;
                }
            }
        } else {
            for (int i = 0; i < num_color_names; i++) {
                if (strcmp(input, color_names[i].name) == 0) {
                    printf("%06X\n", color_names[i].value);
                    break;
                }
            }
        }
    }
    return 0;
}