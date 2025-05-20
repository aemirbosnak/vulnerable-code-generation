//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

void print_rgb(RGB rgb) {
    printf("R: %d, G: %d, B: %d\n", rgb.r, rgb.g, rgb.b);
}

RGB hex_to_rgb(char* hex) {
    RGB rgb;
    sscanf(hex, "%2hhx%2hhx%2hhx", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

void rgb_to_hex(RGB rgb, char* hex) {
    snprintf(hex, sizeof(hex), "%02x%02x%02x", rgb.r, rgb.g, rgb.b);
}

void shift_colors(RGB* colors, int num_colors, int shifts) {
    for (int i = 0; i < num_colors; i++) {
        for (int j = 0; j < shifts; j++) {
            int index = i + (j % num_colors);
            RGB temp = colors[i];
            colors[i] = colors[index];
            colors[index] = temp;
        }
    }
}

int main() {
    int num_colors = 5;
    int shifts = 3;
    RGB colors[num_colors];
    char hex_str[32];

    for (int i = 0; i < num_colors; i++) {
        printf("Enter color %d in hex format: ", i + 1);
        scanf("%s", hex_str);
        colors[i] = hex_to_rgb(hex_str);
        printf("Color %d in RGB format: ", i + 1);
        print_rgb(colors[i]);
    }

    printf("\nShifting colors %d times:\n", shifts);
    shift_colors(colors, num_colors, shifts);

    printf("\nColors after shifting:\n");
    for (int i = 0; i < num_colors; i++) {
        rgb_to_hex(colors[i], hex_str);
        printf("Color %d in hex format: %s\n", i + 1, hex_str);
    }

    return 0;
}