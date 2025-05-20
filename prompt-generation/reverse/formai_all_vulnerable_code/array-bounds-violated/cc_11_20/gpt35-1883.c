//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// The game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Iterative deepening search function
int IDS(char aiPlayer, char huPlayer, int depth);

// MiniMax alpha beta pruning algorithm
int MiniMax(char aiPlayer, char huPlayer, int depth, int alpha, int beta, int maximizingPlayer);

// Check winner function
char CheckWin(char aiPlayer, char huPlayer);

// Draw board function
void DrawBoard();

int main()
{
    char huPlayer = 'X', aiPlayer = 'O';
    char turn = huPlayer;
    int move;

    printf("Welcome to Tic Tac Toe!\n");

    while (1)
    {
        DrawBoard();
        if (turn == huPlayer)
        {
            printf("It's your turn, select a move from 1-9: ");
            scanf("%d", &move);

            // Get row and column from input move
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            // Check if move is valid
            if (board[row][col] == ' ')
            {
                board[row][col] = huPlayer;
                turn = aiPlayer;
            }
            else
            {
                printf("Invalid move, try again.\n");
                continue;
            }
        }
        else
        {
            printf("It's my turn.\n");

            move = IDS(aiPlayer, huPlayer, 0);

            // Get row and column from AI move
            int row = move / 3;
            int col = move % 3;

            board[row][col] = aiPlayer;
            turn = huPlayer;
        }

        // Check if someone won
        char winner = CheckWin(aiPlayer, huPlayer);
        if (winner != ' ')
        {
            DrawBoard();
            printf("%c wins!\n", winner);
            break;
        }

        // Check if it's a tie
        int tie = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    tie = 0;
                    break;
                }
            }
            if (!tie)
            {
                break;
            }
        }
        if (tie)
        {
            DrawBoard();
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}

// Iterative deepening search function
int IDS(char aiPlayer, char huPlayer, int depth)
{
    int move = -1;
    int eval;

    // Run MiniMax with increasing depth until time limit is reached
    for (int i = 1; i <= 7; i += 2)
    {
        eval = MiniMax(aiPlayer, huPlayer, depth, -1000, 1000, 1);
        if (eval == 100)
        {
            return move;
        }
        if (eval == -100)
        {
            continue;
        }
        move = eval;
    }

    return move;
}

// MiniMax alpha beta pruning algorithm
int MiniMax(char aiPlayer, char huPlayer, int depth, int alpha, int beta, int maximizingPlayer)
{
    char winner = CheckWin(aiPlayer, huPlayer);

    // Check for terminal state (win/lose/draw)
    if (winner == aiPlayer)
    {
        return 100;
    }
    if (winner == huPlayer)
    {
        return -100;
    }
    if (winner == ' ')
    {
        return 0;
    }

    // Stop searching after reaching max depth
    if (depth >= 5)
    {
        return 0;
    }

    // Generate possible moves
    int moves[9], moveCount = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                moves[moveCount++] = i * 3 + j;
            }
        }
    }

    // Shuffle the moves to make it less predictable
    for (int i = moveCount - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = moves[i];
        moves[i] = moves[j];
        moves[j] = temp;
    }

    // Run MiniMax on each possible move
    int bestMove = -1, bestScore;
    if (maximizingPlayer)
    {
        bestScore = -1000;
        for (int i = 0; i < moveCount; i++)
        {
            int row = moves[i] / 3;
            int col = moves[i] % 3;

            board[row][col] = aiPlayer;
            int score = MiniMax(aiPlayer, huPlayer, depth + 1, alpha, beta, 0);
            board[row][col] = ' ';

            if (score > bestScore)
            {
                bestScore = score;
                bestMove = moves[i];
            }

            alpha = alpha > bestScore ? alpha : bestScore;
            if (alpha >= beta)
            {
                break;
            }
        }
    }
    else
    {
        bestScore = 1000;
        for (int i = 0; i < moveCount; i++)
        {
            int row = moves[i] / 3;
            int col = moves[i] % 3;

            board[row][col] = huPlayer;
            int score = MiniMax(aiPlayer, huPlayer, depth + 1, alpha, beta, 1);
            board[row][col] = ' ';

            if (score < bestScore)
            {
                bestScore = score;
                bestMove = moves[i];
            }

            beta = beta < bestScore ? beta : bestScore;
            if (alpha >= beta)
            {
                break;
            }
        }
    }

    if (depth == 0)
    {
        return bestMove;
    }
    else
    {
        return bestScore;
    }
}

// Check winner function
char CheckWin(char aiPlayer, char huPlayer)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == aiPlayer)
            {
                return aiPlayer;
            }
            if (board[i][0] == huPlayer)
            {
                return huPlayer;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == aiPlayer)
            {
                return aiPlayer;
            }
            if (board[0][i] == huPlayer)
            {
                return huPlayer;
            }
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == aiPlayer)
        {
            return aiPlayer;
        }
        if (board[0][0] == huPlayer)
        {
            return huPlayer;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == aiPlayer)
        {
            return aiPlayer;
        }
        if (board[0][2] == huPlayer)
        {
            return huPlayer;
        }
    }

    // Check for draw
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return ' ';
            }
        }
    }

    return '-';
}

// Draw board function
void DrawBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}