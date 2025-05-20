//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
    printf("\033[ %d ; %d H", x, y);
}

int main()
{

    int x, y, n, score = 0, level = 1;
    char direction = ' ';

    // Game setup
    system("clear");
    gotoxy(10, 1);
    printf("Welcome to the Adventure!");

    // Game Loop
    while (score < 100)
    {
        // Display the level
        gotoxy(1, 1);
        printf("Level: %d", level);

        // Display the score
        gotoxy(1, 2);
        printf("Score: %d", score);

        // Show the character
        gotoxy(x, y);
        printf("O");

        // Get the direction
        direction = getchar();

        // Move the character
        switch (direction)
        {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
        }

        // Check if the character has reached the goal
        if (x == 20 && y == 20)
        {
            score++;
            level++;
            system("clear");
            gotoxy(10, 1);
            printf("Congratulations! You have completed Level %d.", level);
        }

        // Check if the character has hit a wall
        if (x < 0 || x > 20)
        {
            system("clear");
            gotoxy(10, 1);
            printf("Game Over! You have hit a wall.");
            break;
        }

        if (y < 0 || y > 20)
        {
            system("clear");
            gotoxy(10, 1);
            printf("Game Over! You have hit a wall.");
            break;
        }
    }

    return 0;
}