#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char *str = malloc(10);
    str = NULL;

    FILE *fp = fopen("test.txt", "w");
    fprintf(fp, "Hello, world!");
    fclose(fp);

    return 0;
}
