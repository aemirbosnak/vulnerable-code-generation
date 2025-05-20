//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void print_board()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_winner()
{
    // vertical
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // horizontal
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    // diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int check_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

int get_player_input()
{
    int choice;
    printf("Enter the number of the cell you want to place your X in: ");
    scanf("%d", &choice);
    return choice;
}

int get_computer_input()
{
    int empty_cells[9];
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                empty_cells[index] = i * 3 + j;
                index++;
            }
        }
    }
    srand(time(NULL));
    return empty_cells[rand() % index];
}

void play_game()
{
    char player = 'X';
    char computer = 'O';
    int game_over = 0;
    while (!game_over)
    {
        print_board();
        int choice;
        if (player == 'X')
            choice = get_player_input();
        else
            choice = get_computer_input();
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O')
            board[row][col] = player;
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
        if (check_winner())
        {
            game_over = 1;
            print_board();
            if (player == 'O')
                printf("You win!\n");
            else
                printf("Computer wins!\n");
        }
        else if (check_draw())
        {
            game_over = 1;
            print_board();
            printf("It's a draw!\n");
        }
    }
}

int main()
{
    play_game();
    return 0;
}