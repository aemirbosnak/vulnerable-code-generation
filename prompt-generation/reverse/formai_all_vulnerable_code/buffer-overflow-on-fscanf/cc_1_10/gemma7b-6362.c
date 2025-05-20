//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the pixel art converter!\n");

    // Get the image file name from the user
    char filename[256];
    printf("Enter the image file name: ");
    scanf("%s", filename);

    // Open the image file
    FILE* file = fopen(filename, "r");

    // Check if the file is open
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Get the image file size
    int width = 0;
    int height = 0;
    fscanf(file, "%d %d", &width, &height);

    // Allocate memory for the ASCII art
    char* ascii_art = malloc(width * height);

    // Read the image file data
    int i = 0;
    while (!feof(file))
    {
        unsigned char pixel = fgetc(file);
        ascii_art[i++] = pixel;
    }

    // Convert the image file data into ASCII art
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_value = ascii_art[y * width + x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("o ");
                    break;
                default:
                    printf("Error ");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    free(ascii_art);

    // Close the image file
    fclose(file);

    // Thank the user
    printf("Thank you for using the pixel art converter!\n");

    return 0;
}