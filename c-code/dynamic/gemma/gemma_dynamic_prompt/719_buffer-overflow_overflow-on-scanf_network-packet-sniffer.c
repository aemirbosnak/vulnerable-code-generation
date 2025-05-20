#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter packet data: ");
    scanf("%s", buffer);

    // Overflow the buffer
    buffer[1024 - 1] = '\x0A';

    // Print the packet data
    printf("Packet data: %s", buffer);

    return 0;
}
