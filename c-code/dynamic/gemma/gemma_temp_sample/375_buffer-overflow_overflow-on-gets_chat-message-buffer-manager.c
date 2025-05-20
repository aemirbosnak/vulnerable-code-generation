#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];

    gets(buffer);

    if (strlen(buffer) > BUFFER_SIZE)
    {
        printf("Error: Buffer overflow.\n");
    }
    else
    {
        printf("Message received: %s\n", buffer);
    }

    return 0;
}
