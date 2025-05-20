//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create_bingo_board(int board[][5], int size)
{
    int i, j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            board[i][j] = 0;
        }
    }
}

void print_bingo_board(int board[][5], int size)
{
    int i, j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void fill_bingo_board(int board[][5], int size)
{
    int i, j, count = 0;
    srand(time(0));
    while(count < size*size)
    {
        i = rand() % size;
        j = rand() % size;
        if(board[i][j] == 0)
        {
            board[i][j] = 1;
            count++;
        }
    }
}

void check_for_bingo(int board[][5], int size)
{
    int i, j, count = 0;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(board[i][j] == 1)
            {
                count++;
            }
        }
    }
    if(count == size*size)
    {
        printf("Bingo!\n");
    }
}

int main()
{
    int size, board[5][5], i, j;
    printf("Enter the size of the bingo board (between 1 and 10): ");
    scanf("%d", &size);

    if(size < 1 || size > 10)
    {
        printf("Invalid board size.\n");
        return 0;
    }

    create_bingo_board(board, size);
    fill_bingo_board(board, size);

    printf("Your bingo board:\n");
    print_bingo_board(board, size);

    check_for_bingo(board, size);

    return 0;
}