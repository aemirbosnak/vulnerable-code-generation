//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char name[20];
    int r;
    int g;
    int b;
} Color;

Color colors[] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Magenta", 255, 0, 255},
    {"Cyan", 0, 255, 255},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255}
};

int getIndex(Color colors[], char name[], int len) {
    for (int i = 0; i < len; i++) {
        if (strncmp(colors[i].name, name, strlen(name)) == 0) {
            return i;
        }
    }
    return -1;
}

void rgbToHex(int r, int g, int b, char hex[7]) {
    int val[3] = {r, g, b};
    for (int i = 0; i < 3; i++) {
        int digit = val[i] / 16;
        int rem = val[i] % 16;
        if (digit > 9) {
            hex[i * 2] = digit + 55;
        } else {
            hex[i * 2] = digit + '0';
        }
        digit = rem;
        hex[i * 2 + 1] = digit > 9 ? digit + 55 : digit + '0';
    }
}

int main() {
    char input[50];
    int index;
    Color color;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color name or RGB values (separated by commas): ");
    scanf("%s", input);

    if (sscanf(input, "%d,%d,%d", &color.r, &color.g, &color.b) == 3) {
        printf("You entered RGB values: %d, %d, %d\n", color.r, color.g, color.b);
        rgbToHex(color.r, color.g, color.b, color.name);
        printf("The hex code for this color is: %s\n", color.name);
    } else {
        index = getIndex(colors, input, sizeof(colors) / sizeof(Color));
        if (index != -1) {
            color = colors[index];
            rgbToHex(color.r, color.g, color.b, color.name);
            printf("You entered the color name: %s\n", color.name);
            printf("The hex code for this color is: %s\n", color.name);
        } else {
            printf("Invalid color name or RGB values.\n");
        }
    }

    return 0;
}