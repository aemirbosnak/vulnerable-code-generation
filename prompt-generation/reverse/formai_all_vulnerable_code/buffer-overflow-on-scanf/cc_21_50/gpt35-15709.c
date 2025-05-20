//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int rooms[5][5] = {0};
    int playerX = 2;
    int playerY = 2;
    bool gameOver = false;
    bool hasKey = false;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("The world has ended and you are the last survivor. You come across a haunted house, which may have valuable supplies. You must find the key to escape.\n");
    printf("Enter 'w' to move up, 'a' to move left, 's' to move down, and 'd' to move right.\n");

    while(!gameOver)
    {
        // Set up the room
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i == playerY && j == playerX)
                {
                    printf("X ");
                }
                else
                {
                    printf("%d ", rooms[i][j]);
                }
            }
            printf("\n");
        }

        // Check if the player has the key and is at the exit
        if(hasKey && playerX == 4 && playerY == 0)
        {
            printf("Congratulations, you found the key and escaped the haunted house!\n");
            gameOver = true;
        }

        // Player movement
        char input;
        printf("Enter a direction: ");
        scanf(" %c", &input);

        if(input == 'w')
        {
            if(playerY > 0)
            {
                playerY--;
            }
        }
        else if(input == 'a')
        {
            if(playerX > 0)
            {
                playerX--;
            }
        }
        else if(input == 's')
        {
            if(playerY < 4)
            {
                playerY++;
            }
        }
        else if(input == 'd')
        {
            if(playerX < 4)
            {
                playerX++;
            }
        }

        // Random events in each room
        int event = rand() % 4;
        if(rooms[playerY][playerX] == 0)
        {
            if(event == 0)
            {
                printf("You hear a strange noise...\n");
            }
            else if(event == 1)
            {
                printf("You feel a cold breeze...\n");
            }
            else if(event == 2)
            {
                printf("You see shadows moving...\n");
            }
            else
            {
                printf("You smell something rotten...\n");
            }
        }
        else if(rooms[playerY][playerX] == 1)
        {
            printf("You found a key!\n");
            hasKey = true;
        }
        rooms[playerY][playerX] = 2;    // Mark visited room as discovered
    }
    return 0;
}