#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Hello, %s, welcome to the haunted house.\n", name);

    int choice;
    printf("You find yourself in a dark hallway. You hear a noise behind you. Do you:\n");
    printf("1. Turn around.\n");
    printf("2. Proceed forward.\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You turn around and see a ghostly figure standing there.\n");
            break;
        case 2:
            printf("You proceed forward and find a hidden room.\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}
