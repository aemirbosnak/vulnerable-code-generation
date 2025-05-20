#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(10);
    FILE *fp = fopen("test.txt", "w");

    // Out of bounds write
    write(fp, "This is an out of bounds write", 32);

    fclose(fp);
    free(buffer);

    return 0;
}
