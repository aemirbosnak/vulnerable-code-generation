#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[20];
    int len = 0;

    printf("Enter packet data: ");
    len = gets(buffer);

    if (len > 20)
    {
        printf("Error: Buffer overflow!\n");
    }
    else
    {
        printf("Packet data: %s\n", buffer);
    }

    return 0;
}
