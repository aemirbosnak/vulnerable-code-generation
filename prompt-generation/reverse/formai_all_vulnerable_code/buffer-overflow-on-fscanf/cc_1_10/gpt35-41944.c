//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>

// function prototype
void convertToASCII(FILE *image_file);

int main()
{
    FILE *image;
    char file_name[50];

    // prompt user to enter image file name with extension
    printf("Enter the name of the image file with extension: ");
    scanf("%s", file_name);

    // open the image file in read mode
    image = fopen(file_name, "r");
    // check if image file exists
    if (image == NULL)
    {
        printf("Error: Could not find the image file.\n");
        return 1; // return 1 indicating error
    }

    // call the function to convert image to ASCII art
    convertToASCII(image);

    // close the opened file
    fclose(image);

    return 0; // return 0 indicating success
}

// function to convert image to ASCII art
void convertToASCII(FILE *image_file)
{
    int width, height, color_depth, i, j;
    char ASCII_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    // get the width, height, and color depth
    fscanf(image_file, "%*s %d %d %d", &width, &height, &color_depth);
    int pixel_count = width * height;
    int pixels[pixel_count];

    // read the pixel values
    for (i = 0; i < pixel_count; i++)
    {
        fscanf(image_file, "%d", &pixels[i]);
    }

    // get the average brightness of the image
    int total_brightness = 0, avg_brightness;
    for (i = 0; i < pixel_count; i++)
    {
        total_brightness = total_brightness + pixels[i];
    }
    avg_brightness = total_brightness / pixel_count;

    // print the ASCII art
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // convert the pixel value to brightness value
            int brightness = pixels[i * width + j] / 255.0 * 9;

            // use the corresponding ASCII character based on brightness
            printf("%c", ASCII_chars[brightness]);
        }
        printf("\n");
    }
}