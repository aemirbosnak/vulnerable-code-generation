//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Quantum Maze!\n");
    printf("---------------------\n");
    printf("You are in a labyrinth of intertwined corridors.\n");
    printf("A mysterious force is guiding you through the maze.\n");
    printf("To move forward, type 'f'. To move right, type 'r'. To move left, type 'l'.\n");

    char direction;

    while (1)
    {
        printf("Enter your direction: ");
        scanf("%c", &direction);

        switch (direction)
        {
            case 'f':
                system("clear");
                printf("You move forward into a blinding flash of light.\n");
                printf("You have reached the next level of the maze.\n");
                break;
            case 'r':
                system("clear");
                printf("You move right and encounter a wall.\n");
                break;
            case 'l':
                system("clear");
                printf("You move left and find a hidden secret passage.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        if (direction == 'f')
        {
            system("clear");
            printf("You have completed the Quantum Maze!\n");
            printf("Congratulations! You have won!\n");
            break;
        }
    }

    return 0;
}