#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("/path/to/file", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char *buf = NULL;
    buf = (char *)malloc(1024);
    if (buf == NULL)
    {
        perror("Error allocating memory");
        fclose(fp);
        exit(1);
    }

    int read_size = fread(buf, 1, 1024, fp);
    if (read_size > 0)
    {
        printf("File data: %s", buf);
    }

    fclose(fp);
    free(buf);

    return 0;
}
