#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char input[100];
    printf("You are in a room with two doors. Enter 'north' to go north, 'south' to go south, 'east' to go east, 'west' to go west: ");
    scanf("%s", input);

    if (strcmp(input, "north") == 0)
    {
        printf("You went north.\n");
    }
    else if (strcmp(input, "south") == 0)
    {
        printf("You went south.\n");
    }
    else if (strcmp(input, "east") == 0)
    {
        printf("You went east.\n");
    }
    else if (strcmp(input, "west") == 0)
    {
        printf("You went west.\n");
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}
