#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = malloc(10);
    FILE *fp = fopen("test.txt", "w");

    // Out of bounds write vulnerability
    buf[10] = 'a';

    fwrite(buf, 11, 1, fp);
    fclose(fp);

    free(buf);

    return 0;
}
