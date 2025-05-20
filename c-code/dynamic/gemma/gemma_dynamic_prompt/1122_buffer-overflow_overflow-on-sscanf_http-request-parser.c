#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char *ptr = NULL;
    int i = 0;

    printf("Enter an HTTP request: ");
    scanf("%s", buffer);

    ptr = strstr(buffer, "GET ");
    if (ptr)
    {
        i = atoi(ptr + 5);
        printf("GET request for file number %d\n", i);
    }
    else
    {
        printf("Error parsing request\n");
    }

    return 0;
}
