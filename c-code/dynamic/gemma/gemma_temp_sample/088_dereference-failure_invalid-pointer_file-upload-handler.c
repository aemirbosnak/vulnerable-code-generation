#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    FILE *fp = fopen("/tmp/test.txt", "w");

    if (fp)
    {
        fprintf(fp, "Hello, world!");
        fclose(fp);
    }

    ptr = (char *)fp; // Invalid pointer dereference

    if (ptr)
    {
        free(ptr);
    }

    return 0;
}
