#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char *buf = NULL;
    long offset = 0;

    fp = fopen("/tmp/test.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    // Read data from file, out of bounds
    buf = (char *)malloc(offset);
    fread(buf, 1, offset, fp);

    // Free memory
    free(buf);

    fclose(fp);

    return 0;
}
