//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *hex;
    char *rgb;
    char *name;
} color_t;

static color_t colors[] = {
    {"#FF0000", "rgb(255, 0, 0)", "red"},
    {"#00FF00", "rgb(0, 255, 0)", "green"},
    {"#0000FF", "rgb(0, 0, 255)", "blue"},
    {"#FFFF00", "rgb(255, 255, 0)", "yellow"},
    {"#00FFFF", "rgb(0, 255, 255)", "cyan"},
    {"#FF00FF", "rgb(255, 0, 255)", "magenta"},
    {"#000000", "rgb(0, 0, 0)", "black"},
    {"#FFFFFF", "rgb(255, 255, 255)", "white"}
};

static void handler(void *arg, int status, size_t len) {
    char *response = arg;
    printf("%.*s\n", (int)len, response);
}

int main() {
    char hex[9];
    char *rgb;
    char *name;

    printf("Enter a hex color code: ");
    scanf("%s", hex);

    for (int i = 0; i < sizeof(colors) / sizeof(color_t); i++) {
        if (strcmp(colors[i].hex, hex) == 0) {
            rgb = colors[i].rgb;
            name = colors[i].name;
            break;
        }
    }

    if (rgb == NULL || name == NULL) {
        printf("Invalid color code\n");
        return 1;
    }

    printf("RGB: %s\n", rgb);
    printf("Name: %s\n", name);

    return 0;
}