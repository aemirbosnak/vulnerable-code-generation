#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char data[1024] = "This is a large amount of data that will cause a buffer overflow";

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
