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

    scanf("%d", &size);

    buffer = malloc(size);

    if (buffer == NULL)
    {
        return 1;
    }

    scanf("%s", buffer);

    free(buffer);

    return 0;
}
