//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the dimensions of the image
#define WIDTH 800
#define HEIGHT 600

// Define the maximum number of colors to use in the image
#define MAX_COLORS 256

// Define the data structure for a pixel
typedef struct {
    int x;
    int y;
    int color;
} Pixel;

// Define the data structure for a color
typedef struct {
    int r;
    int g;
    int b;
} Color;

// Function to initialize the random number generator
void init_random() {
    srand(time(NULL));
}

// Function to generate a random color
Color random_color() {
    Color color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    return color;
}

// Function to generate a random image using the given number of colors
void generate_image(int num_colors, Pixel pixels[], Color colors[]) {
    init_random();

    // Generate the colors
    for (int i = 0; i < num_colors; i++) {
        colors[i] = random_color();
    }

    // Generate the pixels
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i].x = rand() % WIDTH;
        pixels[i].y = rand() % HEIGHT;
        pixels[i].color = rand() % num_colors;
    }
}

// Function to print the image to the console
void print_image(Pixel pixels[], Color colors[]) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Pixel pixel = pixels[i];
        Color color = colors[pixel.color];
        printf("(%d,%d) -> %d,%d,%d\n", pixel.x, pixel.y, color.r, color.g, color.b);
    }
}

// Function to save the image to a file
void save_image(Pixel pixels[], Color colors[], char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLORS);

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Pixel pixel = pixels[i];
        Color color = colors[pixel.color];
        fprintf(file, "%d %d %d ", color.r, color.g, color.b);
    }

    fclose(file);
}

// Function to generate a random image and save it to a file
void generate_and_save_image(int num_colors, char* filename) {
    Pixel pixels[WIDTH * HEIGHT];
    Color colors[MAX_COLORS];

    generate_image(num_colors, pixels, colors);

    printf("Generated image:\n");
    print_image(pixels, colors);

    save_image(pixels, colors, filename);

    printf("Saved image to file %s\n", filename);
}

// Main function
int main() {
    int num_colors;

    printf("Enter the number of colors to use in the image: ");
    scanf("%d", &num_colors);

    char filename[100];
    printf("Enter the filename to save the image to: ");
    scanf("%s", filename);

    generate_and_save_image(num_colors, filename);

    return 0;
}