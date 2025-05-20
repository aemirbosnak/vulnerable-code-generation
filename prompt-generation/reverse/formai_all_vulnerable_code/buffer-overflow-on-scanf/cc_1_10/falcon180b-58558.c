//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct {
    char name[20];
    int code;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0},
    {"White", 7},
    {"Red", 1},
    {"Green", 2},
    {"Yellow", 3},
    {"Blue", 4},
    {"Magenta", 5},
    {"Cyan", 6},
    {"Orange", 9},
    {"Purple", 5}
};

int main() {
    int choice, code;
    char color_name[20];

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter 1 to convert from name to code.\n");
    printf("Enter 2 to convert from code to name.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the color name: ");
        scanf("%s", color_name);

        for (int i = 0; i < MAX_COLORS; i++) {
            if (strcmp(color_name, colors[i].name) == 0) {
                printf("The color code for %s is %d.\n", colors[i].name, colors[i].code);
                return 0;
            }
        }

        printf("Color not found.\n");
        return 0;
    } else if (choice == 2) {
        printf("Enter the color code: ");
        scanf("%d", &code);

        for (int i = 0; i < MAX_COLORS; i++) {
            if (colors[i].code == code) {
                printf("The color name for code %d is %s.\n", code, colors[i].name);
                return 0;
            }
        }

        printf("Color code not found.\n");
        return 0;
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    return 0;
}