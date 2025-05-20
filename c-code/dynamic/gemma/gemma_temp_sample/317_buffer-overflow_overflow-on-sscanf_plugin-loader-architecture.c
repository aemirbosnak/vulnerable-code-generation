#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    FILE *file = fopen("plugins.txt", "r");
    fscanf(file, "%s", buffer);
    printf("%s", buffer);
    fclose(file);
    return 0;
}
