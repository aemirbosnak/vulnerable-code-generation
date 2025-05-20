#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(10);
    FILE *file = fopen("secret.txt", "r");

    // Out-of-bounds read vulnerability
    fread(buffer, 1, 100, file);

    printf("%s", buffer);

    free(buffer);
    fclose(file);

    return 0;
}
