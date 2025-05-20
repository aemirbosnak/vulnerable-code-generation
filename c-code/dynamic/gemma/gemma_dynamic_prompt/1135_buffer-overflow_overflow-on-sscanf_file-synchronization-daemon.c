#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char command[1024];

    printf("Enter command: ");
    scanf("%s", command);

    if (strlen(command) > 1024)
    {
        printf("Error: command too long.\n");
    }
    else
    {
        sprintf(buffer, "echo %s", command);
        system(buffer);
    }

    return 0;
}
