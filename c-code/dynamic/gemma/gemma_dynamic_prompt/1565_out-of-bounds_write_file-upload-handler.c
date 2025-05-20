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

    // Out-of-bounds write vulnerability
    fwrite(buffer, 1, 20, fp);

    fclose(fp);
    free(buffer);

    return 0;
}
