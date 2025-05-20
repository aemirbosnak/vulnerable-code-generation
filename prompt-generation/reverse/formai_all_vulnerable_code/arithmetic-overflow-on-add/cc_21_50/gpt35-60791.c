//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include<stdio.h>

int main(){

    char board[8][8]={
        {' ','X',' ','X',' ','X',' ','X'},
        {'X',' ','X',' ','X',' ','X',' '},
        {' ','X',' ','X',' ','X',' ','X'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'O',' ','O',' ','O',' ','O',' '},
        {' ','O',' ','O',' ','O',' ','O'},
        {'O',' ','O',' ','O',' ','O',' '}
    //Initial board status
    };
    int turn = 0, startRow, startCol, endRow, endCol, x, y, numPieces[2] = {12, 12};
    //turn 0 represent player 0 and turn 1 represent player 1
    char s[100];

    while (numPieces[0] > 0 && numPieces[1] > 0)
    {
        printf("Player %d's turn\n", turn);
        printf("Enter the start position: ");
        scanf("%d %d", &startRow, &startCol);
        printf("Enter the end position: ");
        scanf("%d %d", &endRow, &endCol);

        //Check if the move is valid
        if (board[startRow][startCol] == 'X' && turn == 0)
        {
            printf("Invalid move! Try again\n");
            continue;
        }

        if (board[startRow][startCol] == 'O' && turn == 1)
        {
            printf("Invalid move! Try again\n");
            continue;
        }

        if (endRow > 8 || endRow < 0 || endCol > 8 || endCol < 0)
        {
            printf("Invalid move! Try again\n");
            continue;
        }

        //Clear the board and move the piece        
        board[endRow][endCol] = board[startRow][startCol];
        board[startRow][startCol] = ' ';
        
        //Check if a piece was captured
        x = (startRow + endRow) / 2;
        y = (startCol + endCol) / 2;

        if (board[x][y] == 'X' && turn == 1)
        {
            board[x][y] = ' ';
            numPieces[1]--;
        }

        if (board[x][y] == 'O' && turn == 0)
        {
            board[x][y] = ' ';
            numPieces[0]--;
        }

        //Check if a piece was crowned
        if ((board[endRow][endCol] == 'X' && endRow == 0) || (board[endRow][endCol] == 'O' && endRow == 7))
        {
            board[endRow][endCol] = toupper(board[endRow][endCol]);
        }

        //Switch turns
        if (turn == 0)
        {
            turn = 1;
        }
        else
        {
            turn = 0;
        }

        //Print out the board
        printf("\nBoard status:\n");
        printf("  0 1 2 3 4 5 6 7\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d ", i);
            for (int j = 0; j < 8; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        //Check if somebody won
        if (numPieces[0] == 0)
        {
            printf("Player 1 wins!\n");
            break;
        }
        else if (numPieces[1] == 0)
        {
            printf("Player 0 wins!\n");
            break;
        }

    }

    return 0;
}