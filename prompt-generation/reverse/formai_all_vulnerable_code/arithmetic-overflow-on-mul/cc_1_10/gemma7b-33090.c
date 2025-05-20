//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int img_width, img_height;
    scanf("Enter image width: ", &img_width);
    scanf("Enter image height: ", &img_height);

    // Allocate memory for the image data
    int *img_data = malloc(img_width * img_height * sizeof(int));

    // Read the image data
    printf("Enter image data (separated by commas): ");
    char *img_data_str = malloc(1024);
    fgets(img_data_str, 1024, stdin);
    char *img_data_tokens = strtok(img_data_str, ",");

    // Convert the image data to integers
    int i = 0;
    for (img_data_tokens; *img_data_tokens; img_data_tokens++)
    {
        img_data[i++] = atoi(*img_data_tokens);
    }

    // Convert the image data to ASCII art
    int y = 0;
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            int pixel_value = img_data[y * img_width + w];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("·");
                    break;
                case 2:
                    printf("○");
                    break;
                case 3:
                    printf("█");
                    break;
            }
        }
        printf("\n");
        y++;
    }

    // Free memory
    free(img_data);
    free(img_data_str);

    return 0;
}