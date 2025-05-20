//FormAI DATASET v1.0 Category: Image compression ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Function to compress a given image using RLE-based compression */
void imageCompression(int *imageArray, int size)
{
    int i, j, count;

    /* Loop through the image array */
    for (i = 0; i < size; i++)
    {
        count = 1;

        /* If the current pixel is the same as the next pixel, increment the counter */
        while ((i + 1 < size) && (imageArray[i] == imageArray[i + 1]))
        {
            count++;
            i++;
        }

        /* Print the pixel and its count */
        printf("%d %d ", imageArray[i], count);
    }
}

/* Driver code */
int main()
{
    int i, n, *imageArray;

    /* Get the number of pixels and allocate memory for the image array */
    printf("Enter the number of pixels in the image: ");
    scanf("%d", &n);

    imageArray = (int *) malloc(n * sizeof(int));

    /* Get the pixel values */
    for (i = 0; i < n; i++)
    {
        printf("Enter value of pixel %d: ", i + 1);
        scanf("%d", &imageArray[i]);
    }

    /* Compress the image using RLE-based compression */
    printf("Compressed image: ");
    imageCompression(imageArray, n);

    /* Free the memory allocated for the image array */
    free(imageArray);

    return 0;
}