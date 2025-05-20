#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int offset = 0;
    char buffer[1024];

    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Out-of-bounds read
    fseek(fp, offset, SEEK_SET);
    fread(buffer, 1, 1024, fp);

    fclose(fp);

    printf("Read data: %s", buffer);

    return 0;
}
