//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 25

// Function Prototypes
void flip_image(unsigned char *image_data, int width, int height, int channels);
void adjust_brightness_contrast(unsigned char *image_data, int width, int height, int channels, int brightness, int contrast);

int main() 
{
    char filename[MAX_FILENAME_LENGTH];
    unsigned char *image_data;
    int width, height, channels;
    int choice, brightness, contrast;

    printf("Enter the image filename: ");
    scanf("%s", filename);

    FILE *fileptr;
    fileptr = fopen(filename, "rb"); // Open the file for reading in binary mode

    if (fileptr == NULL) // Check if the file was opened successfully
    {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    unsigned char header[54]; // BMP files are 54 bytes long (header)
    fread(header, sizeof(unsigned char), 54, fileptr); // Read the header into memory

    // Extract image metadata from the header
    width = *(int *)&header[18];
    height = *(int *)&header[22];
    channels = *(int *)&header[28];

    int padding_size = (4 - (width * channels) % 4) % 4; // BMP files have padded rows

    // Allocate memory to store the image data
    image_data = (unsigned char *)malloc(width * height * channels * sizeof(unsigned char));

    fread(image_data, sizeof(unsigned char), width * height * channels, fileptr); // Read the image data into memory

    fclose(fileptr); // Close the file

    printf("Select an image processing task:\n");
    printf("1. Flip Image\n");
    printf("2. Adjust Brightness and Contrast\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            flip_image(image_data, width, height, channels);
            printf("Image flipped.\n");
            break;

        case 2:
            printf("Enter the brightness adjustment value (-255 to 255): ");
            scanf("%d", &brightness);
            printf("Enter the contrast adjustment value (-255 to 255): ");
            scanf("%d", &contrast);
            adjust_brightness_contrast(image_data, width, height, channels, brightness, contrast);
            printf("Brightness and contrast adjusted.\n");
            break;
        
        default:
            printf("Error: Invalid choice.\n");
            return 1;
    }

    // Create a new file to write the modified image data to
    char new_filename[MAX_FILENAME_LENGTH];
    strcpy(new_filename, "modified_");
    strcat(new_filename, filename);
    FILE *new_fileptr;
    new_fileptr = fopen(new_filename, "wb"); // Create a new file for writing in binary mode

    // Write the header and image data to the new file
    fwrite(header, sizeof(unsigned char), 54, new_fileptr);
    fwrite(image_data, sizeof(unsigned char), width * height * channels, new_fileptr);

    fclose(new_fileptr); // Close the new file
    free(image_data); // Free the memory allocated to store the image data

    return 0;
}

void flip_image(unsigned char *image_data, int width, int height, int channels)
{
    unsigned char temp;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width / 2; col++)
        {
            for (int channel = 0; channel < channels; channel++)
            {
                temp = *(image_data + (row * width + col * channels + channel));
                *(image_data + (row * width + col * channels + channel)) = *(image_data + (row * width + (width - col - 1) * channels + channel));
                *(image_data + (row * width + (width - col - 1) * channels + channel)) = temp;
            }
        }
    }
}

void adjust_brightness_contrast(unsigned char *image_data, int width, int height, int channels, int brightness, int contrast)
{
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            for (int channel = 0; channel < channels; channel++)
            {
                int pixel_value = *(image_data + (row * width + col * channels + channel));

                // Adjust brightness
                pixel_value += brightness;

                // Adjust contrast
                pixel_value = (int)(factor * (pixel_value - 128) + 128);

                // Ensure pixel value is within valid range (0-255)
                if (pixel_value < 0)
                {
                    pixel_value = 0;
                }
                else if (pixel_value > 255)
                {
                    pixel_value = 255;
                }
                
                *(image_data + (row * width + col * channels + channel)) = (unsigned char)pixel_value;
            }
        }
    }
}