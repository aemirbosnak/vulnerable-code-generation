//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    char hex[8];
} color;

color colors[MAX_COLORS] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"magenta", "#FF00FF"},
    {"cyan", "#00FFFF"},
    {"gray", "#AAAAAA"},
    {"light_gray", "#CCCCCC"},
    {"dark_gray", "#444444"},
    {"light_red", "#FF5555"},
    {"light_green", "#55FF55"},
    {"light_blue", "#5555FF"},
    {"light_yellow", "#FFFF55"}
};

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        exit(1);
    }

    char *color_name = argv[1];
    int i;

    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("%s\n", colors[i].hex);
            break;
        }
    }

    if (i == MAX_COLORS) {
        printf("Invalid color name.\n");
        exit(1);
    }

    return 0;
}