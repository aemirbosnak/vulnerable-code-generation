//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
void image_to_ascii(char *filename, int threshold)
{
    // Open the image file in binary mode
    FILE *fp = fopen(filename, "rb");

    // Handle opening errors
    if (fp == NULL)
    {
        printf("Error: could not open image file!\n");
        exit(1);
    }

    // Determine the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the image data
    char *image_data = (char *) malloc(file_size);
    if (image_data == NULL)
    {
        printf("Error: memory allocation failed!\n");
        exit(1);
    }

    // Read the image data into memory
    fread(image_data, sizeof(char), file_size, fp);

    // Close the image file
    fclose(fp);

    // Determine the image dimensions
    int width = *(int *) (image_data + 18);
    int height = *(int *) (image_data + 22);
    int bpp = *(short *) (image_data + 28);

    printf("Image dimensions: %d x %d\n", width, height);

    // Set the number of pixels per character
    int pixels_per_char = 4;

    // Compute the ASCII art dimensions
    int ascii_width = width / pixels_per_char;
    int ascii_height = height / pixels_per_char;

    // Allocate memory for the ASCII art
    char *ascii_art = (char *) calloc(ascii_width * ascii_height + 1, sizeof(char));
    if (ascii_art == NULL)
    {
        printf("Error: memory allocation failed!\n");
        exit(1);
    }

    // Loop through each pixel and compute the corresponding ASCII character
    for (int y = 0; y < ascii_height; y++)
    {
        for (int x = 0; x < ascii_width; x++)
        {
            int sum = 0;

            for (int i = 0; i < pixels_per_char; i++)
            {
                for (int j = 0; j < pixels_per_char; j++)
                {
                    int pixel_index = ((y * pixels_per_char + i) * width + (x * pixels_per_char + j)) * bpp / 8;

                    // Compute the pixel intensity
                    int intensity = (int) ((unsigned char) image_data[pixel_index] +
                                           (unsigned char) image_data[pixel_index + 1] +
                                           (unsigned char) image_data[pixel_index + 2]) / 3;

                    sum += intensity;
                }
            }

            // Compute the average intensity for the pixel
            int avg_intensity = sum / (pixels_per_char * pixels_per_char);

            // Choose the ASCII character based on the intensity
            char ascii_char;

            if (avg_intensity >= threshold)
            {
                ascii_char = '.';
            }
            else if (avg_intensity >= threshold - 20)
            {
                ascii_char = ':';
            }
            else if (avg_intensity >= threshold - 40)
            {
                ascii_char = '+';
            }
            else if (avg_intensity >= threshold - 60)
            {
                ascii_char = '*';
            }
            else if (avg_intensity >= threshold - 80)
            {
                ascii_char = '#';
            }
            else
            {
                ascii_char = '@';
            }

            ascii_art[y * ascii_width + x] = ascii_char;
        }
    }

    // Print the ASCII art to the console
    printf("%s\n", ascii_art);

    // Save the ASCII art to a file
    char *output_filename = (char *) malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".txt");

    // Open the output file in write mode
    FILE *output_fp = fopen(output_filename, "w");

    // Handle opening errors
    if (output_fp == NULL)
    {
        printf("Error: could not open output file!\n");
        exit(1);
    }

    // Write the ASCII art to the file
    fwrite(ascii_art, sizeof(char), ascii_width * ascii_height, output_fp);

    // Close the output file
    fclose(output_fp);

    printf("ASCII art saved to %s\n", output_filename);

    // Free the memory
    free(image_data);
    free(ascii_art);
    free(output_filename);
}

int main(int argc, char **argv)
{
    // Check for the correct number of command-line arguments
    if (argc < 2 || argc > 3)
    {
        printf("Usage: %s <image file> [threshold]\n", argv[0]);
        exit(1);
    }

    // Get the filename and threshold from the command-line arguments
    char *filename = argv[1];
    int threshold = argc == 3 ? atoi(argv[2]) : 128;

    // Convert the image to ASCII art
    image_to_ascii(filename, threshold);

    return 0;
}