#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    FILE *fp = fopen("audio.dat", "r");
    fscanf(fp, "%s", buffer);
    printf("%s", buffer);
    fclose(fp);
    return 0;
}
