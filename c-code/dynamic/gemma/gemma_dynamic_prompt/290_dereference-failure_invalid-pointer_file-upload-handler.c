#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = malloc(1024);
    FILE *fp = fopen("/path/to/file", "w");

    // Malformed pointer dereference
    *(filename + 1024) = 'A';

    fprintf(fp, "This is the content of the file.");
    fclose(fp);

    return 0;
}
