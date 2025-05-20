#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *url = malloc(1024);
    scanf("Enter URL: ", url);

    int length = strlen(url) + 1;
    char *headers = malloc(length);
    headers[0] = '\0';

    char **parts = malloc(length);
    parts[0] = NULL;

    char *ptr = url;
    char *part = NULL;
    int i = 0;

    while (*ptr)
    {
        if (*ptr == '/')
        {
            part = malloc(length);
            memcpy(part, ptr, strlen(ptr) - 1);
            parts[i++] = part;
            part = NULL;
        }
        ptr++;
    }

    free(url);
    free(headers);
    free(parts);

    return 0;
}
