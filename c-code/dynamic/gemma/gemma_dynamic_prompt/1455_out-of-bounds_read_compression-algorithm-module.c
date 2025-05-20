#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("test.txt", "r");
    int size = 0;
    char* data = NULL;

    // Read file size
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    rewind(file);

    // Allocate memory for data
    data = malloc(size);

    // Read file data
    fread(data, size, 1, file);

    // Out-of-bounds read
    data[size + 1] = 0x42;

    // Print data
    printf("%s", data);

    // Free memory
    free(data);
    fclose(file);

    return 0;
}
