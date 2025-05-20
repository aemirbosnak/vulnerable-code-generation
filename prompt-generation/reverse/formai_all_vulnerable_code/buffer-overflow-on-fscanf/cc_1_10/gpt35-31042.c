//FormAI DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILENAME_LENGTH 256
#define MAX_FILTER_SIZE 15

// Functions
int apply_filter(char *filter_name, int filter_size, int *image_data, int width, int height);
int get_filter_index(char *filter_name);
int get_image_data(char *filename, int **image_data, int *width, int *height);
void save_image_data(char *filename, int *image_data, int width, int height);

int main(void) {
    // Variables
    char filename[MAX_FILENAME_LENGTH];
    char filter_name[MAX_FILENAME_LENGTH];
    int filter_size;
    int *image_data = NULL;
    int width, height;

    // Input
    printf("Enter the filename of the image to edit: ");
    scanf("%s", filename);

    // Load image data from file
    if (get_image_data(filename, &image_data, &width, &height) == 0) {
        printf("Error: Could not load image data from file.\n");
        return 1; // Error exit code
    }

    // Filter selection
    printf("List of available filters:\n");
    printf("1. Blur\n");
    printf("2. Sharpen\n");
    printf("3. Invert\n");
    printf("4. Brightness\n");
    printf("Enter the number of the filter to apply: ");
    int filter_option;
    scanf("%d", &filter_option);
    switch (filter_option) {
        case 1:
            strcpy(filter_name, "blur");
            filter_size = 3;
            break;
        case 2:
            strcpy(filter_name, "sharpen");
            filter_size = 3;
            break;
        case 3:
            strcpy(filter_name, "invert");
            filter_size = 1;
            break;
        case 4:
            strcpy(filter_name, "brightness");
            filter_size = 1;
            break;
        default:
            printf("Error: Invalid filter option.\n");
            return 1; // Error exit code
    }

    // Applying filter
    if (apply_filter(filter_name, filter_size, image_data, width, height) == 0) {
        printf("Error: Failed to apply filter.\n");
        return 1; // Error exit code
    }

    // Save the edited image data to file
    char output_filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename to save the edited image data: ");
    scanf("%s", output_filename);
    save_image_data(output_filename, image_data, width, height);

    // Freeing memory
    free(image_data);

    return 0; // Success exit code
}

/**
 * Applies a filter to an image.
 * @param filter_name: The name of the filter to apply.
 * @param filter_size: The size of the filter matrix (width or height).
 * @param image_data: The image data to filter.
 * @param width: The width of the image.
 * @param height: The height of the image.
 * @returns: 1 for success, 0 for failure.
 */
int apply_filter(char *filter_name, int filter_size, int *image_data, int width, int height) {
    // Variables
    int filter_matrix[MAX_FILTER_SIZE][MAX_FILTER_SIZE];

    // Load filter matrix data from file
    char filter_filename[MAX_FILENAME_LENGTH];
    sprintf(filter_filename, "%s.txt", filter_name); // Adding ".txt" extension to filter name
    FILE *filter_file = fopen(filter_filename, "r");
    if (filter_file == NULL) {
        printf("Error: Could not open filter file.\n");
        return 0; // Failure exit code
    }
    for (int i = 0; i < filter_size; i++) {
        for (int j = 0; j < filter_size; j++) {
            fscanf(filter_file, "%d", &filter_matrix[i][j]);
        }
    }
    fclose(filter_file);

    // Apply filter to image
    int half_filter_size = filter_size / 2;
    int *filtered_image_data = malloc(sizeof(int) * width * height);
    if (filtered_image_data == NULL) {
        printf("Error: Failed to allocate memory for filtered image data.\n");
        return 0; // Failure exit code
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < half_filter_size || i >= height - half_filter_size
                || j < half_filter_size || j >= width - half_filter_size) {
                filtered_image_data[i * width + j] = image_data[i * width + j]; // Edge pixels
            } else {
                int filtered_value = 0;
                for (int x = -half_filter_size; x <= half_filter_size; x++) {
                    for (int y = -half_filter_size; y <= half_filter_size; y++) {
                        filtered_value += image_data[(i + x) * width + j + y]
                                * filter_matrix[half_filter_size + x][half_filter_size + y];
                    }
                }
                filtered_image_data[i * width + j] = filtered_value;
            }
        }
    }

    // Copy filtered image data to original variable
    memcpy(image_data, filtered_image_data, sizeof(int) * width * height);

    // Freeing memory
    free(filtered_image_data);

    return 1; // Success exit code
}

/**
 * Returns the index of a filter based on its name.
 * @param filter_name: The name of the filter.
 * @returns: The index of the filter, or -1 if the filter is not found.
 */
int get_filter_index(char *filter_name) {
    // List of available filters
    char *filters[] = {"blur", "sharpen", "invert", "brightness"};
    int num_filters = sizeof(filters) / sizeof(filters[0]);

    for (int i = 0; i < num_filters; i++) {
        if (strcmp(filter_name, filters[i]) == 0) {
            return i;
        }
    }

    return -1; // Filter not found
}

/**
 * Loads an image from a file and returns its data in a dynamically allocated integer array.
 * @param filename: The name of the image file.
 * @param image_data: Pointer to the pointer that will store the image data.
 * @param width: Pointer to the variable that will store the width of the image.
 * @param height: Pointer to the variable that will store the height of the image.
 * @returns: 1 for success, 0 for failure.
 */
int get_image_data(char *filename, int **image_data, int *width, int *height) {
    // Open file for reading
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return 0; // Failure exit code
    }

    // Read header info
    int header_info[5];
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%d", &header_info[i]);
    }
    *width = header_info[0];
    *height = header_info[1];

    // Allocate memory for image data
    *image_data = malloc(sizeof(int) * (*width) * (*height));
    if (*image_data == NULL) {
        return 0; // Failure exit code
    }

    // Read image data
    int num_bytes = *width * (*height) * header_info[2] / 8;
    unsigned char *buffer = malloc(num_bytes);
    if (buffer == NULL) {
        return 0; // Failure exit code
    }
    fread(buffer, sizeof(unsigned char), num_bytes, file);
    int index = 0;
    for (int i = 0; i < (*height); i++) {
        for (int j = 0; j < (*width); j++) {
            int r = buffer[index];
            int g = buffer[index + 1];
            int b = buffer[index + 2];
            int a = header_info[2] == 32 ? buffer[index + 3] : 255; // Alpha channel (if present)
            (*image_data)[i * (*width) + j] = (a << 24) + (r << 16) + (g << 8) + b; // RGBA value
            index += header_info[2] / 8; // Increment index
        }
    }

    // Freeing memory
    free(buffer);
    fclose(file);

    return 1; // Success exit code
}

/**
 * Saves the image data to a file.
 * @param filename: The name of the output file.
 * @param image_data: The image data to save.
 * @param width: The width of the image.
 * @param height: The height of the image.
 */
void save_image_data(char *filename, int *image_data, int width, int height) {
    // Open file for writing
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open output file.\n");
        return;
    }

    // Write header info
    int header_info[5];
    header_info[0] = width;
    header_info[1] = height;
    header_info[2] = 32; // RGBA format
    header_info[3] = 0;
    header_info[4] = 0;
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%d ", header_info[i]);
    }

    // Write image data
    unsigned char *buffer = malloc(sizeof(unsigned char) * width * height * 4); // 4 bytes per pixel (RGBA)
    if (buffer == NULL) {
        printf("Error: Failed to allocate memory for output buffer.\n");
        fclose(file);
        return;
    }
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int rgba = image_data[i * width + j];
            buffer[index] = (rgba >> 16) & 0xFF; // Red
            buffer[index + 1] = (rgba >> 8) & 0xFF; // Green
            buffer[index + 2] = rgba & 0xFF; // Blue
            buffer[index + 3] = (rgba >> 24) & 0xFF; // Alpha
            index += 4;
        }
    }
    fwrite(buffer, sizeof(unsigned char), width * height * 4, file);

    // Freeing memory
    free(buffer);
    fclose(file);
}