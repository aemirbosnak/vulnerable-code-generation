//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100

// Function to read the image file and store it in a 2D array
unsigned char** read_image_file(char* filename, int* width, int* height) {
    unsigned char** image_matrix = NULL;

    // Open the image file
    FILE* file = fopen(filename, "rb");

    if (file != NULL) {
        // Read the header to get the width and height of the image
        char header[54];
        fread(header, 1, 54, file);
        *width = *(int*)&header[18];
        *height = *(int*)&header[22];
        int bit_depth = *(int*)&header[28];
        
        // Check for supported bit depth
        if (bit_depth != 24) {
            printf("Unsupported bit depth. Only 24-bit RGB images are supported.");
            fclose(file);
            return NULL;
        }

        // Allocate memory for the image matrix
        image_matrix = (unsigned char**)malloc(*height * sizeof(unsigned char*));
        for (int i = 0; i < *height; i++) {
            image_matrix[i] = (unsigned char*)malloc(*width * 3 * sizeof(unsigned char));
        }

        // Read the pixel data into the image matrix
        for (int i = 0; i < *height; i++) {
            for (int j = 0; j < *width * 3; j++) {
                fread(&image_matrix[i][j], 1, 1, file);
            }
        }

        fclose(file);
    } else {
        printf("Failed to open file: %s", filename);
    }

    return image_matrix;
}

// Function to write the image from the 2D array into a new file
void write_image_file(char* filename, unsigned char** image_matrix, int width, int height) {
    // Create the new image file
    FILE* file = fopen(filename, "wb");

    if (file != NULL) {
        // Create the header for the new image file
        char header[54];
        memset(header, 0, 54);
        header[0] = 'B';
        header[1] = 'M';
        *(int*)&header[2] = 54 + width * height * 3;  // File size
        *(int*)&header[10] = 54;  // RGB data offset
        *(int*)&header[14] = 40;  // Info header size
        *(int*)&header[18] = width;
        *(int*)&header[22] = height;
        *(short*)&header[26] = 1;  // Color planes
        *(short*)&header[28] = 24;  // Bits per pixel

        // Write the header to the new image file
        fwrite(header, 1, 54, file);

        // Write the pixel data from the image matrix to the new image file
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width * 3; j++) {
                fwrite(&image_matrix[i][j], 1, 1, file);
            }
        }

        fclose(file);
    } else {
        printf("Failed to create file: %s", filename);
    }
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    int width, height;
    printf("Enter the name of the image file to edit: ");
    scanf("%s", filename);

    // Read the image file and store the pixel data in a 2D array
    unsigned char** image_matrix = read_image_file(filename, &width, &height);
    if (image_matrix == NULL) {
        return 1;
    }

    // Make changes to the image matrix here

    // Write the updated image to a new file
    char new_filename[MAX_FILENAME_SIZE];
    printf("\nEnter the name of the new image file: ");
    scanf("%s", new_filename);
    write_image_file(new_filename, image_matrix, width, height);

    // Free the memory allocated for the image matrix
    for (int i = 0; i < height; i++) {
        free(image_matrix[i]);
    }
    free(image_matrix);

    printf("\nImage editing completed. New image saved to %s", new_filename);
    return 0;
}