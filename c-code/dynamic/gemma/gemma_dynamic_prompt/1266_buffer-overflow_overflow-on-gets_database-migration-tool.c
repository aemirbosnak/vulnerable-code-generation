#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    gets(buffer);

    // Overflow the buffer and write arbitrary data
    buffer[1024 - 1] = 'A';
    buffer[1024 - 2] = 'B';
    buffer[1024 - 3] = 'C';

    printf("Data: %s", buffer);

    return 0;
}
