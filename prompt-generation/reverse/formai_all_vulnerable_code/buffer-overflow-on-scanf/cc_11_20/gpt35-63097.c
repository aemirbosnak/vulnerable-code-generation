//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int room_num = 1;
    int life = 3;
    char name[20];
    printf("Welcome to The Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s! You are trapped in a maze, and your goal is to escape.\n", name);
    printf("You have 3 lives.\n");
    printf("Use 'n' to move north, 's' to move south, 'e' to move east, and 'w' to move west.\n");
    printf("Good luck!\n");
    while (life > 0)
    {
        if (room_num == 1)
        {
            printf("\nYou are in Room 1\n");
            printf("There are doors to the north and east.\n");
            printf("Which direction do you want to go? ");
            char direction[2];
            scanf("%s", direction);
            if (strcmp(direction, "n") == 0)
            {
                room_num = 2;
            }
            else if (strcmp(direction, "e") == 0)
            {
                room_num = 3;
            }
            else
            {
                printf("Invalid direction.\n");
            }
        }
        else if (room_num == 2)
        {
            printf("\nYou are in Room 2\n");
            printf("There are doors to the south and east.\n");
            printf("Which direction do you want to go? ");
            char direction[2];
            scanf("%s", direction);
            if (strcmp(direction, "s") == 0)
            {
                room_num = 1;
            }
            else if (strcmp(direction, "e") == 0)
            {
                room_num = 4;
            }
            else
            {
                printf("Invalid direction.\n");
            }
        }
        else if (room_num == 3)
        {
            printf("\nYou are in Room 3\n");
            printf("There are doors to the west and north.\n");
            printf("Which direction do you want to go? ");
            char direction[2];
            scanf("%s", direction);
            if (strcmp(direction, "w") == 0)
            {
                room_num = 1;
            }
            else if (strcmp(direction, "n") == 0)
            {
                room_num = 4;
            }
            else
            {
                printf("Invalid direction.\n");
            }
        }
        else if (room_num == 4)
        {
            printf("\nYou are in Room 4\n");
            printf("There are doors to the south and west.\n");
            printf("Which direction do you want to go? ");
            char direction[2];
            scanf("%s", direction);
            if (strcmp(direction, "s") == 0)
            {
                room_num = 3;
            }
            else if (strcmp(direction, "w") == 0)
            {
                room_num = 2;
            }
            else if (strcmp(direction, "n") == 0)
            {
                printf("\nCongratulations %s, you have escaped the maze!\n", name);
                break;
            }
            else
            {
                printf("Invalid direction.\n");
            }
        }
        else
        {
            printf("Invalid room number.\n");
        }
        if (rand() % 10 == 0)
        {
            printf("\nOh no! You were attacked by a monster and lost a life.\n");
            life--;
            if (life == 0)
            {
                printf("\nGame over %s, you have run out of lives.\n", name);
                break;
            }
        }
    }
    return 0;
}