//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    puts("Enter file name to edit: ");
    scanf("%s", filename);

    FILE *file_ptr;
    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL)
    {
        printf("File '%s' not found\n", filename);
        return 1;
    }

    printf("Editing file '%s'\n", filename);

    // read in image dimensions
    int width, height, max_pixel_value;
    fscanf(file_ptr, "P3\n%d %d\n%d\n", &width, &height, &max_pixel_value);

    // allocate memory for pixel storage
    int pixel_count = width * height * 3;
    int *image = malloc(sizeof(int) * pixel_count);

    // read in pixel data
    for (int i = 0; i < pixel_count; i++)
    {
        fscanf(file_ptr, "%d", &image[i]);
    }

    fclose(file_ptr);

    // perform image manipulation
    for (int i = 0; i < pixel_count; i++)
    {
        // invert the colors of each pixel
        image[i] = max_pixel_value - image[i];
    }

    // write out new image to file
    char output_filename[MAX_FILENAME_LENGTH + 7] = "edited_";
    strcat(output_filename, filename);
    file_ptr = fopen(output_filename, "w");

    if (file_ptr == NULL)
    {
        printf("Failed to create output file\n");
        return 1;
    }

    fprintf(file_ptr, "P3\n%d %d\n%d\n", width, height, max_pixel_value);
    for (int i = 0; i < pixel_count; i++)
    {
        fprintf(file_ptr, "%d ", image[i]);
        if ((i + 1) % 3 == 0)
        {
            fprintf(file_ptr, "\n");
        }
    }

    fclose(file_ptr);

    printf("Edited image has been saved to file '%s'\n", output_filename);

    free(image);

    return 0;
}