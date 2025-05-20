#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    int len = 0;

    printf("Enter HTTP request: ");
    fgets(buf, 1024, stdin);

    len = strlen(buf);

    if (len > 1024)
    {
        printf("Error: Request too large.\n");
    }
    else
    {
        printf("Request: %s\n", buf);
    }

    return 0;
}
