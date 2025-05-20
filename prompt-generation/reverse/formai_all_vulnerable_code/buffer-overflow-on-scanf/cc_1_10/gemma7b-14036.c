//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, l, compressed_size, original_size;
    char *compressed_data;

    // Get the original data from the user
    printf("Enter the original data (separated by spaces): ");
    scanf("%s", buffer);

    // Calculate the original size of the data
    original_size = strlen(buffer) + 1;

    // Allocate memory for compressed data
    compressed_data = (char *)malloc(original_size);

    // Compress the data
    k = 0;
    for (i = 0; i < original_size - 1; i++)
    {
        int runs = 1;
        for (j = i + 1; j < original_size - 1 && buffer[i] == buffer[j]; j++)
        {
            runs++;
        }

        compressed_data[k++] = buffer[i];
        compressed_data[k++] = runs;
    }

    // Calculate the compressed size
    compressed_size = k + 1;

    // Print the compressed data
    printf("Compressed data: ");
    for (i = 0; i < compressed_size; i++)
    {
        printf("%c ", compressed_data[i]);
    }

    printf("\n");

    // Print the compressed size
    printf("Compressed size: %d", compressed_size);

    // Free the memory allocated for compressed data
    free(compressed_data);

    return 0;
}