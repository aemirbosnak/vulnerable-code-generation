//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void get_color_code(char *color_name, int *red, int *green, int *blue);
void print_color_code(int red, int green, int blue);

int main() {
    char color_name[20];
    int red, green, blue;

    // Get color code from user input
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Convert color name to RGB values
    get_color_code(color_name, &red, &green, &blue);

    // Print the RGB values
    printf("RGB values: ");
    print_color_code(red, green, blue);

    return 0;
}

// Function to get RGB values from color name
void get_color_code(char *color_name, int *red, int *green, int *blue) {
    if (strcmp(color_name, "red") == 0) {
        *red = 255;
        *green = 0;
        *blue = 0;
    } else if (strcmp(color_name, "green") == 0) {
        *red = 0;
        *green = 255;
        *blue = 0;
    } else if (strcmp(color_name, "blue") == 0) {
        *red = 0;
        *green = 0;
        *blue = 255;
    } else if (strcmp(color_name, "yellow") == 0) {
        *red = 255;
        *green = 255;
        *blue = 0;
    } else if (strcmp(color_name, "cyan") == 0) {
        *red = 0;
        *green = 255;
        *blue = 255;
    } else if (strcmp(color_name, "magenta") == 0) {
        *red = 255;
        *green = 0;
        *blue = 255;
    } else if (strcmp(color_name, "white") == 0) {
        *red = 255;
        *green = 255;
        *blue = 255;
    } else if (strcmp(color_name, "black") == 0) {
        *red = 0;
        *green = 0;
        *blue = 0;
    } else {
        printf("Invalid color name!\n");
        exit(1);
    }
}

// Function to print RGB values
void print_color_code(int red, int green, int blue) {
    printf("%d, %d, %d\n", red, green, blue);
}