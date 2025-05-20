#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int len = 0;

    printf("Enter packet data: ");
    scanf("%s", buffer);

    len = strlen(buffer) + 1;

    if (len > 1024)
    {
        printf("Error: Buffer overflow.\n");
    }
    else
    {
        printf("Packet data: %s\n", buffer);
    }

    return 0;
}
