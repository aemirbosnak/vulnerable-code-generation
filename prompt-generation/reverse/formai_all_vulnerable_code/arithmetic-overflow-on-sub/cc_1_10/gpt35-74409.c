//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void display_board(char *board);
int check_win(char *board, char player);
int minimax(char *board, int depth, int isMaxPlayer, char ai, char human);
int get_best_move(char *board, char ai, char human);
void play_game(char ai, char human);

int main()
{
  char ai = 'X';
  char human = 'O';
  play_game(ai, human);
  return 0;
}

void display_board(char *board)
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int check_win(char *board, char player)
{
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player))
    {
        return 1;
    }
    return 0;
}

int minimax(char *board, int depth, int isMaxPlayer, char ai, char human)
{
    int score;
    int bestScore;
    int i;

    if (check_win(board, ai))
    {
        return 10 - depth;
    }
    else if (check_win(board, human))
    {
        return depth - 10;
    }
    else if (depth == 9)
    {
        return 0;
    }

    if (isMaxPlayer)
    {
        bestScore = -1000;
        for (i = 0; i < 9; i++)
        {
            if (board[i] == '-')
            {
                board[i] = ai;
                score = minimax(board, depth + 1, !isMaxPlayer, ai, human);
                board[i] = '-';
                if (score > bestScore)
                {
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
    else
    {
        bestScore = 1000;
        for (i = 0; i < 9; i++)
        {
            if (board[i] == '-')
            {
                board[i] = human;
                score = minimax(board, depth + 1, !isMaxPlayer, ai, human);
                board[i] = '-';
                if (score < bestScore)
                {
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

int get_best_move(char *board, char ai, char human)
{
    int i;
    int move;
    int bestScore = -1000;
    int score;

    for (i = 0; i < 9; i++)
    {
        if (board[i] == '-')
        {
            board[i] = ai;
            score = minimax(board, 0, 0, ai, human);
            board[i] = '-';
            if (score > bestScore)
            {
                bestScore = score;
                move = i;
            }
        }
    }
    return move;
}

void play_game(char ai, char human)
{
    char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    int turn = 1;
    int move;

    printf("Welcome to Retro Tic Tac Toe!\n");
    printf("You are O. The computer is X.\n");
    printf("\n");

    while (turn < 10)
    {
        if (turn % 2 != 0)
        {
            printf("It's your turn!\n");
            printf("\n");
            display_board(board);
            printf("Please choose a move (1-9): ");
            scanf("%d", &move);
            while (board[move - 1] != '-')
            {
                printf("Invalid move. Please choose a move (1-9): ");
                scanf("%d", &move);
            }
            board[move - 1] = human;
        }
        else
        {
            printf("It's the computer's turn!\n");
            move = get_best_move(board, ai, human);
            printf("Computer chose move %d.\n", move + 1);
            board[move] = ai;
        }

        if (check_win(board, ai))
        {
            printf("Computer wins!\n");
            display_board(board);
            return;
        }
        else if (check_win(board, human))
        {
            printf("You win!\n");
            display_board(board);
            return;
        }
        else if (turn == 9)
        {
            printf("It's a tie!\n");
            display_board(board);
            return;
        }

        turn++;
    }
}