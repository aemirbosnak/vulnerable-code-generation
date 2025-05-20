//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

void print_color(Color color) {
    printf("Name: %s\n", color.name);
    printf("Red: %d\n", color.red);
    printf("Green: %d\n", color.green);
    printf("Blue: %d\n", color.blue);
}

int main() {
    int num_colors;
    Color colors[50];

    printf("How many colors would you like to enter? ");
    scanf("%d", &num_colors);

    for (int i = 0; i < num_colors; i++) {
        printf("Enter color name (max %d characters): ", MAX_COLOR_NAME_LENGTH);
        scanf("%s", colors[i].name);

        printf("Enter red value (0-255): ");
        scanf("%d", &colors[i].red);

        printf("Enter green value (0-255): ");
        scanf("%d", &colors[i].green);

        printf("Enter blue value (0-255): ");
        scanf("%d", &colors[i].blue);
    }

    printf("Enter a color name to search for: ");
    char search_name[MAX_COLOR_NAME_LENGTH];
    scanf("%s", search_name);

    Color* found_color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, search_name) == 0) {
            found_color = &colors[i];
            break;
        }
    }

    if (found_color == NULL) {
        printf("Color not found.\n");
    } else {
        print_color(*found_color);
    }

    return 0;
}