#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    FILE *file = fopen("test.txt", "w");

    // Write beyond the allocated memory
    buffer[1024] = 'a';

    fprintf(file, "%s", buffer);
    fclose(file);

    free(buffer);

    return 0;
}
