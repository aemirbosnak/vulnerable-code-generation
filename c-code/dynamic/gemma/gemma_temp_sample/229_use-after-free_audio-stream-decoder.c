#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    char *buffer = NULL;
    int size = 0;

    fp = fopen("audio.bin", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the buffer
    buffer = malloc(1024);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    size = read(fp, buffer, 1024);
    if (size == -1)
    {
        perror("Error reading file");
        exit(1);
    }

    // Play the audio data
    write(1, buffer, size);

    // Free the memory
    free(buffer);

    // Close the file
    fclose(fp);

    return 0;
}
