//FormAI DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
} color_t;

color_t hex_to_rgb(char hex[]) {
    unsigned int red, green, blue;
    sscanf(hex, "%02x%02x%02x", &red, &green, &blue);

    color_t color = {red, green, blue};
    return color;
}

char* rgb_to_hex(color_t color) {
    char* hex = (char*) malloc(7 * sizeof(char));
    sprintf(hex, "#%02x%02x%02x", color.red, color.green, color.blue);

    return hex;
}

void convert_color(char type[], char color[]) {
    if (type[0] == 'h') {
        color_t rgb_color = hex_to_rgb(color);
        printf("RGB: %u, %u, %u\n", rgb_color.red, rgb_color.green, rgb_color.blue);
    } else if (type[0] == 'r') {
        char* hex_color = rgb_to_hex((color_t) {atoi(&color[0]), atoi(&color[2]), atoi(&color[4])});
        printf("Hex: %s\n", hex_color);
        free(hex_color);
    } else {
        printf("Invalid type.\n");
    }
}

int main() {
    char type[10], color[10];

    printf("Enter color type (hex or rgb): ");
    scanf("%s", type);

    printf("Enter color code: ");
    scanf("%s", color);

    convert_color(type, color);

    return 0;
}