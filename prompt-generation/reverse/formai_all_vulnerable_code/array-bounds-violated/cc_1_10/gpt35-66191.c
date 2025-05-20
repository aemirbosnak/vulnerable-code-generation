//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int board[3][3] = {0}; // initialize the game board

/* function to print the game board */
void print_board()
{
    printf("Current Board:\n\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == 1)
                printf("X ");
            else if(board[i][j] == -1)
                printf("O ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

/* function to check for win conditions */
int check_win()
{
    int sum = 0;

    // check rows
    for(int i=0;i<3;i++)
    {
        sum = board[i][0] + board[i][1] + board[i][2];
        if(sum == 3 || sum == -3)
            return sum/3;
    }

    // check columns
    for(int i=0;i<3;i++)
    {
        sum = board[0][i] + board[1][i] + board[2][i];
        if(sum == 3 || sum == -3)
            return sum/3;
    }

    // check diagonals
    sum = board[0][0] + board[1][1] + board[2][2];
    if(sum == 3 || sum == -3)
        return sum/3;

    sum = board[0][2] + board[1][1] + board[2][0];
    if(sum == 3 || sum == -3)
        return sum/3;

    // if no win condition is met
    return 0;
}

/* function to generate a random move */
void ai_move(int player)
{
    int move_x = rand()%3;
    int move_y = rand()%3;

    while(board[move_x][move_y] != 0) // while the generated move is already occupied
    {
        move_x = rand()%3;
        move_y = rand()%3;
    }

    board[move_x][move_y] = player; // make the move on the game board
}

int main()
{
    srand(time(NULL)); // seed the random number generator with current time

    int player = 1; // player 1 starts the game

    while(check_win() == 0) // while there is no winner
    {
        print_board(); // print the current state of the game board

        if(player == 1) // player 1's turn
        {
            int x,y;
            printf("Player X's turn. Enter move coordinates: ");
            scanf("%d %d",&x,&y);

            while(board[x][y] != 0) // while the entered move is already occupied
            {
                printf("Invalid move. Try again. Enter move coordinates: ");
                scanf("%d %d",&x,&y);
            }

            board[x][y] = 1; // make the move on the game board
            player = -1; // switch to player 2's turn
        }
        else // player 2's turn
        {
            ai_move(-1); // generate an AI move for player 2
            player = 1; // switch to player 1's turn
        }
    }

    print_board();

    if(check_win() == 1)
        printf("Player X wins!\n");
    else if(check_win() == -1)
        printf("Player O wins!\n");
    else
        printf("It's a draw!\n");

    return 0;
}