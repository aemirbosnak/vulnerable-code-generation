//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    int code;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 31},
    {"green", 32},
    {"yellow", 33},
    {"blue", 34},
    {"magenta", 35},
    {"cyan", 36},
    {"gray", 37},
    {"light-red", 91},
    {"light-green", 92},
    {"light-yellow", 93},
    {"light-blue", 94},
    {"light-magenta", 95},
    {"light-cyan", 96},
    {"light-gray", 97}
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color>\n", argv[0]);
        exit(1);
    }

    char *color_name = argv[1];
    int i;

    for (i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("%s\n", colors[i].name);
            printf("Code: %d\n", colors[i].code);
            return 0;
        }
    }

    printf("Invalid color name.\n");
    return 1;
}