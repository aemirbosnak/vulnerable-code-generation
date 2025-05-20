//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16 // Maximum number of colors to support

// Define the color codes
char *color_codes[] = {
    "Black", "Maroon", "Green", "Olive",
    "Navy", "Purple", "Teal", "Silver",
    "Gray", "Red", "Lime", "Yellow",
    "Blue", "Fuchsia", "Aqua", "White"
};

// Function to convert color name to code
int get_color_code(char *color_name) {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(color_name, color_codes[i]) == 0) {
            return i;
        }
    }
    return -1; // Color not found
}

// Function to print usage instructions
void print_usage() {
    printf("Usage: color_converter <color_name> <text>\n");
    printf("Color names: Black, Maroon, Green, Olive, Navy, Purple, Teal, Silver,\n");
    printf("Gray, Red, Lime, Yellow, Blue, Fuchsia, Aqua, White\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    char *color_name = argv[1];
    char *text = argv[2];

    int color_code = get_color_code(color_name);
    if (color_code == -1) {
        printf("Error: Invalid color name\n");
        return 1;
    }

    printf("\033[0;%dm%s\033[0m\n", color_code, text);

    return 0;
}