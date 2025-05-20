//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100

//Function Declarations
void flip_image(unsigned char *image_data, int height, int width, int channels);
void change_brightness(unsigned char *image_data, int height, int width, int channels, int brightness_value);
void change_contrast(unsigned char *image_data, int height, int width, int channels, float contrast_value);

//Main function
int main()
{
    char file_name[MAX_FILE_NAME];
    printf("Enter the name of the input file: ");
    scanf("%s", file_name);

    //Opening the input file
    FILE *image_file = fopen(file_name, "rb");

    if (image_file == NULL) {
        printf("Error: Could not open file.");
        return -1;
    }

    int height, width, channels;
    unsigned char *image_data;
    char buffer[16];

    //Reading the header information from input file
    fscanf(image_file, "%*s %d %d %d", &width, &height, &channels);

    if (channels != 3) {
        printf("Error: Input file must be color image.");
        return -1;
    }

    printf("Enter the task to perform on the input image:\n");
    printf("1. Flip image horizontally\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");

    int task;
    scanf("%d", &task);

    //Reading the image data from input file
    image_data = (unsigned char*) malloc(height * width * channels);
    fread(image_data, sizeof(unsigned char), height * width * channels, image_file);
    fclose(image_file);

    switch (task) {
        case 1:
            flip_image(image_data, height, width, channels);
            break;
        case 2:
            printf("Enter the brightness value (between -255 to 255): ");
            int brightness_value;
            scanf("%d", &brightness_value);
            change_brightness(image_data, height, width, channels, brightness_value);
            break;
        case 3:
            printf("Enter the contrast value (between 0.1 to 10.0): ");
            float contrast_value;
            scanf("%f", &contrast_value);
            change_contrast(image_data, height, width, channels, contrast_value);
            break;
        default:
            printf("Error: Invalid task selected.");
            free(image_data);
            return -1;
    }

    //Creating the output file name
    char output_file_name[MAX_FILE_NAME];
    sprintf(output_file_name, "output_%s", file_name);

    //Opening the output file
    FILE *output_file = fopen(output_file_name, "wb");

    if (output_file == NULL) {
        printf("Error: Could not create output file.");
        free(image_data);
        return -1;
    }

    //Writing the header information to output file
    fprintf(output_file, "P6\n%d %d\n255\n", width, height);

    //Writing the modified image data to output file
    fwrite(image_data, sizeof(unsigned char), height * width * channels, output_file);
    fclose(output_file);
    free(image_data);

    printf("Output file generated successfully.");

    return 0;
}

//Function definitions

//Function to flip the image horizontally
void flip_image(unsigned char *image_data, int height, int width, int channels)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            for (int c = 0; c < channels; c++) {
                unsigned char temp = image_data[i * width * channels + j * channels + c];
                image_data[i * width * channels + j * channels + c] = image_data[i * width * channels + (width - j - 1) * channels + c];
                image_data[i * width * channels + (width - j - 1) * channels + c] = temp;
            }
        }
    }
}

//Function to change the brightness of the image
void change_brightness(unsigned char *image_data, int height, int width, int channels, int brightness_value)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int c = 0; c < channels; c++) {
                int pixel_index = i * width * channels + j * channels + c;
                int pixel_value = (int) image_data[pixel_index];
                pixel_value += brightness_value;
                if (pixel_value > 255) {
                    pixel_value = 255;
                } else if (pixel_value < 0) {
                    pixel_value = 0;
                }
                image_data[pixel_index] = (unsigned char) pixel_value;
            }
        }
    }
}

//Function to change the contrast of the image
void change_contrast(unsigned char *image_data, int height, int width, int channels, float contrast_value)
{
    float factor = (259 * (contrast_value + 255)) / (255 * (259 - contrast_value));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int c = 0; c < channels; c++) {
                int pixel_index = i * width * channels + j * channels + c;
                float pixel_value = (float) image_data[pixel_index];
                pixel_value = factor * (pixel_value - 128) + 128;
                if (pixel_value > 255) {
                    pixel_value = 255;
                } else if (pixel_value < 0) {
                    pixel_value = 0;
                }
                image_data[pixel_index] = (unsigned char) pixel_value;
            }
        }
    }
}