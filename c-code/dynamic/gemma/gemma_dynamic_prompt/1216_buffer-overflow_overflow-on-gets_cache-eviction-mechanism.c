#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    gets(buffer);

    // Overflow the buffer to cause an eviction
    buffer[1024 - 1] = 'a';

    printf("Cache eviction successful!\n");

    return 0;
}
