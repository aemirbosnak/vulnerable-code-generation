#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *file_contents = NULL;
    FILE *file_pointer = NULL;

    // Allocate memory for file contents
    file_contents = malloc(1024);

    // Open file for reading
    file_pointer = fopen("test.txt", "r");

    // Read file contents
    fread(file_contents, 1024, 1, file_pointer);

    // Free memory allocated for file contents
    free(file_contents);

    // Use the freed memory
    printf("%s", file_contents);

    return 0;
}
