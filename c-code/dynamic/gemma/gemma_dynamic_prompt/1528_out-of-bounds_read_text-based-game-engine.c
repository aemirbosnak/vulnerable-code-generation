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

    printf("Enter a command: ");
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] > 'a' && buffer[i] < 'z')
        {
            printf("Out of bounds!\n");
            return 1;
        }
    }

    printf("Command received: %s\n", buffer);

    return 0;
}
