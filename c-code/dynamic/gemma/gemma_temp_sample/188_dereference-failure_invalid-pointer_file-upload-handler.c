#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = NULL;
    FILE *fp = NULL;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file is open
    if (fp == NULL)
    {
        printf("Error opening file: %s", filename);
        exit(1);
    }

    // Read the file contents
    char *data = NULL;
    size_t size = 0;
    while ((data = (char *)realloc(data, size)) != NULL)
    {
        size_t read_size = fread(data, 1, size, fp);
        size += read_size;
    }

    // Close the file
    fclose(fp);

    // Print the file contents
    printf("File contents: \n");
    printf("%s", data);

    // Free the memory
    free(data);

    return 0;
}
