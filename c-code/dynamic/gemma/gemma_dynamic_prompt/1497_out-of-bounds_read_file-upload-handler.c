#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char *buffer;
    long offset;

    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    buffer = malloc(1024);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        exit(1);
    }

    offset = 100000; // Out of bounds offset
    read(fp, buffer, offset);

    fclose(fp);
    free(buffer);

    return 0;
}
