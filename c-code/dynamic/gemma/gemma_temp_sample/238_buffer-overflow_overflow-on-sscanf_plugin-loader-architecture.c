#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    char command[256];

    printf("Enter a command: ");
    scanf("%s", command);

    // Overflow the buffer
    command[255] = 'A';

    // Execute the command
    system(command);

    return 0;
}
