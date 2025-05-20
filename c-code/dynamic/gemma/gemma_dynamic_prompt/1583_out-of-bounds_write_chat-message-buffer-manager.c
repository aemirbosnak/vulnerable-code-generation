#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int index = 0;
    int size = 0;

    printf("Enter message: ");
    getline(buffer, 1024, stdin);

    size = strlen(buffer) + 1;
    if (size > 1024)
    {
        printf("Message too long\n");
    }
    else
    {
        buffer[index] = '\0';
        index++;
        printf("Message stored: %s\n", buffer);
    }

    return 0;
}
