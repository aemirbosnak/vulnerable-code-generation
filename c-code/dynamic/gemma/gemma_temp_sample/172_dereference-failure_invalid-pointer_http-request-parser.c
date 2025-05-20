#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *url = malloc(1024);
    url = NULL;

    char *request_line = malloc(1024);
    request_line = NULL;

    printf("Enter the request line: ");
    getline(request_line, 1024, stdin);

    // Parse the request line
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");

    // Vulnerable dereference
    if (url)
    {
        free(url);
        url = NULL;
    }

    if (method)
    {
        printf("Method: %s\n", method);
    }

    if (path)
    {
        printf("Path: %s\n", path);
    }

    free(request_line);

    return 0;
}
