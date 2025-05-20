//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 70
#define MAX_HEIGHT 70

char ascii_characters[] = {' ','.','\'',':','o','&','8','#','@'};

int grayscale_values[MAX_WIDTH][MAX_HEIGHT];

// Convert RGB values to grayscale value using Luma method
int get_grayscale_value(int red, int green, int blue) {
    return 0.2126 * red + 0.7152 * green + 0.0722 * blue;
}

// Read the image contents from file and store grayscale values in array
void read_image(FILE *image_file) {
    char buffer[16];
    int width, height, max_gray;
    fscanf(image_file, "%s\n%d %d\n%d\n", buffer, &width, &height, &max_gray);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int red, green, blue;
            fscanf(image_file, "%d %d %d", &red, &green, &blue);
            grayscale_values[i][j] = get_grayscale_value(red, green, blue);
        }
    }
}

// Convert grayscale values to ASCII characters and print the art
void print_ascii_art() {
    for(int i = 0; i < MAX_HEIGHT; i++) {
        for(int j = 0; j < MAX_WIDTH; j++) {
            int index = grayscale_values[i][j] / 25;
            printf("%c", ascii_characters[index]);
        }
        printf("\n");
    }
}

int main() {
    FILE *image_file = fopen("example_image.ppm", "r");
    if(image_file == NULL) {
        perror("Could not open image file");
        exit(EXIT_FAILURE);
    }

    read_image(image_file);
    fclose(image_file);

    print_ascii_art();
    
    return 0;
}