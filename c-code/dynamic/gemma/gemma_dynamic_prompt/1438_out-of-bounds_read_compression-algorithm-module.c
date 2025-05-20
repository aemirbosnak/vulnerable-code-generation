#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(10);
    FILE *file = fopen("test.txt", "r");

    // Out-of-bounds read vulnerability
    fread(buffer, 1, 20, file);

    fclose(file);
    free(buffer);

    return 0;
}
