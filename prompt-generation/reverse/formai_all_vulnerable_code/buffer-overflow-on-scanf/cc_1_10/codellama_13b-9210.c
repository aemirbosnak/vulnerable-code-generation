//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: dynamic
// Color Code Converter
#include <stdio.h>
#include <string.h>

// Define the color codes
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET   "\x1B[0m"

// Define the color names
char *color_names[] = {
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "Magenta",
    "Cyan",
    "White"
};

// Define the color codes
char *color_codes[] = {
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

// Define the main function
int main() {
    // Get the input from the user
    char color_name[20];
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Check if the input is a valid color name
    int color_index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(color_name, color_names[i]) == 0) {
            color_index = i;
            break;
        }
    }

    // If the input is a valid color name, print the corresponding color code
    if (color_index != -1) {
        printf("%s\n", color_codes[color_index]);
    } else {
        printf("Invalid color name.\n");
    }

    return 0;
}