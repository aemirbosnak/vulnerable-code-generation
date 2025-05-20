#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];

    printf("Enter packet data: ");
    fscanf(stdin, "%s", buffer);

    // Overflow the buffer
    buffer[1024 - 1] = '\x0a';

    printf("Packet data: %s", buffer);

    return 0;
}
