//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 7

typedef struct {
    char name[10];
    int value;
} Color;

Color colors[MAX_COLORS] = {{"Black", 0}, {"White", 7}, {"Red", 1}, {"Green", 2}, {"Blue", 4}, {"Yellow", 6}, {"Magenta", 5}};

int main() {
    int choice;
    char input[100];

    printf("Welcome to the Color Code Converter!\n\n");
    printf("Please enter a color name or code to convert: ");
    scanf("%s", input);

    if (strlen(input) == 3 && input[0] == '#') {
        int red = input[1] - '0';
        int green = input[2] - '0';
        int blue = input[3] - '0';

        int colorIndex = -1;
        for (int i = 0; i < MAX_COLORS; i++) {
            if (colors[i].value == (red << 5) | (green << 2) | blue) {
                colorIndex = i;
                break;
            }
        }

        if (colorIndex!= -1) {
            printf("The color code #%s corresponds to the color %s.\n", input, colors[colorIndex].name);
        } else {
            printf("Invalid color code.\n");
        }
    } else {
        for (int i = 0; i < MAX_COLORS; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("The color code for %s is #%02X%02X%02X.\n", colors[i].name, colors[i].value >> 5, (colors[i].value >> 2) & 0x07, colors[i].value & 0x03);
                break;
            }
        }
    }

    return 0;
}