//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"gray", "#808080"}
};

int num_colors = sizeof(colors) / sizeof(Color);

void print_colors() {
    printf("Color\tCode\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s\t%s\n", colors[i].name, colors[i].hex);
    }
}

int main() {
    char input[MAX_COLOR_NAME_LENGTH];
    int index;

    print_colors();

    printf("Enter a color name: ");
    scanf("%s", input);

    for (index = 0; index < num_colors; index++) {
        if (strcmp(colors[index].name, input) == 0) {
            printf("The hexadecimal code for %s is: %s\n", input, colors[index].hex);
            return 0;
        }
    }

    printf("Invalid color name.\n");
    return 1;
}