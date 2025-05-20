#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1024];
    fgets(arr, 1024, stdin);
    char *p = arr;
    for (; *p; p++)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p = 'a';
        }
        else if (*p >= 'A' && *p <= 'Z')
        {
            *p = 'A';
        }
        else if (*p >= '0' && *p <= '9')
        {
            *p = '0';
        }
    }
    printf("%s", arr);
    return 0;
}
