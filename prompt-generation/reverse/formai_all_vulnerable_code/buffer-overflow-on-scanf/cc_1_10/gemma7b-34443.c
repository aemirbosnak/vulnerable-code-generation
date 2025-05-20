//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Brave Terminal Game!\n");
    printf("------------------------\n");
    printf("You are in the land of the Brave.\n");
    printf("What would you like to do? (help/move/attack)\n");

    char input;
    scanf("%c", &input);

    switch (input)
    {
        case 'h':
            printf("You can move north, south, east, west, or attack.\n");
            break;
        case 'm':
            printf("Please specify the direction you want to move in (n/s/e/w).");
            char direction;
            scanf("%c", &direction);

            switch (direction)
            {
                case 'n':
                    printf("You moved north.\n");
                    break;
                case 's':
                    printf("You moved south.\n");
                    break;
                case 'e':
                    printf("You moved east.\n");
                    break;
                case 'w':
                    printf("You moved west.\n");
                    break;
                default:
                    printf("Invalid direction.\n");
                    break;
            }
            break;
        case 'a':
            printf("Please specify the target you want to attack.\n");
            int target;
            scanf("%d", &target);

            printf("You attacked the target %d.\n", target);
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}