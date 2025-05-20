#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("test.txt", "r");
    char *buffer = NULL;
    long offset = 0;

    buffer = malloc(1024);

    // Read data from file at an offset beyond the file size
    fread(buffer, 1, 1024, fp);

    printf("Data read from file at offset %ld: %s", offset, buffer);

    fclose(fp);
    free(buffer);

    return 0;
}
