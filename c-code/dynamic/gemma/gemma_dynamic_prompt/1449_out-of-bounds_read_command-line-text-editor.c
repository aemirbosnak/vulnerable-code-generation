#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(1024);
    FILE *file = fopen("test.txt", "w");

    // Write data to the file
    fprintf(file, "Hello, world!");

    // Read data from the file
    int offset = 1000;
    read(file, buffer, offset);

    // Print the data
    printf("%s", buffer);

    free(buffer);
    fclose(file);

    return 0;
}
