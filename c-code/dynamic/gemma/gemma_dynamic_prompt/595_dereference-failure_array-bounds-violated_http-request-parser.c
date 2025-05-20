#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *url = "GET /foo?bar[]=baz&bam[]=boom";
    char **headers = NULL;
    int num_headers = 0;

    // Allocate memory for headers
    headers = malloc(1024);

    // Parse the URL
    char *ptr = url;
    char *key, *value;
    while (*ptr)
    {
        key = strchr(ptr, '=');
        value = strchr(key, '&');

        // Allocate memory for header key and value
        headers[num_headers] = malloc(strlen(key) + 1);
        memcpy(headers[num_headers], key, strlen(key) + 1);

        num_headers++;

        if (value)
        {
            headers[num_headers] = malloc(strlen(value) + 1);
            memcpy(headers[num_headers], value, strlen(value) + 1);
            num_headers++;
        }

        ptr = value ? value + 1 : ptr + 1;
    }

    // Print the headers
    for (int i = 0; i < num_headers; i++)
    {
        printf("%s: %s\n", headers[i], headers[i + 1]);
    }

    // Free the allocated memory
    for (int i = 0; i < num_headers; i++)
    {
        free(headers[i]);
    }
    free(headers);

    return 0;
}
