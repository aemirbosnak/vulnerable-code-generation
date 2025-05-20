//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 100
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[MAX_COLOR_CODE_LENGTH];
} color_t;

color_t colors[] = {
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"orange", "#FFA500"},
    {"purple", "#800080"},
    {"pink", "#FFC0CB"},
    {"white", "#FFFFFF"},
    {"black", "#000000"},
    {"gray", "#808080"},
    {"brown", "#A52A2A"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"teal", "#008080"}
};

int main() {
    int num_colors = sizeof(colors) / sizeof(color_t);
    int choice;

    printf("Enter the number of colors you want to convert:\n");
    scanf("%d", &choice);

    if (choice > num_colors) {
        printf("Invalid choice\n");
        return 1;
    }

    int i;
    for (i = 0; i < choice; i++) {
        printf("Enter the name of the color you want to convert (red, green, blue, etc.):\n");
        scanf(" %s", colors[i].name);

        if (strlen(colors[i].name) > MAX_COLOR_NAME_LENGTH) {
            printf("Color name too long\n");
            return 1;
        }
    }

    for (i = 0; i < choice; i++) {
        printf("The hex code for %s is %s\n", colors[i].name, colors[i].hex);
    }

    return 0;
}