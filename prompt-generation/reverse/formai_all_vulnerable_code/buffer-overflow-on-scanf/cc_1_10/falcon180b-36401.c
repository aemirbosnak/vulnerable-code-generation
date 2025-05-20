//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[8];
    int value;
} color_t;

color_t colors[MAX_COLORS] = {
    {"BLACK", 0},
    {"RED", 1},
    {"GREEN", 2},
    {"YELLOW", 3},
    {"BLUE", 4},
    {"MAGENTA", 5},
    {"CYAN", 6},
    {"WHITE", 7},
    {"GRAY", 8},
    {"LIGHT_RED", 9},
    {"LIGHT_GREEN", 10},
    {"LIGHT_YELLOW", 11},
    {"LIGHT_BLUE", 12},
    {"LIGHT_MAGENTA", 13},
    {"LIGHT_CYAN", 14},
    {"LIGHT_WHITE", 15}
};

int main() {
    int choice, i;

    printf("Enter your choice:\n");
    printf("1. Convert color name to color code\n");
    printf("2. Convert color code to color name\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter color name: ");
            scanf("%s", colors[0].name);

            for(i=0; i<MAX_COLORS; i++) {
                if(strcmp(colors[i].name, colors[0].name) == 0) {
                    printf("Color code: %d\n", colors[i].value);
                    break;
                }
            }

            break;

        case 2:
            printf("Enter color code: ");
            scanf("%d", &i);

            for(i=0; i<MAX_COLORS; i++) {
                if(colors[i].value == i) {
                    printf("Color name: %s\n", colors[i].name);
                    break;
                }
            }

            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}