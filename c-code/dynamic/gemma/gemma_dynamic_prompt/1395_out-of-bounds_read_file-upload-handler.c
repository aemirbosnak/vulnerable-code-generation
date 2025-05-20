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
    FILE *file = fopen("test.txt", "r");

    if (file)
    {
        // Read file size
        fseek(file, 0L, SEEK_END);
        size = ftell(file);

        // Allocate memory for buffer
        buffer = malloc(size);

        // Read file contents
        rewind(file);
        fread(buffer, size, 1, file);

        // Out-of-bounds read
        buffer[size] = 'A';

        // Print buffer contents
        printf("%s", buffer);

        // Free memory and close file
        free(buffer);
        fclose(file);
    }

    return 0;
}
