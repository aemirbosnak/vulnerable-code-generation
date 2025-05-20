#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[10];
    char *command = NULL;

    printf("Enter command: ");
    scanf("%s", buffer);

    command = malloc(strlen(buffer) + 1);
    memcpy(command, buffer, strlen(buffer) + 1);

    printf("Command: %s\n", command);

    free(command);
    return 0;
}
