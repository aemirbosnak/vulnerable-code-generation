//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_COLOR_CODES 10

typedef struct {
    char *name;
    char *color_code;
} ColorCode;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char input_color[MAX_LENGTH];
    strcpy(input_color, argv[1]);

    ColorCode color_codes[MAX_COLOR_CODES];
    int num_color_codes = 0;

    color_codes[num_color_codes].name = "Black";
    color_codes[num_color_codes].color_code = "#000000";
    num_color_codes++;

    color_codes[num_color_codes].name = "White";
    color_codes[num_color_codes].color_code = "#FFFFFF";
    num_color_codes++;

    color_codes[num_color_codes].name = "Red";
    color_codes[num_color_codes].color_code = "#FF0000";
    num_color_codes++;

    color_codes[num_color_codes].name = "Green";
    color_codes[num_color_codes].color_code = "#00FF00";
    num_color_codes++;

    color_codes[num_color_codes].name = "Blue";
    color_codes[num_color_codes].color_code = "#0000FF";
    num_color_codes++;

    color_codes[num_color_codes].name = "Yellow";
    color_codes[num_color_codes].color_code = "#FFFF00";
    num_color_codes++;

    color_codes[num_color_codes].name = "Cyan";
    color_codes[num_color_codes].color_code = "#00FFFF";
    num_color_codes++;

    color_codes[num_color_codes].name = "Magenta";
    color_codes[num_color_codes].color_code = "#FF00FF";
    num_color_codes++;

    color_codes[num_color_codes].name = "Gray";
    color_codes[num_color_codes].color_code = "#808080";
    num_color_codes++;

    int i;
    for (i = 0; i < num_color_codes; i++) {
        if (strcmp(input_color, color_codes[i].name) == 0) {
            printf("%s: %s\n", input_color, color_codes[i].color_code);
            return 0;
        }
    }

    printf("Color code not found.\n");
    return 1;
}