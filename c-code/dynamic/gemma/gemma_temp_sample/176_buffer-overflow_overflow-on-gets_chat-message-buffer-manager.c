#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char message[1024];

    printf("Enter a message: ");
    gets(message);

    if (strlen(message) > 1024)
    {
        printf("Error: Message too long.\n");
    }
    else
    {
        strcpy(buffer, message);
        printf("Message stored: %s\n", buffer);
    }

    return 0;
}
