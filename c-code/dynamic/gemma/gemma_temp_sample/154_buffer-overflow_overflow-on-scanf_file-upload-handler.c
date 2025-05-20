#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    scanf("%s", buffer);

    if (strlen(buffer) > 1024)
    {
        printf("Error: Buffer overflow.\n");
    }
    else
    {
        printf("File upload successful.\n");
    }

    return 0;
}
