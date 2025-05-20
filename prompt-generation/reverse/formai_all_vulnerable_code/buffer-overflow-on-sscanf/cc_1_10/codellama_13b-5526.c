//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
// Color Code Converter
// A cheerful example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a color
struct color {
    char name[20];
    int r;
    int g;
    int b;
};

// Define a function to convert a color to a string
char* color_to_string(struct color* color) {
    char* str = malloc(sizeof(char) * 7);
    sprintf(str, "%d,%d,%d", color->r, color->g, color->b);
    return str;
}

// Define a function to convert a string to a color
struct color* string_to_color(char* str) {
    struct color* color = malloc(sizeof(struct color));
    sscanf(str, "%d,%d,%d", &color->r, &color->g, &color->b);
    return color;
}

int main() {
    // Declare a color
    struct color my_color;

    // Set the color's name and values
    strcpy(my_color.name, "Red");
    my_color.r = 255;
    my_color.g = 0;
    my_color.b = 0;

    // Print the color's name and values
    printf("Color: %s\n", my_color.name);
    printf("RGB: %d,%d,%d\n", my_color.r, my_color.g, my_color.b);

    // Convert the color to a string
    char* str = color_to_string(&my_color);
    printf("String: %s\n", str);

    // Convert the string back to a color
    struct color* color = string_to_color(str);
    printf("Color: %s\n", color->name);
    printf("RGB: %d,%d,%d\n", color->r, color->g, color->b);

    // Free the memory allocated for the string
    free(str);

    return 0;
}