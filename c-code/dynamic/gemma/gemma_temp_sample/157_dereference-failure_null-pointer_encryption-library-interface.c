#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *ptr = NULL;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        printf("%c", ptr[i]);
    }

    return 0;
}
