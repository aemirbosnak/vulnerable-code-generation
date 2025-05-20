#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[512];
    char command[128];

    printf("Enter command: ");
    scanf("%s", command);

    if (strlen(command) > 512)
    {
        printf("Error: Command too long.\n");
    }
    else
    {
        sprintf(buffer, "echo %s", command);
        system(buffer);
    }

    return 0;
}
