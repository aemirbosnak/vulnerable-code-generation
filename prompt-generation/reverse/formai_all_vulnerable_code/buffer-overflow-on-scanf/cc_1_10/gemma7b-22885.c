//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Magical Forest!\n");
    printf("--------------------\n");

    int forest_size = 10;
    int player_position = 0;
    int treasure_position = rand() % forest_size;

    char direction = ' ';

    while (direction != 'q')
    {
        printf("Current position: %d\n", player_position);
        printf("Enter direction (w/a/s/d/q): ");
        scanf("%c", &direction);

        switch (direction)
        {
            case 'w':
                player_position++;
                break;
            case 'a':
                player_position--;
                break;
            case 's':
                player_position++;
                break;
            case 'd':
                player_position--;
                break;
            case 'q':
                printf("Thank you for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (player_position == treasure_position)
        {
            printf("Congratulations! You found the treasure!\n");
            printf("The treasure is worth 100 gold coins.\n");
            break;
        }

        system("clear");
    }

    return 0;
}