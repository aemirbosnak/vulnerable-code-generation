//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, i, j, x, y;
    char cmd;

    // Initialize the robot's position
    x = 0;
    y = 0;

    // Set up the game board
    char board[10][10] = {
        {'S', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}
    };

    // Loop until the robot reaches the goal or the user quits
    while (1)
    {
        // Get the user's command
        printf("Enter a command (w, s, e, n, q): ");
        scanf(" %c", &cmd);

        // Move the robot
        switch (cmd)
        {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'e':
                x++;
                break;
            case 'n':
                x--;
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
                break;
        }

        // Check if the robot has reached the goal
        if (board[y][x] == 'G')
        {
            printf("Congratulations! You have reached the goal!\n");
            exit(0);
        }

        // Check if the robot has run into a wall
        if (board[y][x] == 'O')
        {
            printf("Oops! You have run into a wall.\n");
            x = 0;
            y = 0;
        }

        // Print the game board
        for (r = 0; r < 10; r++)
        {
            for (c = 0; c < 10; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}