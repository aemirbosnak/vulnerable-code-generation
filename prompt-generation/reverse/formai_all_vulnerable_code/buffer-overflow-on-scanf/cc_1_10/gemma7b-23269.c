//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>

int main()
{
    int choice;

    printf("You are in a haunted house.\n");
    printf("You hear a noise in the hallway.\n");
    printf("What do you do?\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You grab a weapon and prepare for battle.\n");
            break;
        case 2:
            printf("You flee in terror.\n");
            break;
        case 3:
            printf("You try to hide.\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    printf("Suddenly, a ghost appears.\n");
    printf("The ghost whispers secrets in your ear.\n");
    printf("What do you do?\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You fight back, but the ghost is too strong.\n");
            break;
        case 2:
            printf("You try to escape, but the ghost catches you.\n");
            break;
        case 3:
            printf("You offer a sacrifice to the ghost.\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    printf("The ghost takes your soul.\n");
    printf("Game Over.\n");

    return 0;
}