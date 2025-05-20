#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    FILE *fp = fopen("cache.txt", "r");
    fscanf(fp, "%s", buffer);
    printf("%s", buffer);
    fclose(fp);

    return 0;
}
