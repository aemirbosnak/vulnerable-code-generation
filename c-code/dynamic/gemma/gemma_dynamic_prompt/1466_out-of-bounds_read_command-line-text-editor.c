#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = malloc(10);
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read data from the file, out of bounds
    int read_amount = fread(buf, 1, 100, fp);

    if (read_amount > 0)
    {
        printf("%s", buf);
    }

    fclose(fp);
    free(buf);

    return 0;
}
