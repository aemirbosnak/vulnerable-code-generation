//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, n, count = 0, original_size = 0, compressed_size = 0;

    printf("Enter the number of characters you want to compress: ");
    scanf("%d", &n);

    printf("Enter the characters: ");
    for (i = 0; i < n; i++)
    {
        buffer[i] = getchar();
        original_size++;
    }

    // Compress the data
    for (i = 0; i < n - 1; i++)
    {
        int frequency = 0;
        for (j = i; j < n && buffer[j] == buffer[i]; j++)
        {
            frequency++;
        }

        if (frequency > 1)
        {
            buffer[i] = buffer[i] - 32;
            compressed_size++;
            count++;
        }
    }

    // Print the compressed data
    printf("Compressed data: ");
    for (i = 0; i < n; i++)
    {
        printf("%c", buffer[i]);
    }

    // Print the number of characters compressed
    printf("\nNumber of characters compressed: %d", count);

    // Calculate the compressed size
    compressed_size = original_size - count;

    // Print the compressed size
    printf("\nCompressed size: %d", compressed_size);

    return 0;
}