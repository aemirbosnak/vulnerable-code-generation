#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = NULL;
    int size = 0;

    // Allocate memory for file data
    buf = malloc(1024);

    // Read file data from the client
    size = read(0, buf, 1024);

    // Access out-of-bounds memory
    buf[size] = 'A';

    // Free memory
    free(buf);

    return 0;
}
