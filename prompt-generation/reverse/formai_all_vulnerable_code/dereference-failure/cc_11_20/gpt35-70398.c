//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

// Function to display the game board
void display_board(char board[8][8])
{
    int i,j;
    printf("\n   0  1  2  3  4  5  6  7\n");
    printf("  ------------------------\n");
    for(i=0;i<8;i++)
    {
        printf("%d |",i);
        for(j=0;j<8;j++)
        {
            printf("%c |",board[i][j]);
        }
        printf("\n");
        printf("  ------------------------\n");
    }
}

// Function to determine the valid moves for a piece
void valid_moves(char board[8][8],int i,int j)
{
    if(board[i][j] == 'R')   // For a Rook
    {
        printf("Valid moves: \n");
        int k;
        for(k=0;k<8;k++)
        {
            if(k!=j)
            {
                printf("(%d,%d) ",i,k);
            }
            if(k!=i)
            {
                printf("(%d,%d) ",k,j);
            }
        }
    }
    else if(board[i][j] == 'K')  // For a Knight
    {
        printf("Valid moves: \n");
        if(i-2>=0 && j-1>=0)
        {
            printf("(%d,%d) ",i-2,j-1);
        }
        if(i-2>=0 && j+1<=7)
        {
            printf("(%d,%d) ",i-2,j+1);
        }
        if(i+2<=7 && j-1>=0)
        {
            printf("(%d,%d) ",i+2,j-1);
        }
        if(i+2<=7 && j+1<=7)
        {
            printf("(%d,%d) ",i+2,j+1);
        }
        if(i-1>=0 && j-2>=0)
        {
            printf("(%d,%d) ",i-1,j-2);
        }
        if(i+1<=7 && j-2>=0)
        {
            printf("(%d,%d) ",i+1,j-2);
        }
        if(i-1>=0 && j+2<=7)
        {
            printf("(%d,%d) ",i-1,j+2);
        }
        if(i+1<=7 && j+2<=7)
        {
            printf("(%d,%d) ",i+1,j+2);
        }
    }
    else if(board[i][j] == 'B')   // For a Bishop
    {
        printf("Valid moves: \n");
        int k,l;
        for(k=i,l=j;k>=0 && l>=0;k--,l--)
        {
            printf("(%d,%d) ",k,l);
        }
        for(k=i,l=j;k>=0 && l<=7;k--,l++)
        {
            printf("(%d,%d) ",k,l);
        }
        for(k=i,l=j;k<=7 && l>=0;k++,l--)
        {
            printf("(%d,%d) ",k,l);
        }
        for(k=i,l=j;k<=7 && l<=7;k++,l++)
        {
            printf("(%d,%d) ",k,l);
        }
    }
    else if(board[i][j] == 'Q')   // For a Queen
    {
        printf("Valid moves: \n");
        int k,l;
        for(k=0;k<8;k++)
        {
            if(k!=j)
            {
                printf("(%d,%d) ",i,k);
            }
            if(k!=i)
            {
                printf("(%d,%d) ",k,j);
            }
        }
        for(k=i,l=j;k>=0 && l>=0;k--,l--)
        {
            printf("(%d,%d) ",k,l);
        }
        for(k=i,l=j;k>=0 && l<=7;k--,l++)
        {
            printf("(%d,%d) ",k,l);
        }
        for(k=i,l=j;k<=7 && l>=0;k++,l--)
        {
            printf("(%d,%d) ",k,l);
        }
        for(k=i,l=j;k<=7 && l<=7;k++,l++)
        {
            printf("(%d,%d) ",k,l);
        }
    }
    else if(board[i][j] == 'P')   // For a Pawn
    {
        printf("Valid moves: \n");
        if(i == 1)
        {
            printf("(%d,%d) ",i+1,j);
            printf("(%d,%d) ",i+2,j);
        }
        else
        {
            printf("(%d,%d) ",i+1,j);
        }
    }
    else   // For an empty space
    {
        printf("No valid moves\n");
    }
}

int main()
{
    char board[8][8] = {{'R','K','B','Q','M','B','K','R'},  // Medieval style board with Rook, Knight, Bishop, Queen and King
                        {'P','P','P','P','P','P','P','P'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'p','p','p','p','p','p','p','p'},
                        {'r','k','b','q','m','b','k','r'}};
    int i,j;
    display_board(board);
    printf("\nEnter the coordinates of the piece you want to move:\n");
    printf("Row: ");
    scanf("%d",&i);
    printf("Column: ");
    scanf("%d",&j);
    printf("\n");
    valid_moves(board,i,j);
    printf("\n\n");
    return 0;
}