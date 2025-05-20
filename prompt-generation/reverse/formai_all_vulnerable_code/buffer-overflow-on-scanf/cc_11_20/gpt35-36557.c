//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to print the current board */
void print_board(int board[3][3])
{
    printf("\n");
    int i, j;
    for(i=0; i<3; i++){
        printf("--------\n");
        for(j=0; j<3; j++){
            printf("| %d ", board[i][j]);
        }
    printf("|\n");
    }
    printf("--------\n");
}

/* Function to check if the game has ended */
int check_end(int board[3][3])
{
    int i, j, flag;
    // Check for rows
    for(i=0; i<3; i++){
        flag = 0;
        for(j=0; j<3; j++){
            if(board[i][j] != board[i][0])
                flag = 1;
        }
        if(flag == 0)
            return board[i][0];
    }
    // Check for columns
    for(i=0; i<3; i++){
        flag = 0;
        for(j=0; j<3; j++){
            if(board[j][i] != board[0][i])
                flag = 1;
        }
        if(flag == 0)
            return board[0][i];
    }
    // Check for diagonals
    flag = 0;
    for(i=0; i<3; i++){
        if(board[i][i] != board[0][0])
            flag = 1;
    }
    if(flag == 0)
        return board[0][0];
    flag = 0;
    for(i=0; i<3; i++){
        if(board[i][2-i] != board[0][2])
            flag = 1;
    }
    if(flag == 0)
        return board[0][2];
    // Check for a tie
    flag = 0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == 0)
                flag = 1;
        }
    }
    if(flag == 0)
        return -1;
    return 0;
}

/* Main function */
int main(int argc, char *argv[])
{
    int player = 1, i, j, row, col, choice, turn=0;
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    srand(time(NULL)); // Set random seed
    printf("Welcome to the C Table Game. Player 1 is X, Player 2 is O.\n");
    printf("Player %d, please enter your name: ", player);
    char name[20];
    scanf("%s", name);
    while(check_end(board) == 0)
    {
        turn++;
        if(player==1)
            player=2;
        else
            player=1;
        printf("Turn %d: Player %d, it's your turn.\n", turn, player);
        print_board(board);
        printf("%s, please enter a number between 1 and 9 to place your marker: ", name);
        // Allow random CPU vs Human play
        if(player==2 && argc>1 && argv[1][0]=='c')
        {
            do // Select a random empty cell
            {
                choice = rand()%9 + 1;
                row = (int)((choice-1)/3);
                col = (choice-1)%3;
            }while(board[row][col]!=0);
            printf("%d\n", choice);
            // Wait for human to press enter
            getchar();
        }else{
            scanf("%d", &choice);
            row = (int)((choice-1)/3);
            col = (choice-1)%3;
            while(board[row][col] != 0)
            {
                printf("Invalid move. Please enter a valid number: ");
                scanf("%d",&choice);
                row = (int)((choice-1)/3);
                col = (choice-1)%3;
            }
        }
        if(player == 1)
            board[row][col] = 1;
        else
            board[row][col] = 2;

    }
    print_board(board);
    int winner = check_end(board);
    if(winner == 1)
        printf("Player 1 wins!\n");
    else if(winner == 2)
        printf("Player 2 wins!\n");
    else
        printf("It's a tie!\n");
    return 0;
}