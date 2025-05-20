//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define MAX_FILE_PATH_LENGTH 100

int main(void) {
    char input_file[MAX_FILE_PATH_LENGTH];
    printf("Enter the input file path: ");
    fgets(input_file, MAX_FILE_PATH_LENGTH, stdin);
    input_file[strcspn(input_file, "\n")] = 0;

    printf("Choose an option:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Flip the image vertically\n");
    printf("3. Increase the brightness\n");
    printf("4. Decrease the brightness\n");
    printf("5. Increase the contrast\n");
    printf("6. Decrease the contrast\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    FILE* file_ptr = fopen(input_file, "rb");
    if (file_ptr == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    char output_file[MAX_FILE_PATH_LENGTH];
    sprintf(output_file, "output_%d.bmp", choice);

    FILE* output_file_ptr = fopen(output_file, "wb");
    if (output_file_ptr == NULL) {
        printf("Could not create output file.\n");
        return 1;
    }

    // Read header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file_ptr);
    fwrite(header, sizeof(unsigned char), 54, output_file_ptr);

    // Read image data into 2D array
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bit_depth = *(int*)&header[28];
    int row_size = (width * bit_depth / 8 + 3) / 4 * 4; // Padding
    unsigned char* img_data = (unsigned char*) malloc(row_size * height);
    fread(img_data, sizeof(unsigned char), row_size * height, file_ptr);

    if(choice == 1) { // Horizontal flip
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width / 2; j++) {
                for (int k = 0; k < bit_depth / 8; k++) {
                    unsigned char temp = img_data[i * row_size + j * bit_depth / 8 + k];
                    img_data[i * row_size + j * bit_depth / 8 + k] = img_data[i * row_size + (width - j - 1) * bit_depth / 8 + k];
                    img_data[i * row_size + (width - j - 1) * bit_depth / 8 + k] = temp;
                }
            }
        }
    } else if(choice == 2) { // Vertical flip
        for (int i = 0; i < height / 2; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < bit_depth / 8; k++) {
                    unsigned char temp = img_data[i * row_size + j * bit_depth / 8 + k];
                    img_data[i * row_size + j * bit_depth / 8 + k] = img_data[(height - i - 1) * row_size + j * bit_depth / 8 + k];
                    img_data[(height - i - 1) * row_size + j * bit_depth / 8 + k] = temp;
                }
            }
        }
    } else if(choice == 3) { // Increase brightness
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < bit_depth / 8; k++) {
                    int pixel_value = img_data[i * row_size + j * bit_depth / 8 + k];
                    pixel_value += 50;
                    if (pixel_value > MAX_PIXEL_VALUE) {
                        pixel_value = MAX_PIXEL_VALUE;
                    }
                    img_data[i * row_size + j * bit_depth / 8 + k] = (unsigned char)pixel_value;
                }
            }
        }
    } else if(choice == 4) { // Decrease brightness
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < bit_depth / 8; k++) {
                    int pixel_value = img_data[i * row_size + j * bit_depth / 8 + k];
                    pixel_value -= 50;
                    if (pixel_value < 0) {
                        pixel_value = 0;
                    }
                    img_data[i * row_size + j * bit_depth / 8 + k] = (unsigned char)pixel_value;
                }
            }
        }
    } else if(choice == 5) { // Increase contrast
        float alpha = 1.5;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < bit_depth / 8; k++) {
                    int pixel_value = img_data[i * row_size + j * bit_depth / 8 + k];
                    pixel_value = (int)(alpha * (pixel_value - MAX_PIXEL_VALUE / 2) + MAX_PIXEL_VALUE / 2);
                    if (pixel_value < 0) {
                        pixel_value = 0;
                    }
                    if (pixel_value > MAX_PIXEL_VALUE) {
                        pixel_value = MAX_PIXEL_VALUE;
                    }
                    img_data[i * row_size + j * bit_depth / 8 + k] = (unsigned char)pixel_value;
                }
            }
        }
    } else if(choice == 6) { // Decrease contrast
        float alpha = 0.6;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < bit_depth / 8; k++) {
                    int pixel_value = img_data[i * row_size + j * bit_depth / 8 + k];
                    pixel_value = (int)(alpha * (pixel_value - MAX_PIXEL_VALUE / 2) + MAX_PIXEL_VALUE / 2);
                    if (pixel_value < 0) {
                        pixel_value = 0;
                    }
                    if (pixel_value > MAX_PIXEL_VALUE) {
                        pixel_value = MAX_PIXEL_VALUE;
                    }
                    img_data[i * row_size + j * bit_depth / 8 + k] = (unsigned char)pixel_value;
                }
            }
        }
    } else { // Invalid choice
        printf("Invalid choice.\n");
        return 1;
    }

    fwrite(img_data, sizeof(unsigned char), row_size * height, output_file_ptr);

    fclose(file_ptr);
    fclose(output_file_ptr);
    free(img_data);

    printf("Output file created successfully.\n");

    return 0;
}