//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

// Function to flip the image horizontally
void flip_horizontally(BYTE *image_data, int width, int height)
{
    int i, j;
    BYTE *temp_row = malloc(sizeof(BYTE) * width);

    for (i = 0; i < height; ++i)
    {
        for (j = 0; j < width/2; ++j)
        {
            temp_row[j] = image_data[i * width + j];
            image_data[i * width + j] = image_data[(i + 1) * width - j - 1];
            image_data[(i + 1) * width - j - 1] = temp_row[j];
        }
    }
    free(temp_row);
}

// Function to adjust brightness and contrast
void adjust_brightness_contrast(BYTE *image_data, int width, int height, int brightness, int contrast)
{
    int pixel_value;
    double contrast_factor = (259.0 * (contrast + 255)) / (255.0 * (259 - contrast));

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            pixel_value = image_data[i * width + j] + brightness;
            pixel_value = (int)(contrast_factor * (pixel_value - 128) + 128);

            if (pixel_value < 0)
            {
                pixel_value = 0;
            }
            else if (pixel_value > 255)
            {
                pixel_value = 255;
            }

            image_data[i * width + j] = (BYTE)pixel_value;
        }
    }
}

int main()
{
    FILE *fptr;
    char filename[20];
    int width, height, brightness, contrast;
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Opening the file
    fptr = fopen(filename, "rb");
    if (fptr == NULL)
    {
        printf("Error opening the file!\n");
        exit(1);
    }

    // Reading the image header
    BYTE header[54];
    fread(header, sizeof(BYTE), 54, fptr);

    // Reading the image width and height
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    // Calculating the image data size
    int data_size = width * height * 3;

    // Allocating memory for the image data
    BYTE *image_data = (BYTE*)malloc(sizeof(BYTE) * data_size);

    // Reading the image data
    fread(image_data, sizeof(BYTE), data_size, fptr);

    // Closing the file
    fclose(fptr);

    printf("\n1. Flip the image horizontally\n");
    printf("2. Adjust brightness and contrast\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1: // Flipping the image horizontally
            flip_horizontally(image_data, width, height);
            break;
        
        case 2: // Adjusting brightness and contrast
            printf("\nEnter the brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            printf("Enter the contrast value (-255 to 255): ");
            scanf("%d", &contrast);
            adjust_brightness_contrast(image_data, width, height, brightness, contrast);
            break;

        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    // Creating a new file to save the modified image
    FILE *new_fptr;
    new_fptr = fopen("modified_image.bmp", "wb");
    if (new_fptr == NULL)
    {
        printf("Error creating the new file!\n");
        exit(1);
    }

    // Writing the image header
    fwrite(header, sizeof(BYTE), 54, new_fptr);

    // Writing the modified image data
    fwrite(image_data, sizeof(BYTE), data_size, new_fptr);

    // Closing the file
    fclose(new_fptr);

    // Freeing the memory
    free(image_data);

    printf("Image processing completed successfully!\n");
    return 0;
}