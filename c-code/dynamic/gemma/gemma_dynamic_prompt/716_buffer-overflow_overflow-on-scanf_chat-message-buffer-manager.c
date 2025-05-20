#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];

    printf("Enter a message: ");
    scanf("%s", buffer);

    if (strlen(buffer) > BUFFER_SIZE)
    {
        printf("Error: buffer overflow\n");
    }
    else
    {
        printf("Message received: %s\n", buffer);
    }

    return 0;
}
