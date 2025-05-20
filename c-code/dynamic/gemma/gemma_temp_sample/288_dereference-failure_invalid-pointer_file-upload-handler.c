#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    FILE *fp = fopen("/path/to/file.txt", "r");

    if (fp)
    {
        // Invalid pointer dereference
        *ptr = fgets(ptr, 1024, fp);
        fclose(fp);
    }

    return 0;
}
