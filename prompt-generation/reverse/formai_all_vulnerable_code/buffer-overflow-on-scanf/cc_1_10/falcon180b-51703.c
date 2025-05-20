//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7 // maximum length of a color code
#define NUM_COLORS 16 // number of colors supported by the program

typedef struct {
    char name[10];
    char hex[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[NUM_COLORS] = {
    {"Black", "#000000"},
    {"White", "#FFFFFF"},
    {"Red", "#FF0000"},
    {"Lime", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Yellow", "#FFFF00"},
    {"Cyan", "#00FFFF"},
    {"Magenta", "#FF00FF"},
    {"Silver", "#C0C0C0"},
    {"Gray", "#808080"},
    {"Maroon", "#800000"},
    {"Olive", "#808000"},
    {"Green", "#008000"},
    {"Navy", "#000080"},
    {"Purple", "#800080"},
    {"Teal", "#008080"}
};

int main() {
    char color_code[MAX_COLOR_CODE_LENGTH + 1];
    int i, j;

    printf("Enter a color code (in hexadecimal format): ");
    scanf("%s", color_code);

    // check if the color code is valid
    if (strlen(color_code)!= 6 && strlen(color_code)!= 3) {
        printf("Invalid color code.\n");
        return 1;
    }

    for (i = 0; i < NUM_COLORS; i++) {
        if (strcmp(color_code, colors[i].hex) == 0) {
            printf("The color is %s.\n", colors[i].name);
            return 0;
        }
    }

    printf("Invalid color code.\n");
    return 1;
}