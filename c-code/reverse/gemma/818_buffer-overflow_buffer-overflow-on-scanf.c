#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "light") == 0)
    {
        // Toggle light
    }
    else if (strcmp(input, "fan") == 0)
    {
        // Toggle fan
    }
    else if (strcmp(input, "ac") == 0)
    {
        // Toggle AC
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}
