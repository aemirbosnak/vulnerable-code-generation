#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buf = malloc(1024);

    // Read the file contents from the client
    FILE *fp = fopen("test.txt", "r");
    if (fp)
    {
        size = fread(buf, 1, 1024, fp);
    }

    // Out-of-bounds read
    buf[size] = 'A';

    // Free the memory and close the file
    free(buf);
    fclose(fp);

    return 0;
}
