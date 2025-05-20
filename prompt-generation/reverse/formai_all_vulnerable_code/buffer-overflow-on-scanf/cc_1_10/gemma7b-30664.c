//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    int i, j, k, l, n, count = 0, original_size = 0, compressed_size = 0;
    char *original_data, *compressed_data;

    // Allocate memory for original and compressed data
    original_data = (char *)malloc(MAX_SIZE);
    compressed_data = (char *)malloc(MAX_SIZE);

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the original data from the user
    printf("Enter the original data: ");
    for (i = 0; i < n; i++)
    {
        scanf("%c", &original_data[i]);
    }

    // Calculate the original size of the data
    original_size = n;

    // Compress the data
    for (i = 0; i < n; i++)
    {
        char current_char = original_data[i];
        int frequency = 0;

        for (j = 0; j < n; j++)
        {
            if (current_char == original_data[j])
            {
                frequency++;
            }
        }

        if (frequency > 1)
        {
            compressed_data[count] = current_char;
            compressed_data[count + 1] = frequency;
            count++;
        }
        else
        {
            compressed_data[count] = current_char;
            count++;
        }
    }

    // Calculate the compressed size of the data
    compressed_size = count;

    // Print the compressed data
    printf("Compressed data: ");
    for (i = 0; i < compressed_size; i++)
    {
        printf("%c ", compressed_data[i]);
    }

    // Print the original size and compressed size
    printf("\nOriginal size: %d", original_size);
    printf("\nCompressed size: %d", compressed_size);

    // Free the allocated memory
    free(original_data);
    free(compressed_data);

    return 0;
}