#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char command[1024];

    printf("Enter a command: ");
    scanf("%s", command);

    if (strlen(command) > 10)
    {
        printf("Error: command too long.\n");
    }
    else
    {
        strcpy(buffer, command);
        printf("Command: %s\n", buffer);
    }

    return 0;
}
