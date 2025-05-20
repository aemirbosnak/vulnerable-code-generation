//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>

#define BOARD_SIZE 3

typedef enum
{
    PLAYER_X,
    PLAYER_O,
    DRAW,
    NOT_OVER
}game_result;

char board[BOARD_SIZE][BOARD_SIZE]; // The board
int moves_made; // The number of moves made so far

void init_board(void)
{
    int i,j;
    for(i=0;i<BOARD_SIZE;i++)
    {
        for(j=0;j<BOARD_SIZE;j++)
        {
            board[i][j] = '_';
        }
    }
}

void display_board(void)
{
    int i,j;
    for(i=0;i<BOARD_SIZE;i++)
    {
        for(j=0;j<BOARD_SIZE;j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int make_move(int row, int col, char symbol)
{
    if(row>=BOARD_SIZE || col>=BOARD_SIZE)
    {
        printf("\nInvalid move! Try again.\n");
        return -1;
    }
    if(board[row][col] != '_')
    {
        printf("\nInvalid move! Try again.\n");
        return -1;
    }
    board[row][col] = symbol;
    moves_made++;
    return 0;
}

game_result check_game_over(void)
{
    int i,j;

    // Check rows
    for(i=0;i<BOARD_SIZE;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        {
            if(board[i][0]=='X') return PLAYER_X;
            else if(board[i][0]=='O') return PLAYER_O;
        }
    }

    // Check columns
    for(j=0;j<BOARD_SIZE;j++)
    {
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j])
        {
            if(board[0][j]=='X') return PLAYER_X;
            else if(board[0][j]=='O') return PLAYER_O;
        }
    }

    // Check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if(board[0][0]=='X') return PLAYER_X;
        else if(board[0][0]=='O') return PLAYER_O;
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        if(board[0][2]=='X') return PLAYER_X;
        else if(board[0][2]=='O') return PLAYER_O;
    }

    // Check for draw
    if(moves_made == BOARD_SIZE*BOARD_SIZE) return DRAW;

    return NOT_OVER;
}

void computer_play(void)
{
    int i,j;
    int empty_spots = 0;
    int row,col;
    char symbol = 'O';

    for(i=0;i<BOARD_SIZE;i++)
    {
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j] == '_')
            {
                empty_spots++;
                row = i;
                col = j;
            }
        }
    }

    if(empty_spots == 0)
    {
        printf("\nNo empty spots left to play!");
        return;
    }

    if(empty_spots == 1)
    {
        printf("\nPlaying in the only available spot\n");
    }

    make_move(row,col,symbol);

}

void player_play(void)
{
    int row,col;

    printf("\nYour turn! Choose a row and column:\n");
    scanf("%d %d", &row, &col);

    while(make_move(row,col,'X')==-1)
    {
        printf("\nTry again!\n");
        scanf("%d %d", &row, &col);
    }
}

int main()
{
    init_board();

    while(1)
    {
        display_board();

        player_play();
        if(check_game_over() != NOT_OVER) break;

        computer_play();
        if(check_game_over() != NOT_OVER) break;
    }

    game_result result = check_game_over();

    if(result == PLAYER_X) printf("\nYou win!");
    else if(result == PLAYER_O) printf("\nComputer wins!");
    else if(result == DRAW) printf("\nIt's a draw!");

    return 0;
}