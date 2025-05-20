//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
// Welcome to the nuclear winter, where color is a fading memory.

#include <stdio.h>
#include <stdlib.h>

// Our tattered color palette, scarred by the apocalypse.
typedef enum {
    RUSTED_RED,
    ASHEN_GRAY,
    MUTATED_GREEN,
    RADIANT_YELLOW,
    IRRADIATED_BLUE,
    VOID_BLACK,
} Color;

// A map to guide us through the murky wasteland of color codes.
char *color_codes[] = {
    "192", "128", "0",
    "128", "128", "128",
    "0", "128", "0",
    "255", "255", "0",
    "0", "0", "255",
    "0", "0", "0"
};

// A glimmer of hope in the darkness, our color converter.
char *convert_color(Color color) {
    return color_codes[color];
}

// A beacon of information in the barren landscape.
void print_color_options() {
    printf("Colors of the apocalypse:\n");
    for (Color color = 0; color < VOID_BLACK; color++) {
        printf("  %s: %s\n", convert_color(color), color_codes[color]);
    }
}

// Our journey begins in the desolate wasteland of the main function.
int main() {
    // Unveil the secrets of the color code.
    printf("Enter a color (0-5): ");
    int color_choice;
    scanf("%d", &color_choice);

    // Dispatch a message from the remnants of humanity.
    printf("Color code: %s\n", convert_color(color_choice));

    // A lantern in the void, illuminating the path to color knowledge.
    print_color_options();

    return 0;
}