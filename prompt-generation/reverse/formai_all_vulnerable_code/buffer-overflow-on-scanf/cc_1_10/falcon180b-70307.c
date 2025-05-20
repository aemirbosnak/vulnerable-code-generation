//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLOR_NAMES 100

enum {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE,
    BLACK,
    WHITE,
    GREY,
    UNKNOWN
};

struct color_name {
    char *name;
    int value;
};

struct color_name color_names[] = {
    {"red", RED},
    {"orange", ORANGE},
    {"yellow", YELLOW},
    {"green", GREEN},
    {"blue", BLUE},
    {"purple", PURPLE},
    {"black", BLACK},
    {"white", WHITE},
    {"grey", GREY},
    {NULL, UNKNOWN}
};

int main() {
    int choice;
    int random_color;

    srand(time(NULL));
    random_color = rand() % 9;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert a color name to its RGB value\n");
    printf("2. Convert an RGB value to its color name\n");
    printf("3. Generate a random color name and its RGB value\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a color name: ");
            scanf("%s", color_names[random_color].name);
            printf("The RGB value for %s is: %d\n", color_names[random_color].name, random_color);
            break;
        case 2:
            printf("Enter an RGB value (0-8): ");
            scanf("%d", &random_color);
            for (int i = 0; color_names[i].name!= NULL; i++) {
                if (color_names[i].value == random_color) {
                    printf("The color name for RGB value %d is: %s\n", random_color, color_names[i].name);
                    break;
                }
            }
            break;
        case 3:
            printf("A random color name and its RGB value:\n");
            printf("Color name: %s\n", color_names[random_color].name);
            printf("RGB value: %d\n", random_color);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}