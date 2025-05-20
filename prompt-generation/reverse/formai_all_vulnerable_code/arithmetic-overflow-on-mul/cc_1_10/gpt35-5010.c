//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[50];
    int width, height;
    int i, j;
    unsigned char *image;
    FILE *file;

    printf("Enter the filename of the image to edit (include extension): ");
    scanf("%s", filename);

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 0;
    }

    fseek(file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    fseek(file, 54, SEEK_SET);

    image = (unsigned char*) malloc(width * height * 3 * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height * 3, file);

    fclose(file);

    // Edit Image Here
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int red = image[(i * width + j) * 3];
            int green = image[(i * width + j) * 3 + 1];
            int blue = image[(i * width + j) * 3 + 2];

            // Convert to Grayscale
            int grayscale = 0.2989 * red + 0.5870 * green + 0.1140 * blue;

            image[(i * width + j) * 3] = grayscale;
            image[(i * width + j) * 3 + 1] = grayscale;
            image[(i * width + j) * 3 + 2] = grayscale;
        }
    }

    // Save the edited image
    char output_filename[50];
    printf("Enter the filename to save the edited image as (include extension): ");
    scanf("%s", output_filename);

    file = fopen(output_filename, "wb");
    if (file == NULL) {
        printf("Error: Unable to create file.\n");
        return 0;
    }

    fwrite(image, sizeof(unsigned char), width * height * 3, file);

    fclose(file);
    free(image);

    printf("Image saved successfully.");
    
    return 0;
}