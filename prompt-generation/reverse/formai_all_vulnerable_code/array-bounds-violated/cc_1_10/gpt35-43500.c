//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the Tic Tac Toe board
void print_board(char board[])
{
    printf("\n");
    printf("\t\t %c | %c | %c\n", board[0], board[1], board[2]);
    printf("\t\t---|---|---\n");
    printf("\t\t %c | %c | %c\n", board[3], board[4], board[5]);
    printf("\t\t---|---|---\n");
    printf("\t\t %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// function to check if the game has ended in a win, draw, or not ended yet
int check_win(char board[])
{
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == board[i+1] && board[i] == board[i+2])
        {
            return 1;
        }
    }
    
    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == board[i+3] && board[i] == board[i+6])
        {
            return 1;
        }
    }
    
    if (board[0] == board[4] && board[0] == board[8])
    {
        return 1;
    }
    
    if (board[2] == board[4] && board[2] == board[6])
    {
        return 1;
    }
    
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return 0;
        }
    }
    
    return 2;
}

// function for the AI to make a move
int ai_move(char board[])
{
    // check if the AI can win on the next move
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] == '-')
        {
            board[i] = 'O';
            if (check_win(board) == 1)
            {
                return i;
            }
            board[i] = '-';
        }
    }
    
    // check if the player can win on the next move and block them
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] == '-')
        {
            board[i] = 'X';
            if (check_win(board) == 1)
            {
                board[i] = 'O';
                return i;
            }
            board[i] = '-';
        }
    }
    
    // pick random move if no winning moves
    int move;
    srand(time(NULL));
    do
    {
        move = rand() % 9;
    } while (board[move] != '-');
    
    board[move] = 'O';
    
    return move;
}

int main()
{
    char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    int turn = 0;
    int winner = 0;
    
    printf("\t\tWelcome to Tic Tac Toe!\n");
    printf("\t\t=======================\n\n");
    
    print_board(board);
    
    while (winner == 0)
    {
        if (turn % 2 == 0)
        {
            int player_move;
            printf("Player's turn (X): ");
            scanf("%d", &player_move);
            if (board[player_move] == '-')
            {
                board[player_move] = 'X';
                turn++;
                print_board(board);
            }
            else
            {
                printf("Invalid move!\n");
            }
        }
        else
        {
            int ai = ai_move(board);
            printf("AI's turn (O): %d\n", ai);
            turn++;
            print_board(board);
        }
        
        winner = check_win(board);
        
        if (winner == 1)
        {
            if (turn % 2 == 0)
            {
                printf("AI wins!\n");
            }
            else
            {
                printf("Player wins!\n");
            }
        }
        else if (winner == 2)
        {
            printf("Draw!\n");
            break;
        }
    }
    
    return 0;
}