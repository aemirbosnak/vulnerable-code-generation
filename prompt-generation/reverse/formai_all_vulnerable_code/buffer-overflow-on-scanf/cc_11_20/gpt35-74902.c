//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int check_win(char board[3][3], char player);
void print_board(char board[3][3]);
int computer_move(char board[3][3], char player);
int player_move(char board[3][3], char player);

int main()
{
    char board[3][3] = {{'-','-','-'}, {'-','-','-'}, {'-','-','-'}};
    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;

    printf("Welcome to Tic-Tac-Toe! Player 1 is X and Player 2 is O.\n");
    printf("The board looks like this:\n");
    print_board(board);
    printf("Player 1 will go first.\n");

    while (1)
    {
        if (current_player == player1)
        {
            int move = player_move(board, player1);
            board[move / 3][move % 3] = player1;
            if (check_win(board, player1))
            {
                printf("Player 1 wins the game!\n");
                break;
            }
            current_player = player2;
        }
        else
        {
            int move = computer_move(board, player2);
            board[move / 3][move % 3] = player2;
            if (check_win(board, player2))
            {
                printf("The computer wins the game!\n");
                break;
            }
            current_player = player1;
        }

        print_board(board);

        int board_full = 1;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (board[i][j] == '-')
                {
                    board_full = 0;
                    break;
                }
            }
        }

        if (board_full)
        {
            printf("The game is a tie!\n");
            break;
        }
    }

    return 0;
}

int check_win(char board[3][3], char player)
{
    /* check rows */
    for (int i=0; i<3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }

    /* check columns */
    for (int i=0; i<3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    /* check diagonals */
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

void print_board(char board[3][3])
{
    printf("   1 2 3\n");
    for (int i=0; i<3; i++)
    {
        printf("%d ", i+1);
        for (int j=0; j<3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int computer_move(char board[3][3], char player)
{
    /* check rows */
    for (int i=0; i<3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == '-')
        {
            return i*3 + 2;
        }
        if (board[i][0] == player && board[i][2] == player && board[i][1] == '-')
        {
            return i*3 + 1;
        }
        if (board[i][1] == player && board[i][2] == player && board[i][0] == '-')
        {
            return i*3;
        }
    }

    /* check columns */
    for (int i=0; i<3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == '-')
        {
            return 6 + i;
        }
        if (board[0][i] == player && board[2][i] == player && board[1][i] == '-')
        {
            return 3 + i;
        }
        if (board[1][i] == player && board[2][i] == player && board[0][i] == '-')
        {
            return i;
        }
    }

    /* check diagonals */
    if (board[0][0] == player && board[1][1] == player && board[2][2] == '-')
    {
        return 8;
    }
    if (board[1][1] == player && board[2][2] == player && board[0][0] == '-')
    {
        return 0;
    }
    if (board[0][0] == player && board[2][2] == player && board[1][1] == '-')
    {
        return 4;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == '-')
    {
        return 6;
    }
    if (board[1][1] == player && board[2][0] == player && board[0][2] == '-')
    {
        return 2;
    }
    if (board[0][2] == player && board[2][0] == player && board[1][1] == '-')
    {
        return 4;
    }

    /* if there is no chance of winning on this move, choose a random square */
    int random;
    do
    {
        random = rand() % 9;
    } while (board[random / 3][random % 3] != '-');

    return random;
}

int player_move(char board[3][3], char player)
{
    int row, column;
    do
    {
        printf("Enter the row and column of your move (e.g., '1 1' is the top-left square): ");
        scanf("%d %d", &row, &column);
        if (board[row-1][column-1] != '-')
        {
            printf("That square is already taken. Please choose another.\n");
        }
    } while (board[row-1][column-1] != '-');

    return (row-1)*3 + (column-1);
}