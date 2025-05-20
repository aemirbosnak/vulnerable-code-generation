//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    int i, j, size, original_size, compressed_size, data[MAX_SIZE], compressed_data[MAX_SIZE];

    printf("Enter the size of the data: ");
    scanf("%d", &size);

    original_size = size;

    printf("Enter the data: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    compressed_size = compress(data, size, compressed_data);

    printf("The compressed data is: ");
    for (i = 0; i < compressed_size; i++)
    {
        printf("%d ", compressed_data[i]);
    }

    printf("\nThe compressed size is: %d", compressed_size);

    printf("\nThe original size is: %d", original_size);

    return 0;
}

int compress(int *data, int size, int *compressed_data)
{
    int i, j, count = 0, compressed_size = 0, unique_data[MAX_SIZE], frequency[MAX_SIZE];

    for (i = 0; i < size; i++)
    {
        unique_data[i] = data[i];
    }

    for (i = 0; i < size; i++)
    {
        frequency[unique_data[i]]++;
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (frequency[i] > 1)
        {
            compressed_data[count++] = i;
            compressed_data[count++] = frequency[i] - 1;
        }
    }

    compressed_size = count;

    return compressed_size;
}