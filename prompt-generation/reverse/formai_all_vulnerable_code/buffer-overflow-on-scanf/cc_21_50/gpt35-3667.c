//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//A function to display the status of game
int gameStatus(char* board, int player1, int player2)
{
    printf("\nPlayer 1 : %c | Player 2 : %c\n", player1, player2);
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n");

    if(board[0]==player1 && board[1]==player1 && board[2]==player1)
        return 1;
    else if(board[0]==player2 && board[1]==player2 && board[2]==player2)
        return 2;
    else if(board[3]==player1 && board[4]==player1 && board[5]==player1)
        return 1;
    else if(board[3]==player2 && board[4]==player2 && board[5]==player2)
        return 2;
    else if(board[6]==player1 && board[7]==player1 && board[8]==player1)
        return 1;
    else if(board[6]==player2 && board[7]==player2 && board[8]==player2)
        return 2;
    else if(board[0]==player1 && board[3]==player1 && board[6]==player1)
        return 1;
    else if(board[0]==player2 && board[3]==player2 && board[6]==player2)
        return 2;
    else if(board[1]==player1 && board[4]==player1 && board[7]==player1)
        return 1;
    else if(board[1]==player2 && board[4]==player2 && board[7]==player2)
        return 2;
    else if(board[2]==player1 && board[5]==player1 && board[8]==player1)
        return 1;
    else if(board[2]==player2 && board[5]==player2 && board[8]==player2)
        return 2;
    else if(board[0]==player1 && board[4]==player1 && board[8]==player1)
        return 1;
    else if(board[0]==player2 && board[4]==player2 && board[8]==player2)
        return 2;
    else if(board[2]==player1 && board[4]==player1 && board[6]==player1)
        return 1;
    else if(board[2]==player2 && board[4]==player2 && board[6]==player2)
        return 2;
    else if(board[0]!='1' && board[1]!='2' && board[2]!='3' && board[3]!='4' && board[4]!='5' && board[5]!='6' && board[6]!='7' && board[7]!='8' && board[8]!='9')
        return 0;
    else
        return -1;
}

//A function to randomly choose the player
int choosePlayer(char* board, char player1, char player2)
{
    int playerTurn;
    srand(time(0));
    int turn = rand() % 2;

    if(turn==0)
    {
        printf("\nPlayer 1 [%c] goes first.\n", player1);
        playerTurn = 1;
    }

    else
    {
        printf("\nPlayer 2 [%c] goes first.\n", player2);
        playerTurn = 2;
    }
    return playerTurn;
}

//Main function to implement the game
int main()
{
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int playerTurn, i, position, gameResult;
    char player1, player2;

    printf("Welcome to Unique C Table Game - Tic Tac Toe\n");
    printf("-------------------------------------------------\n");
    printf("Player 1, choose your character (X or O): ");
    scanf(" %c", &player1);
    printf("\n");
    player1 = toupper(player1);

    while (player1!='X' && player1!='O')
    {
        printf("Invalid character. Choose only either 'X' or 'O'.\n");
        printf("Player 1, choose your character (X or O): ");
        scanf(" %c", &player1);
    }

    if(player1=='X')
    {
        player2 = 'O';
    }

    else
    {
        player2 = 'X';
    }

    playerTurn = choosePlayer(board, player1, player2);

    do{
        gameStatus(board, player1, player2);

        if(playerTurn == 1)
        {
            printf("\nPlayer 1 [%c], make a move: ", player1);
            scanf("%d", &position);

            while (position<1 || position>9)
            {
                printf("Invalid move. Choose a number between 1 to 9.\n");
                printf("\nPlayer 1 [%c], make a move: ", player1);
                scanf("%d", &position);
            }

        }

        else
        {
            printf("\nPlayer 2 [%c], make a move: ", player2);
            scanf("%d", &position);

            while (position<1 || position>9)
            {
                printf("Invalid move. Choose a number between 1 to 9.\n");
                printf("\nPlayer 2 [%c], make a move: ", player2);
                scanf("%d", &position);
            }

        }


        if(board[position-1]!=player1 && board[position-1]!=player2)
        {
            if(playerTurn == 1)
            {
                board[position-1] = player1;
                playerTurn = 2;
            }

            else
            {
                board[position-1] = player2;
                playerTurn = 1;
            }
        }
        else
        {
            printf("\nInvalid move. Position already occupied.\n");
            continue;
        }


        gameResult = gameStatus(board, player1, player2);

    }while(gameResult==-1);

    if(gameResult==1)
    {
        printf("\nPlayer 1 [%c] has won the game!\n", player1);
    }

    else if(gameResult==2)
    {
        printf("\nPlayer 2 [%c] has won the game!\n", player2);
    }
    else
    {
        printf("\nIt's a draw!");
    }

    gameStatus(board, player1, player2);

    return 0;
}