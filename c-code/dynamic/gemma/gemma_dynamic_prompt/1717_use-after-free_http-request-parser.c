#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char* str = malloc(1024);
    gets(str);

    char* ptr = str;
    while (*ptr)
    {
        if (*ptr == ' ' || *ptr == '\n' || *ptr == '\r')
        {
            *ptr = '\0';
        }
        ptr++;
    }

    printf("%s", str);

    free(str);

    return 0;
}
