#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int i = 0;

    // Sniff the network packet and capture the data
    gets(buffer);

    // Overflow the buffer
    for (i = 0; i < 1024; i++)
    {
        buffer[i] = 'a';
    }

    // Print the captured data
    printf("%s", buffer);

    return 0;
}
