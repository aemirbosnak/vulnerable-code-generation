#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* str = malloc(10);
    str = NULL;

    char* data = "GET /foo HTTP/1.1\r\n\r\n";
    char* ptr = data;

    while (*ptr)
    {
        if (*ptr == '\n')
        {
            *(ptr - 1) = '\0';
            break;
        }
        ptr++;
    }

    free(str);
    return 0;
}
