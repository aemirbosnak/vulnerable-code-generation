//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16
#define MAX_NAMES 16

typedef struct {
    char name[MAX_NAMES];
    int code;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0},
    {"White", 7},
    {"Red", 1},
    {"Green", 2},
    {"Blue", 4},
    {"Yellow", 6},
    {"Magenta", 5},
    {"Cyan", 3},
    {"Gray", 8},
    {"LightRed", 9},
    {"LightGreen", 10},
    {"LightBlue", 12},
    {"LightYellow", 14},
    {"LightMagenta", 13},
    {"LightCyan", 11},
    {"LightGray", 15}
};

int main() {
    int choice, i;
    char input[MAX_NAMES];

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Convert color name to code\n");
    printf("2. Convert color code to name\n");
    printf("3. List all available colors\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the name of the color: ");
            scanf("%s", input);

            for(i = 0; i < MAX_COLORS; i++) {
                if(strcmp(colors[i].name, input) == 0) {
                    printf("The color code for %s is %d\n", input, colors[i].code);
                    break;
                }
            }
            break;

        case 2:
            printf("Enter the color code: ");
            scanf("%d", &i);

            for(i = 0; i < MAX_COLORS; i++) {
                if(colors[i].code == i) {
                    printf("The name of the color with code %d is %s\n", i, colors[i].name);
                    break;
                }
            }
            break;

        case 3:
            printf("Available colors:\n");
            for(i = 0; i < MAX_COLORS; i++) {
                printf("%s (%d)\n", colors[i].name, colors[i].code);
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}