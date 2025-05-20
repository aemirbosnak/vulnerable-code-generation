//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int code;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char* name, int code) {
    if (num_colors >= MAX_COLORS) {
        printf("Error: Maximum number of colors reached.\n");
        exit(1);
    }

    strcpy(colors[num_colors].name, name);
    colors[num_colors].code = code;
    num_colors++;
}

int main() {
    add_color("red", 0xff0000);
    add_color("green", 0x00ff00);
    add_color("blue", 0x0000ff);
    add_color("yellow", 0xffff00);
    add_color("purple", 0x800080);
    add_color("orange", 0xffa500);

    // Test color conversion
    char input[20];
    int code;

    printf("Enter a color name: ");
    scanf("%s", input);

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            code = colors[i].code;
            break;
        }
    }

    if (code == 0) {
        printf("Error: Color not found.\n");
        exit(1);
    }

    printf("RGB code: %06x\n", code);

    return 0;
}