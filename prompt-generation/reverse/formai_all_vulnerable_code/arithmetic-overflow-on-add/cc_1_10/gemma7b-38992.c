//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char *data, int size)
{
    int i, j, count = 1, frequency[MAX_SIZE] = {0};
    char buffer[MAX_SIZE] = "";

    // Calculate character frequencies
    for (i = 0; i < size; i++)
    {
        frequency[data[i]]++;
    }

    // Build compressed data
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (frequency[i] > 0)
        {
            buffer[j++] = i;
            buffer[j++] = frequency[i];
        }
    }

    // Copy compressed data to original buffer
    memcpy(data, buffer, j);

    // Update the size of the compressed data
    size = j;
}

int main()
{
    char data[] = "aabbbbcccccaa";
    int size = 11;

    compress(data, size);

    printf("Compressed data: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", data[i]);
    }

    printf("\n");

    return 0;
}