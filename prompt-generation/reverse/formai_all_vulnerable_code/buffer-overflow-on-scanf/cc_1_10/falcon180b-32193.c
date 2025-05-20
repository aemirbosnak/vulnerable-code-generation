//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_COLOR_CODE 16777215 // 2^24 - 1

// Function to generate a random color code
int generate_color_code() {
    return rand() % MAX_COLOR_CODE;
}

// Function to convert a color code to RGB values
void color_code_to_rgb(int color_code, int *r, int *g, int *b) {
    *r = (color_code >> 16) & 0xFF;
    *g = (color_code >> 8) & 0xFF;
    *b = color_code & 0xFF;
}

// Function to convert RGB values to a color code
int rgb_to_color_code(int r, int g, int b) {
    return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

// Function to print a color code in hex format
void print_color_code(int color_code) {
    printf("#%06X\n", color_code);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int color_code;
    int r, g, b;

    // Generate 10 random color codes and print them in hex format
    for (int i = 0; i < 10; i++) {
        color_code = generate_color_code();
        color_code_to_rgb(color_code, &r, &g, &b);
        printf("Random color %d: (%d, %d, %d)\n", i + 1, r, g, b);
        print_color_code(color_code);
    }

    // Prompt the user to enter a color code and print its RGB values
    printf("\nEnter a color code in hex format (e.g. #FF0000): ");
    scanf("%x", &color_code);
    color_code_to_rgb(color_code, &r, &g, &b);
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    return 0;
}