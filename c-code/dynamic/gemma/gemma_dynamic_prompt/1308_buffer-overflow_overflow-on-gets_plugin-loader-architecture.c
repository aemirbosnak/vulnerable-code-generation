#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int i;

    printf("Enter plugin name: ");
    gets(buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (i > 1023)
        {
            printf("Error: buffer overflow.\n");
            exit(1);
        }
    }

    printf("Plugin name: %s\n", buffer);

    return 0;
}
