//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input;
    int room = 1;

    // Room 1 - Entrance
    printf("You are in a dark and dusty room. You hear a click and a rustling sound.\n");

    // Choose an action
    printf("What do you want to do? (c)enter, (p)peak, (h)ear, (a)tttack: ");
    scanf("%c", &input);

    switch (input)
    {
        case 'c':
            // Enter the room
            room = 2;
            break;
        case 'p':
            // Peak around the room
            printf("You see a strange object on the table.\n");
            break;
        case 'h':
            // Hear sounds
            printf("You hear footsteps and a distant scream.\n");
            break;
        case 'a':
            // Attack
            printf("You attack the object, but it is not harmful.\n");
            break;
        default:
            // Invalid input
            printf("Invalid input.\n");
            break;
    }

    // Room 2 - Main Hall
    if (room == 2)
    {
        printf("You are in a large hall. There is a door on the north wall and a trapdoor on the east wall.\n");

        // Choose an action
        printf("What do you want to do? (n)orth, (e)ast, (d)octor, (t)rapdoor: ");
        scanf("%c", &input);

        switch (input)
        {
            case 'n':
                // Go north
                room = 3;
                break;
            case 'e':
                // Go east
                room = 4;
                break;
            case 'd':
                // Go south
                room = 5;
                break;
            case 't':
                // Open the trapdoor
                room = 6;
                break;
            default:
                // Invalid input
                printf("Invalid input.\n");
                break;
        }
    }

    // Room 3 - Bedroom
    if (room == 3)
    {
        printf("You are in a bedroom. There is a bed, a dresser, and a window.\n");

        // Choose an action
        printf("What do you want to do? (b)ed, (d)resser, (w)indow: ");
        scanf("%c", &input);

        switch (input)
        {
            case 'b':
                // Sleep
                printf("You sleep and dream of a dream.\n");
                break;
            case 'd':
                // Dress
                printf("You dress and prepare for your journey.\n");
                break;
            case 'w':
                // Look out the window
                printf("You look out the window and see the sun shining on your face.\n");
                break;
            default:
                // Invalid input
                printf("Invalid input.\n");
                break;
        }
    }

    // Game over
    printf("The end.\n");

    return 0;
}