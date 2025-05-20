#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int x = 0;
    char buffer[1024];

    printf("Enter a command: ");
    scanf("%s", buffer);

    x = atoi(buffer);

    if (x > 1024)
    {
        printf("Error: value out of bounds\n");
    }
    else
    {
        printf("Value: %d\n", x);
    }

    return 0;
}
