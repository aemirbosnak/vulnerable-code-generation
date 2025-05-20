#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    FILE *fp;

    fp = fopen("file.txt", "w");
    fscanf(fp, "%s", buffer);

    fprintf(fp, "%s", buffer);
    fclose(fp);

    return 0;
}
