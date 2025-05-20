//FormAI DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILENAME_SIZE 50
#define MAX_FILTER_SIZE 3

int main() {
    char filename[MAX_FILENAME_SIZE];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Open the image file
    FILE *image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    // Read the header information
    char header[54];
    fread(header, sizeof(char), 54, image_file);

    // Get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the size of the image data in bytes
    int padding = 0;
    while ((width*3 + padding) % 4 != 0) {
        padding++;
    }
    int image_size = (width*3 + padding) * height;

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char*)malloc(image_size);

    // Read the image data
    fread(image_data, sizeof(char), image_size, image_file);

    // Close the image file
    fclose(image_file);

    // Set up the image filters
    int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE] = {
        {-1, -1, -1},
        {-1, 8, -1},
        {-1, -1, -1}
    };

    int filter_width = MAX_FILTER_SIZE;
    int filter_height = MAX_FILTER_SIZE;

    // Apply the filter to the image
    unsigned char *filtered_data = (unsigned char*)malloc(image_size);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int red = 0;
            int green = 0;
            int blue = 0;

            // Apply the filter to the current pixel and its neighbors
            for (int j = 0; j < filter_height; j++) {
                for (int i = 0; i < filter_width; i++) {
                    int x_index = x + i - (filter_width/2);
                    int y_index = y + j - (filter_height/2);

                    if (x_index >= 0 && x_index < width && y_index >= 0 && y_index < height) {
                        // Get the color values for the current neighbor pixel
                        int index = (y_index*(width*3 + padding)) + (x_index*3);
                        red += filter[j][i] * image_data[index + 2];
                        green += filter[j][i] * image_data[index + 1];
                        blue += filter[j][i] * image_data[index];
                    }
                }
            }

            // Set the filtered pixel color values
            int index = (y*(width*3 + padding)) + (x*3);
            filtered_data[index + 2] = red;
            filtered_data[index + 1] = green;
            filtered_data[index] = blue;
        }
    }

    // Open the output image file
    char output_filename[MAX_FILENAME_SIZE+10];
    sprintf(output_filename, "filtered_%s", filename);
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not create output file.\n");
        return 1;
    }

    // Write the header and filtered image data to the output file
    fwrite(header, sizeof(char), 54, output_file);
    fwrite(filtered_data, sizeof(char), image_size, output_file);

    // Close the output file
    fclose(output_file);

    // Free the memory
    free(image_data);
    free(filtered_data);

    printf("The image has been successfully filtered and saved to %s.\n", output_filename);

    return 0;
}