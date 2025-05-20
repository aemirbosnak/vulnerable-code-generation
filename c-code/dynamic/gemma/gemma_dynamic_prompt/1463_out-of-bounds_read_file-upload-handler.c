#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = NULL;
    char *buffer = NULL;
    long int size = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    // Allocate memory for the buffer
    buffer = malloc(size);
    if (buffer == NULL)
    {
        printf("Error allocating memory.\n");
        fclose(fp);
        exit(1);
    }

    // Read the file into the buffer
    fread(buffer, size, 1, fp);

    // Close the file
    fclose(fp);

    // Print the file contents
    printf("File contents:\n");
    printf("%s", buffer);

    // Free the memory
    free(buffer);

    return 0;
}
