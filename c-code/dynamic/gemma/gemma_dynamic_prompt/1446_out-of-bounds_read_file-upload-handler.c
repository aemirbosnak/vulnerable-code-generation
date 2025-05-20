#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(1024);
    FILE *file = fopen("test.txt", "r");
    size_t read_size = fread(buffer, 1, 1024, file);
    fclose(file);

    buffer[read_size - 1] = '\x0';
    printf("%s", buffer);

    free(buffer);
    return 0;
}
