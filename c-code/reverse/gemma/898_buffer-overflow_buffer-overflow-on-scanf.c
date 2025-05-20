#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char name[20];
    scanf("%s", name);

    printf("Hello, %s, welcome to the haunted house.\n", name);

    printf("You find yourself in a dark and dusty hallway. You hear a rustling sound coming from the end of the hall.\n");

    printf("What do you want to do? (A) Attack, (B) Avoid, (C) Investigate\n");
    char choice;
    scanf("%c", &choice);

    switch (choice)
    {
        case 'a':
            printf("You charged at the source of the sound, but it was just a harmless cat.\n");
            break;
        case 'b':
            printf("You avoided the sound, but you feel like you are being watched.\n");
            break;
        case 'c':
            printf("You investigated the sound and found a hidden secret room.\n");
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}
