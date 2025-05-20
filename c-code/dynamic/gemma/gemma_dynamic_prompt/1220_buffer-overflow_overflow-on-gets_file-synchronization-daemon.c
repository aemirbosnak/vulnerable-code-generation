#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    gets(buffer); // Overflow on gets

    size = strlen(buffer) + 1;
    buffer = realloc(buffer, size);

    printf("The updated buffer is: %s\n", buffer);

    free(buffer);

    return 0;
}
