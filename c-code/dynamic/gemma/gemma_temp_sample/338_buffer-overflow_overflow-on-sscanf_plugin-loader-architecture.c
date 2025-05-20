#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[512];
    char command[256];

    printf("Enter command: ");
    scanf(command, "%s");

    if (strlen(command) > 512)
    {
        printf("Error: Command too long.\n");
        exit(1);
    }

    strcpy(buffer, command);
    system(buffer);

    return 0;
}
