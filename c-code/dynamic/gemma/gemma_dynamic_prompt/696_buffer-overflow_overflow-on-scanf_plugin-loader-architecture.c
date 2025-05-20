#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char buffer[1024];

    printf("Enter a command: ");
    scanf("%s", buffer);

    if (strlen(buffer) > 1024)
    {
        printf("Error: Buffer overflow.\n");
    }
    else
    {
        printf("Command: %s\n", buffer);
    }

    return 0;
}
