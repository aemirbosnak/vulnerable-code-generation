//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
char board[3][3];
int playerMove(int p) 
{ 
    int x, y;
    printf("Player %d: Enter co-ordinates for your move [row, col]: ", p); 
    scanf("%d %d", &x, &y);
    if (board[x][y] != ' ')
    {
        printf("\n Invalid Move! Position already taken. \n");
        return -1;
    }
    else
        board[x][y] = p == 1 ? 'X' : 'O';
    return 0;
} 
int checkWin(int p) 
{ 
    int i, j; 
    for (i = 0; i < 3; i++) //check rows for win
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2])
            || (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                return p;
    
    //check diagonals for win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2])
        || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            return p;
    
    return 0; 
} 
int aiMove(int ai, int player) 
{ 
    srand(time(NULL));
    int x, y; 
    do
    {
        //generate random coordinates for AI move
        x=rand()%3;
        y=rand()%3;
    }while(board[x][y]!=' '); //loop until a blank cell is found
    board[x][y]=ai == 1 ? 'X' : 'O';
    printf("\nAI move: [row, col] = [%d,%d]\n",x,y);
    return 0;
}
void initBoard()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
}
void displayBoard() 
{ 
    printf("\n\n"); 
    printf("\t\t\t  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]); 
    printf("\t\t\t----+---+----\n"); 
    printf("\t\t\t  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]); 
    printf("\t\t\t----+---+----\n"); 
    printf("\t\t\t  %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]); 
} 
int main() 
{ 
    int choice, player, winner=0;
    printf("\n\n:::::: TIC TAC TOE :::::::::\n\n");
    printf("Choose a player (1) or AI (2): ");
    scanf("%d",&choice); 
    initBoard();
    srand(time(NULL)); //initialize random seed
    player = rand() % 2 + 1; //randomly select player 1 or 2 to start

    for(int i = 0; i<9 ; i++) 
    { 
        if (player == choice)
            playerMove(player);
        else
            aiMove(player, choice);
        displayBoard();
        winner = checkWin(player);
        if(winner)//if a player has won the game
            break;
        player = player == 1 ? 2 : 1; //switch to other player or AI for next move
    }
    if(winner)
        printf("Player %d has won the game!", winner);
    else
        printf("Game over - Tie!");

    return 0; 
}