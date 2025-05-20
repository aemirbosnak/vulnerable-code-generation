//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x, y, z, choice, score = 0;
    char board[4][4] = {{'.', '.', '.', '.'},
                              {'.', 'O', '.', '.'},
                              {'.', '.', 'O', '.'},
                              {'.', '.', '.', '.'}};

    system("clear");
    printf("Welcome to the Minesweeper Game!\n");
    printf("------------------------\n");

    // Placing the mines randomly
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            board[x][y] = rand() % 2 == 0 ? 'M' : '.';
        }
    }

    // Displaying the board
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }

    // Getting the user's choice
    printf("Enter your choice (number): ");
    scanf("%d", &choice);

    // Checking if the choice is valid
    if (choice < 1 || choice > 16)
    {
        printf("Invalid choice.\n");
        return;
    }

    // Checking if the cell has a mine
    if (board[x][y] == 'M')
    {
        printf("Game over! You lost.\n");
        return;
    }

    // Marking the cell as visited
    board[x][y] = 'V';

    // Incrementing the score
    score++;

    // Displaying the updated board
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }

    // Checking if the user won
    if (score == 16)
    {
        printf("Congratulations! You won!\n");
    }

    return;
}