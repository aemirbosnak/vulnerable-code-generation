//FormAI DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declare variables
    int height, width, choice, i, j;
    char filename[20];
    unsigned char *image;

    // Read the filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file and read header
    FILE* f = fopen(filename, "rb");
    if(f == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }
    fread(&height, sizeof(int), 1, f);
    fread(&width, sizeof(int), 1, f);

    // Allocate memory for the image
    image = (unsigned char*) malloc(height*width*sizeof(unsigned char));

    // Read the image data
    fread(image, sizeof(unsigned char), height*width, f);

    // Close the image file
    fclose(f);

    // Display the menu
    printf("\nMenu\n");
    printf("------------------------------\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Apply the selected operation to the image
    switch(choice) {
        case 1:
            for(i = 0; i < height; i++) {
                for(j = 0; j < width; j++) {
                    image[i*width+j] = 255 - image[i*width+j];
                }
            }
            break;
        case 2:
            for(i = 0; i < height; i++) {
                for(j = 0; j < width; j++) {
                    unsigned char pixel = image[i*width+j];
                    unsigned char gray = 0.21*pixel + 0.72*pixel + 0.07*pixel;
                    image[i*width+j] = gray;
                }
            }
            break;
        default:
            printf("Invalid Choice.\n");
            exit(1);
    }

    // Save the modified image
    printf("Enter the output filename: ");
    scanf("%s", filename);

    // Open the output file
    FILE* output = fopen(filename, "wb");
    if(output == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    // Write the header
    fwrite(&height, sizeof(int), 1, output);
    fwrite(&width, sizeof(int), 1, output);

    // Write the image data
    fwrite(image, sizeof(unsigned char), height*width, output);

    // Close the output file
    fclose(output);

    // Free the memory allocated for the image
    free(image);

    printf("Operation completed successfully.\n");

    return 0;
}