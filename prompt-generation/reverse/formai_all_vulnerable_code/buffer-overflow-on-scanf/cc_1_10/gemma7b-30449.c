//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void data_recovery(char *filename)
{
    FILE *fp;
    char *buffer;
    int size = 0, i;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    // Calculate file size
    while (!feof(fp))
    {
        size++;
        fseek(fp, size, SEEK_SET);
    }

    // Allocate memory for the buffer
    buffer = (char *)malloc(size);

    // Read the file into the buffer
    rewind(fp);
    fread(buffer, size, 1, fp);

    // Print the recovered data
    for (i = 0; i < size; i++)
    {
        printf("%c ", buffer[i]);
    }

    // Free the memory
    free(buffer);
    fclose(fp);
}

int main()
{
    char filename[20];

    printf("Enter the filename: ");
    scanf("%s", filename);

    data_recovery(filename);

    return 0;
}