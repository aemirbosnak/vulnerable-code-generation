//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **data, int **size)
{
    int i, j, k, count = 0, run_length = 1;
    char previous = '\0';

    for (i = 0; i < *size; i++)
    {
        if (previous == data[i])
        {
            run_length++;
        }
        else
        {
            if (run_length > 1)
            {
                for (j = 0; j < run_length - 1; j++)
                {
                    data[k++] = count - 1;
                }
            }
            previous = data[i];
            run_length = 1;
            count++;
        }
    }

    *size = k;
}

int main()
{
    char **data = NULL;
    int size = 0, original_size = 0;

    // Get the original data size
    printf("Enter the original data size: ");
    scanf("%d", &original_size);

    // Allocate memory for the data
    data = malloc(original_size);

    // Get the original data
    printf("Enter the original data: ");
    scanf("%s", data);

    // Compress the data
    compress(data, &size);

    // Print the compressed data size
    printf("The compressed data size is: %d", size);

    // Print the compressed data
    printf("The compressed data is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}