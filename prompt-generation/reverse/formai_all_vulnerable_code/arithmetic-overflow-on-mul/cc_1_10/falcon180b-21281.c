//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a pixel art image
void print_pixel_art(char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", image[i * width + j]);
        }
        printf("\n");
    }
}

// Function to generate a random pixel art image
char *generate_pixel_art(int width, int height) {
    char *image = malloc(width * height * sizeof(char));
    if (image == NULL) {
        printf("Error: Failed to allocate memory for pixel art image.\n");
        exit(1);
    }

    // Initialize the image with random characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = rand() % 26 + 'A';
        }
    }

    return image;
}

// Function to save a pixel art image to a file
void save_pixel_art(char *filename, char *image, int width, int height) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Failed to create file '%s'.\n", filename);
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%c", image[i * width + j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Pixel art saved to file '%s'.\n", filename);
}

int main() {
    srand(time(NULL));

    // Get user input for pixel art dimensions
    int width, height;
    printf("Enter the width of the pixel art image: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art image: ");
    scanf("%d", &height);

    // Generate a random pixel art image
    char *image = generate_pixel_art(width, height);

    // Print the pixel art image
    printf("Pixel art image:\n");
    print_pixel_art(image, width, height);

    // Save the pixel art image to a file
    char filename[100];
    printf("Enter the filename to save the pixel art image: ");
    scanf("%s", filename);
    save_pixel_art(filename, image, width, height);

    free(image);
    return 0;
}