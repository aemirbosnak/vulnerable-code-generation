//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODES 100

typedef struct {
    char *name;
    char *hex_code;
} Color;

int main() {
    Color colors[MAX_COLOR_NAMES];
    int num_colors = 0;

    colors[num_colors].name = "red";
    colors[num_colors].hex_code = "#FF0000";
    num_colors++;

    colors[num_colors].name = "blue";
    colors[num_colors].hex_code = "#0000FF";
    num_colors++;

    colors[num_colors].name = "green";
    colors[num_colors].hex_code = "#00FF00";
    num_colors++;

    colors[num_colors].name = "yellow";
    colors[num_colors].hex_code = "#FFFF00";
    num_colors++;

    colors[num_colors].name = "purple";
    colors[num_colors].hex_code = "#FF00FF";
    num_colors++;

    colors[num_colors].name = "orange";
    colors[num_colors].hex_code = "#FFA500";
    num_colors++;

    colors[num_colors].name = "white";
    colors[num_colors].hex_code = "#FFFFFF";
    num_colors++;

    colors[num_colors].name = "black";
    colors[num_colors].hex_code = "#000000";
    num_colors++;

    int choice;
    char input[50];

    printf("Enter the color name or hex code you want to convert:\n");
    scanf("%s", input);

    if (strlen(input) == 7 && input[0] == '#') {
        printf("Enter the color name you want to convert to:\n");
        scanf("%s", input);

        for (int i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("The hex code for %s is #%s\n", colors[i].name, colors[i].hex_code);
            }
        }
    } else if (strlen(input) == strlen(colors[0].name)) {
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("The hex code for %s is #%s\n", colors[i].name, colors[i].hex_code);
            }
        }
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}