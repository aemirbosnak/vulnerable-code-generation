//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(int difficulty)
{
    int i, j, r, c, d;
    char ch, command;
    time_t t;

    // Setting the atmosphere
    srand(time(NULL));
    i = rand() % 5;
    j = rand() % 5;
    r = rand() % 3;
    c = rand() % 2;

    // Building the haunted house
    printf("You wake up in a cold and desolate hallway.\n");
    printf("The only sound is the clock ticking and the wind howling outside.\n");
    printf("As you turn a corner, you find yourself in a haunted house.\n");

    // Playing the game
    printf("Please enter a command (go, explore, search, flee): ");
    scanf(" %c", &command);

    switch (command)
    {
        case 'g':
            // Going forward
            printf("You go forward and encounter a ghostly figure.\n");
            break;
        case 'e':
            // Exploring
            printf("You explore the house and find a hidden room.\n");
            break;
        case 's':
            // Searching
            printf("You search for clues and find a map.\n");
            break;
        case 'f':
            // Fleeing
            printf("You flee from the house and escape the ghostly figure.\n");
            break;
        default:
            printf("Invalid command.\n");
    }

    // Adding difficulty
    if (difficulty == 1)
    {
        d = rand() % 2;
        switch (d)
        {
            case 0:
                printf("The ghostly figure grabs you and pulls you into the house.\n");
                break;
            case 1:
                printf("The ghostly figure whispers secrets in your ear.\n");
                break;
        }
    }

    // Ending the game
    printf("The haunted house fades away and you are safe.\n");
}

int main()
{
    play_haunted_house(1);
    return 0;
}