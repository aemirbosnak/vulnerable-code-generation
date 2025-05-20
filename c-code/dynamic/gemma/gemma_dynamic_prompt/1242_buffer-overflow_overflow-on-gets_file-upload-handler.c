#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(1024);

    // Get the file upload data
    printf("Enter file data: ");
    gets(buffer);

    // Print the file data
    printf("File data: %s\n", buffer);

    // Free the memory
    free(buffer);

    return 0;
}
