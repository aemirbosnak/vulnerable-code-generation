#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buf = malloc(size);

    // Read the file data
    FILE *fp = fopen("test.txt", "r");
    int read_size = fread(buf, 1, 1024, fp);

    // Write the file data out of bounds
    buf[read_size] = 'A';

    // Free the memory
    free(buf);

    return 0;
}
