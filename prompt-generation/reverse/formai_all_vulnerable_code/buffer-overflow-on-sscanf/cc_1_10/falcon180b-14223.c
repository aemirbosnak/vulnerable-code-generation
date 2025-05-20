//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Gray", 128, 128, 128},
    {"LightGray", 192, 192, 192},
    {"DarkBlue", 0, 0, 128},
    {"DarkGreen", 0, 128, 0},
    {"DarkRed", 128, 0, 0},
    {"DarkYellow", 128, 128, 0},
    {"DarkCyan", 0, 128, 128}
};

int main() {
    int choice, i;
    char input[50];

    printf("Color Code Converter\n");
    printf("Enter your choice:\n");
    printf("1. Convert RGB to color name\n");
    printf("2. Convert color name to RGB\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter RGB values (separated by space): ");
            scanf("%s", input);
            sscanf(input, "%d %d %d", &colors[0].red, &colors[0].green, &colors[0].blue);
            for(i=1; i<MAX_COLORS; i++) {
                if(colors[i].red == colors[0].red && colors[i].green == colors[0].green && colors[i].blue == colors[0].blue) {
                    printf("Color name: %s\n", colors[i].name);
                    break;
                }
            }
            break;
        case 2:
            printf("Enter color name: ");
            scanf("%s", input);
            for(i=0; i<MAX_COLORS; i++) {
                if(strcmp(input, colors[i].name) == 0) {
                    printf("RGB values: %d %d %d\n", colors[i].red, colors[i].green, colors[i].blue);
                    break;
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}