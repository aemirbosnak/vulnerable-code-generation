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

    char *method = malloc(64);
    printf("Enter method (GET/POST/PUT/DELETE): ");
    scanf("%s", method);

    char *headers = malloc(2048);
    printf("Enter headers (key-value pairs):\n");
    scanf("Headers: ");
    char *header_lines = strdup(headers);

    char *body = malloc(4096);
    printf("Enter body (optional):\n");
    scanf("Body: ");
    char *body_data = strdup(body);

    free(url);
    free(method);
    free(headers);
    free(body);

    return 0;
}
