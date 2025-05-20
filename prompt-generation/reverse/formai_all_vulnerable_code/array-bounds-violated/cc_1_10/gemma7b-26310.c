//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Jungle Adventure!\n");

    // Create a 2D Array for the Jungle Map
    char jungleMap[5][5] = {{' ', ' ', 'A', ' ', ' '},
                              {'J', 'P', ' ', 'S', ' '},
                              {' ', 'R', ' ', ' ', ' '},
                              {'D', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '}};

    // Player Character
    char playerChar = 'P';

    // Game Loop
    int gameLoop = 1;

    // Movement Directions
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // While the game loop is running
    while (gameLoop)
    {
        // Display the Jungle Map
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                printf("%c ", jungleMap[r][c]);
            }
            printf("\n");
        }

        // Get the player's move
        char move = getchar();

        // Check if the move is valid
        int validMove = 0;
        for (int i = 0; i < 4; i++)
        {
            if (move == dx[i] && move == dy[i])
            {
                validMove = 1;
            }
        }

        // If the move is valid, move the player character
        if (validMove)
        {
            jungleMap[playerChar - 'A'][playerChar - 'A'] = ' ';
            playerChar = move + 'A';
            jungleMap[playerChar - 'A'][playerChar - 'A'] = playerChar;
        }

        // Check if the player has won or lost
        if (jungleMap[playerChar - 'A'][0] == 'A' || jungleMap[playerChar - 'A'][2] == 'A')
        {
            gameLoop = 0;
        }
    }

    // Game Over Message
    printf("Congratulations! You have won the Jungle Adventure!\n");

    return 0;
}