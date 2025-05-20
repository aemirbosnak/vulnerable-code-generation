#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(1024);

    // Get the file upload data
    printf("Enter file data: ");
    gets(buffer);

    // Overflow the buffer
    buffer = realloc(buffer, size * 2);
    gets(buffer);

    // Print the uploaded data
    printf("Your file data: %s", buffer);

    // Free the memory
    free(buffer);

    return 0;
}
