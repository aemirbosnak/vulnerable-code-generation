//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 100

typedef struct {
    char *name;
    int value;
} ColorName;

ColorName color_names[MAX_COLOR_NAMES] = {{"black", 0}, {"red", 1}, {"green", 2}, {"yellow", 3}, {"blue", 4}, {"magenta", 5}, {"cyan", 6}, {"white", 7}};

int num_color_names = sizeof(color_names) / sizeof(ColorName);

int main() {
    char input_color[100];
    int input_value;
    int output_value;

    printf("Welcome to the Post-Apocalyptic Color Code Converter!\n");
    printf("Enter a color name or value to convert: ");
    scanf("%s", input_color);

    if (isdigit(input_color[0])) {
        input_value = atoi(input_color);
        printf("Input: %d\n", input_value);
    } else {
        for (int i = 0; i < num_color_names; i++) {
            if (strcmp(input_color, color_names[i].name) == 0) {
                input_value = color_names[i].value;
                printf("Input: %s (%d)\n", input_color, input_value);
                break;
            }
        }
    }

    printf("Enter the output format (hex or rgb): ");
    scanf("%s", input_color);

    if (strcmp(input_color, "hex") == 0) {
        sprintf(input_color, "#%06X", input_value);
        printf("Output: %s\n", input_color);
    } else if (strcmp(input_color, "rgb") == 0) {
        output_value = (input_value >> 16) & 0xFF;
        output_value += (input_value >> 8) & 0xFF;
        output_value += input_value & 0xFF;
        sprintf(input_color, "%d,%d,%d", output_value >> 16, output_value >> 8 & 0xFF, output_value & 0xFF);
        printf("Output: %s\n", input_color);
    } else {
        printf("Invalid output format.\n");
    }

    return 0;
}