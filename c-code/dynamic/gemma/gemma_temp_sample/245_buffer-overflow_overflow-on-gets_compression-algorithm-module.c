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

    printf("Enter data: ");
    gets(buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Overflow the buffer
        buffer[i + 1] = buffer[i];
    }

    printf("Compressed data: ");
    puts(buffer);

    return 0;
}
