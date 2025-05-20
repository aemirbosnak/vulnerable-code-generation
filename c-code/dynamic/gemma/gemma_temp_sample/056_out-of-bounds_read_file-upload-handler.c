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
    FILE *fp = NULL;

    // Open file
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read file contents
    buf = malloc(size);
    size = fread(buf, 1, size, fp);

    // Out-of-bounds read
    buf[size] = 'A';

    // Close file
    fclose(fp);

    // Free memory
    free(buf);

    return 0;
}
