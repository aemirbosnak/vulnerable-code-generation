//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("You wake up in a cold, dark cell. The only sound is your own breathing and the faintest echo of your imprisoned screams.\n");

    printf("Suddenly, a prison guard rounds the corner. You hear the click of his clicker and the sound of his footsteps approaching.\n");

    // Choose your path:
    // 1. Fight back
    // 2. Attempt to escape
    // 3. Submit to authority

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You attempt to attack the guard, but he is too quick. He subdue you and throws you against the wall.\n");
            break;
        case 2:
            printf("You try to find a way to escape, but the cell is bare. There is no hope of freedom.\n");
            break;
        case 3:
            printf("You submit to the guard's authority, hoping for a moment of peace.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("The guard leaves the cell. You are alone again.\n");

    // What do you want to do next?
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "quit") == 0)
    {
        printf("You decide to quit and contemplate your bleak future.\n");
        exit(0);
    }

    printf("You have not implemented that command yet.\n");

    return 0;
}