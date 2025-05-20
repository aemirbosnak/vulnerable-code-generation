#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = malloc(1024);
    gets(buf);

    FILE *fp = fopen("test.txt", "w");
    fprintf(fp, buf);
    fclose(fp);

    return 0;
}
