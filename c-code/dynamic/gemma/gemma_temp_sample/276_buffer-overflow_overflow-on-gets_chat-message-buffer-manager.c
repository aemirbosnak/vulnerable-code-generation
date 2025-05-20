#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int i = 0;

    while (1)
    {
        printf("Enter message: ");
        gets(buffer);

        if (i > 10)
        {
            break;
        }

        printf("Message received: %s\n", buffer);
        i++;
    }

    return 0;
}
