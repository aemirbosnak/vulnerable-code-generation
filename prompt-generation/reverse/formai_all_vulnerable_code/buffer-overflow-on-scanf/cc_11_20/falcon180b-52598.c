//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    int value;
} color_t;

color_t colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"gray", 8},
    {"darkgray", 8},
    {"lightred", 9},
    {"lightgreen", 10},
    {"lightyellow", 11},
    {"lightblue", 12},
    {"lightmagenta", 13},
    {"lightcyan", 14}
};

int main() {
    int choice, i, n;
    char input[100];
    printf("Welcome to the Color Code Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert color code to name\n");
    printf("2. Convert color name to code\n");
    printf("3. List all available colors\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a color code (in hexadecimal format): ");
            scanf("%s", input);
            for(i=0; i<MAX_COLORS; i++) {
                if(strcmp(colors[i].name, input) == 0) {
                    printf("Color code: %s\n", input);
                    printf("Color name: %s\n", colors[i].name);
                    break;
                }
            }
            if(i == MAX_COLORS) {
                printf("Color not found.\n");
            }
            break;
        case 2:
            printf("Enter a color name: ");
            scanf("%s", input);
            for(i=0; i<MAX_COLORS; i++) {
                if(strcmp(colors[i].name, input) == 0) {
                    printf("Color code: %s\n", colors[i].name);
                    break;
                }
            }
            if(i == MAX_COLORS) {
                printf("Color not found.\n");
            }
            break;
        case 3:
            printf("List of available colors:\n");
            for(i=0; i<MAX_COLORS; i++) {
                printf("%s - %d\n", colors[i].name, colors[i].value);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}