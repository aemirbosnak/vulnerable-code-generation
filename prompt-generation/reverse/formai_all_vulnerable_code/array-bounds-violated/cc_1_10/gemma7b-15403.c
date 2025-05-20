//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y)
{
    Node* node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void playGame()
{
    // Create the game board
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Place the initial move
    board[1][1] = 1;

    // Loop until the game is over
    while (1)
    {
        // Get the player's move
        int moveX, moveY;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Check if the move is valid
        if (board[moveX][moveY] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[moveX][moveY] = 1;

        // Check if the player has won
        if (checkWin(board, 1) || checkWin(board, 2))
        {
            printf("You have won!\n");
            break;
        }

        // If there is no winner, it's a draw
        else if (board[BOARD_SIZE - 1][BOARD_SIZE - 1] == 0)
        {
            printf("It's a draw.\n");
            break;
        }
    }
}

int checkWin(int** board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // No winner
    return 0;
}

int main()
{
    playGame();

    return 0;
}