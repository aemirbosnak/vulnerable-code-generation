//FormAI DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_PIXEL_VALUE 255

int main() {
    char filename[MAX_FILENAME_SIZE];
    printf("Enter the filename of the image you want to edit: ");
    scanf("%s", filename);

    // Read image data from file
    FILE *image_file = fopen(filename, "r");
    if (image_file == NULL) {
        printf("Error: file not found.");
        return 1;
    }

    unsigned int height, width;
    fscanf(image_file, "%u %u", &height, &width);
    
    unsigned char **pixel_data = (unsigned char**) malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        pixel_data[i] = (unsigned char*) malloc(width * sizeof(unsigned char));
        for (int j = 0; j < width; j++) {
            fscanf(image_file, "%hhu", &pixel_data[i][j]);
        }
    }
    fclose(image_file);

    // Display menu to user
    printf("Welcome to the image editor!\n");
    printf("1. Apply grayscale filter\n");
    printf("2. Invert colors\n");
    printf("3. Flip horizontally\n");
    printf("4. Flip vertically\n");
    printf("5. Save and exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    // Process user's choice
    switch (choice) {
        case 1:
            printf("Applying grayscale filter...\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    unsigned char gray_value = pixel_data[i][j] * 0.3 + pixel_data[i][j] * 0.59 + pixel_data[i][j] * 0.11;
                    pixel_data[i][j] = gray_value;
                }
            }
            break;

        case 2:
            printf("Inverting colors...\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    unsigned char inverted_value = MAX_PIXEL_VALUE - pixel_data[i][j];
                    pixel_data[i][j] = inverted_value;
                }
            }
            break;

        case 3:
            printf("Flipping horizontally...\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width / 2; j++) {
                    unsigned char temp = pixel_data[i][j];
                    pixel_data[i][j] = pixel_data[i][width - j - 1];
                    pixel_data[i][width - j - 1] = temp;
                }
            }
            break;

        case 4:
            printf("Flipping vertically...\n");
            for (int i = 0; i < height / 2; i++) {
                unsigned char *temp_row = pixel_data[i];
                pixel_data[i] = pixel_data[height - i - 1];
                pixel_data[height - i - 1] = temp_row;
            }
            break;

        case 5:
            printf("Saving and exiting...\n");
            // Write edited image data to file
            FILE *edited_image_file = fopen(filename, "w");
            fprintf(edited_image_file, "%u %u\n", height, width);
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    fprintf(edited_image_file, "%hhu ", pixel_data[i][j]);
                }
                fprintf(edited_image_file, "\n");
            }
            fclose(edited_image_file);
            break;

        default:
            printf("Invalid choice. Exiting program...\n");
            return 1;
    }

    // Free memory allocated for pixel data
    for (int i = 0; i < height; i++) {
        free(pixel_data[i]);
    }
    free(pixel_data);

    return 0;
}