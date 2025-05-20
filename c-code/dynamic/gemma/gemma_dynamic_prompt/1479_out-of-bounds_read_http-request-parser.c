#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *url = "GET /hello?name=John&age=30&secret=topsecret";
    char *ptr = url;
    char *key = NULL;
    char *value = NULL;

    while (*ptr)
    {
        if (*ptr == '?')
        {
            key = ptr + 1;
            value = strchr(key, '=');
            if (value)
            {
                *value = '\0';
                printf("Key: %s, Value: %s\n", key, value + 1);
            }
        }
        ptr++;
    }

    return 0;
}
