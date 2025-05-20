#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* buffer = NULL;
    buffer = (char*)malloc(10);
    if (buffer == NULL)
    {
        exit(1);
    }

    // This line intentionally causes a dereference failure
    int value = *(buffer + 10);

    free(buffer);
    return 0;
}
