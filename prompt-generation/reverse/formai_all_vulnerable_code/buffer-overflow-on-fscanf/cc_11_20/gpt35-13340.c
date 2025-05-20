//FormAI DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    FILE *image_file, *new_image_file;
    int height, width, i, j;
    char mode[3];
    unsigned char pixel;

    //Open the image file
    image_file = fopen("input_image.ppm", "rb");

    //Read the mode of the image (P2 or P5)
    fscanf(image_file, "%s", mode);

    //Skip the comments
    char c = getc(image_file);
    while (c == '#') {
        while (getc(image_file) != '\n');
        c = getc(image_file);
    }
    ungetc(c, image_file);
    
    //Read the width of the image
    fscanf(image_file, "%d", &width);

    //Read the height of the image
    fscanf(image_file, "%d", &height);

    //Read the maximum value of the pixels
    int maxval;
    fscanf(image_file, "%d", &maxval);
    
    //Allocate memory for the image
    unsigned char **image = malloc(height * sizeof(unsigned char *));
    for (i = 0; i < height; i++) 
        image[i] = malloc(width * sizeof(unsigned char));

    //Read the pixels of the image
    if (strcmp(mode, "P5") == 0) {
        fgetc(image_file); //Skip the newline character after the maximum value
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                image[i][j] = fgetc(image_file);
            }
        }
    } else if (strcmp(mode, "P2") == 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                fscanf(image_file, "%hhu", &pixel);
                image[i][j] = pixel;
            }
        }
    }

    //Close the image file
    fclose(image_file);

    //Apply a filter to the image (e.g. invert the colors)
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i][j] = maxval - image[i][j];
        }
    }

    //Save the new image
    new_image_file = fopen("output_image.ppm", "wb");

    //Write the mode of the image (P2 or P5)
    fprintf(new_image_file, "%s\n", mode);

    //Write the width of the image
    fprintf(new_image_file, "%d ", width);

    //Write the height of the image
    fprintf(new_image_file, "%d\n", height);

    //Write the maximum value of the pixels
    fprintf(new_image_file, "%d\n", maxval);

    //Write the pixels of the image
    if (strcmp(mode, "P5") == 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                fputc(image[i][j], new_image_file);
            }
        }
    } else if (strcmp(mode, "P2") == 0) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {    
                fprintf(new_image_file, "%hhu ", image[i][j]);
            }
            fprintf(new_image_file, "\n");
        }
    }

    //Close the new image file
    fclose(new_image_file);

    //Free the memory allocated for the image
    for (i = 0; i < height; i++) 
        free(image[i]);
    free(image);

    return 0;
}