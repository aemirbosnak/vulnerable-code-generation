#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int index = 0;

    printf("Enter a command: ");
    fgets(buffer, 1024, stdin);

    // Out-of-bounds read vulnerability
    index = atoi(buffer) + 10;
    if (index >= 0 && index < 1024)
    {
        printf("Content at index %d: %c\n", index, buffer[index]);
    }
    else
    {
        printf("Error: out of bounds\n");
    }

    return 0;
}
