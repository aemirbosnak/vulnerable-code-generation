//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void display_board(char board[3][3]);
int check_winner(char board[3][3], char symbol);
int minimax(char board[3][3], int depth, int alpha, int beta, int is_maximizing);
int get_best_move(char board[3][3]);
int get_player_move(char board[3][3], char symbol);

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int turn = 0;
    int winner = 0;
    int move = 0;

    // Main game loop
    while (turn < 9 && winner == 0)
    {
        // Player's turn
        if (turn % 2 == 0)
        {
            move = get_player_move(board, 'X');
            board[move / 3][move % 3] = 'X';

            if (check_winner(board, 'X'))
            {
                winner = 1;
                printf("Congratulations! You won the game!\n");
            }
        }
        // AI's turn
        else
        {
            move = get_best_move(board);
            board[move / 3][move % 3] = 'O';

            if (check_winner(board, 'O'))
            {
                winner = 2;
                printf("Sorry, you lost the game.\n");
            }
        }

        turn++;
        display_board(board);
    }

    // Game ended in a tie
    if (winner == 0)
    {
        printf("Game ended in a tie.\n");
    }

    return 0;
}

// Function to display Tic Tac Toe board
void display_board(char board[3][3])
{
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

// Function to check if the game has ended in a winning state
int check_winner(char board[3][3], char symbol)
{
    int i, j;

    // check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return 1;
        }
    }

    // check columns
    for (j = 0; j < 3; j++)
    {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
        {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return 1;
    }

    return 0;
}

// Function to implement the Minimax algorithm
int minimax(char board[3][3], int depth, int alpha, int beta, int is_maximizing)
{
    int i, j, score;
    int best_score;

    // check if game has ended in a winning state or a tie
    if (check_winner(board, 'O'))
    {
        return 10 - depth;
    }
    else if (check_winner(board, 'X'))
    {
        return depth - 10;
    }
    else if (depth == 9)
    {
        return 0;
    }

    // recursive calls to get the best score
    if (is_maximizing)
    {
        best_score = -1000;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    score = minimax(board, depth + 1, alpha, beta, 0);
                    board[i][j] = ' ';
                    if (score > best_score)
                    {
                        best_score = score;
                    }
                    if (score > alpha)
                    {
                        alpha = score;
                    }
                    if (alpha >= beta)
                    {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
    else
    {
        best_score = 1000;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    score = minimax(board, depth + 1, alpha, beta, 1);
                    board[i][j] = ' ';
                    if (score < best_score)
                    {
                        best_score = score;
                    }
                    if (score < beta)
                    {
                        beta = score;
                    }
                    if (alpha >= beta)
                    {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
}

// Function to get the AI's next move using Minimax algorithm
int get_best_move(char board[3][3])
{
    int i, j;
    int best_move;
    int best_score = -1000;
    int score;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                score = minimax(board, 0, -1000, 1000, 0);
                board[i][j] = ' ';
                if (score > best_score)
                {
                    best_score = score;
                    best_move = i * 3 + j;
                }
            }
        }
    }
    return best_move;
}

// Function to get the player's move
int get_player_move(char board[3][3], char symbol)
{
    int row, col;
    printf("Enter your move (row 1-3, column 1-3): ");
    scanf("%d%d", &row, &col);

    // check if move is valid
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
    {
        printf("Invalid move. Enter your move (row 1-3, column 1-3): ");
        scanf("%d%d", &row, &col);
    }

    return (row - 1) * 3 + (col - 1);
}