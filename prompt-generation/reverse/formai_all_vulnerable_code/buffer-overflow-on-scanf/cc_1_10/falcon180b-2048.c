//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

struct color {
    char name[20];
    int code;
};

struct color colors[MAX_COLORS] = {
    {"Black", 0},
    {"White", 1},
    {"Red", 2},
    {"Green", 3},
    {"Blue", 4},
    {"Yellow", 5},
    {"Cyan", 6},
    {"Magenta", 7},
    {"Gray", 8},
    {"DarkGray", 9}
};

int main() {
    int choice;
    char color_name[20];
    int color_code;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert color name to code\n");
    printf("2. Convert color code to name\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a color name: ");
            scanf("%s", color_name);

            for(int i=0; i<MAX_COLORS; i++) {
                if(strcmp(color_name, colors[i].name) == 0) {
                    printf("The color code for %s is %d\n", color_name, colors[i].code);
                    break;
                }
            }

            break;

        case 2:
            printf("Enter a color code: ");
            scanf("%d", &color_code);

            for(int i=0; i<MAX_COLORS; i++) {
                if(colors[i].code == color_code) {
                    printf("The color name for code %d is %s\n", color_code, colors[i].name);
                    break;
                }
            }

            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}