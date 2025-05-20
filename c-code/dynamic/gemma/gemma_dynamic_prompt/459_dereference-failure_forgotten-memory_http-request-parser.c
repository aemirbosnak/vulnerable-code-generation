#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *buf = malloc(1024);
    int len = 0;

    // Read the request header
    printf("Enter header: ");
    scanf("%s", buf);

    // Allocate memory for the request body
    buf = realloc(buf, len + 1);

    // Read the request body
    printf("Enter body: ");
    scanf("%s", buf);

    // Print the request header and body
    printf("Header: %s\n", buf);
    printf("Body: %s\n", buf);

    free(buf);
    return 0;
}
