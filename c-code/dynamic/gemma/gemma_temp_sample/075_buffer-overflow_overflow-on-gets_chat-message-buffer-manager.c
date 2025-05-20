#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    char message[100];

    gets(message);

    if (strlen(message) > 10)
    {
        printf("Error: Message too long.\n");
    }
    else
    {
        strcpy(buffer, message);
        printf("Message received: %s\n", buffer);
    }

    return 0;
}
