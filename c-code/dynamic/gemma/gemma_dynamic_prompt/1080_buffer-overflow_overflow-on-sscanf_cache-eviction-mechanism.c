#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int size = 0;
    FILE *fp = fopen("cache.txt", "r");

    fscanf(fp, "%s", buffer);
    size = strlen(buffer);

    printf("Cache eviction mechanism:\n");
    printf("-------------------\n");
    printf("Size of buffer: %d\n", size);
    printf("Content of buffer: %s\n", buffer);

    fclose(fp);

    return 0;
}
