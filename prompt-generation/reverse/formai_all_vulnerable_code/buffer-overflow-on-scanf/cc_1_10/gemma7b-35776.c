//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void image_editor(int **arr, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            int pixel_value = arr[r][c];
            int avg_value = (pixel_value - 128) / 2;
            arr[r][c] = 128 + avg_value * 2;
        }
    }
}

int main()
{
    int w, h;
    scanf("Enter the width of the image: ", &w);
    scanf("Enter the height of the image: ", &h);

    int **arr = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        arr[i] = (int *)malloc(w * sizeof(int));
    }

    // Read the pixel values from the image
    printf("Enter the pixel values of the image (separated by commas): ");
    char input[1000];
    scanf("%s", input);

    // Convert the input into an array of integers
    int pixel_values[1000];
    char *p = input;
    int i = 0;
    while (*p)
    {
        pixel_values[i++] = atoi(p);
        p += 2;
    }

    // Apply the image editor function
    image_editor(arr, w, h);

    // Write the pixel values of the edited image to the console
    printf("The pixel values of the edited image are:");
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf(", %d", arr[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the image
    for (int i = 0; i < h; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}