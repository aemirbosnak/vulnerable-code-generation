//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 10
#define MAX_COLOR_CODE_LEN 8

// Define the color name and its corresponding hex code
struct color_code {
    char name[MAX_COLOR_NAME_LEN];
    char hex_code[MAX_COLOR_CODE_LEN];
};

// Function to convert hex code to RGB values
void hex_to_rgb(char* hex_code, int* rgb_values) {
    int red = 0, green = 0, blue = 0;
    if (strlen(hex_code)!= 6) {
        printf("Error: Invalid hex code.\n");
        exit(1);
    }
    sscanf(hex_code, "#%02x%02x%02x", &red, &green, &blue);
    rgb_values[0] = red;
    rgb_values[1] = green;
    rgb_values[2] = blue;
}

// Function to print the RGB values of a given color
void print_rgb_values(int* rgb_values) {
    printf("RGB values: %d, %d, %d\n", rgb_values[0], rgb_values[1], rgb_values[2]);
}

// Function to print the available color codes
void print_color_codes() {
    struct color_code color_codes[] = {{"red", "#FF0000"}, {"green", "#00FF00"}, {"blue", "#0000FF"}};
    int num_color_codes = sizeof(color_codes) / sizeof(struct color_code);
    printf("Available color codes:\n");
    for (int i = 0; i < num_color_codes; i++) {
        printf("%s - %s\n", color_codes[i].name, color_codes[i].hex_code);
    }
}

int main() {
    char input_color_code[MAX_COLOR_CODE_LEN];
    int rgb_values[3];

    // Prompt the user to enter a color code
    printf("Enter a color code (e.g. #FF0000 for red): ");
    scanf("%s", input_color_code);

    // Convert the input color code to RGB values
    hex_to_rgb(input_color_code, rgb_values);

    // Print the RGB values of the input color code
    print_rgb_values(rgb_values);

    return 0;
}