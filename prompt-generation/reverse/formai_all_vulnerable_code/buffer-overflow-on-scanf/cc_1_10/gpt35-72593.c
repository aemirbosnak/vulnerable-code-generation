//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void display(char board[][SIZE]);
void shuffle(char board[][SIZE]);
void play(char board[][SIZE]);

int main()
{
    char board[SIZE][SIZE] = {
        {'A', 'A', 'B', 'B'},
        {'C', 'C', 'D', 'D'},
        {'E', 'E', 'F', 'F'},
        {'G', 'G', 'H', 'H'}
    };

    shuffle(board);
    display(board);
    play(board);

    return 0;
}

void display(char board[][SIZE])
{
    printf("\n   1  2  3  4\n");

    for(int i = 0; i < SIZE; ++i)
    {
        printf("%c  ", 'A' + i);

        for(int j = 0; j < SIZE; ++j)
        {
            printf("%c  ", board[i][j]);
        }

        printf("\n");
    }
}

void shuffle(char board[][SIZE])
{
    srand(time(NULL));

    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            int r = rand() % (SIZE - i) + i;
            int c = rand() % (SIZE - j) + j;

            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void play(char board[][SIZE])
{
    do
    {
        printf("\nEnter the row and column numbers to flip the card: ");
        int row1, col1, row2, col2;
        scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

        if(row1 < 1 || row1 > SIZE || col1 < 1 || col1 > SIZE || row2 < 1 || row2 > SIZE || col2 < 1 || col2 > SIZE)
        {
            printf("Invalid input! Please enter row and column numbers between 1 and %d.\n", SIZE);
        }
        else if(board[row1 - 1][col1 - 1] == board[row2 - 1][col2 - 1])
        {
            board[row1 - 1][col1 - 1] = ' ';
            board[row2 - 1][col2 - 1] = ' ';
            display(board);
        }
        else
        {
            display(board);
            printf("\nSorry, wrong choice! Try again.\n");
        }
    }
    while(board[0][0] != ' ' || board[0][1] != ' ' || board[0][2] != ' ' || board[0][3] != ' ' || board[1][0] != ' ' || board[1][1] != ' ' || board[1][2] != ' ' || board[1][3] != ' ' || board[2][0] != ' ' || board[2][1] != ' ' || board[2][2] != ' ' || board[2][3] != ' ' || board[3][0] != ' ' || board[3][1] != ' ' || board[3][2] != ' ' || board[3][3] != ' ');
}