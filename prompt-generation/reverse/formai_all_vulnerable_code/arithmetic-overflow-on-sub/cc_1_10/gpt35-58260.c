//FormAI DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void display_board(char board[][BOARD_SIZE])
{
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board(char board[][BOARD_SIZE])
{
    int i, j, k, l;
    char temp;
    srand(time(NULL));
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            k = rand() % BOARD_SIZE;
            l = rand() % BOARD_SIZE;
            temp = board[i][j];
            board[i][j] = board[k][l];
            board[k][l] = temp;
        }
    }
}

int check_match(char board[][BOARD_SIZE], int i1, int j1, int i2, int j2)
{
    if (board[i1][j1] == board[i2][j2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_win(char board[][BOARD_SIZE])
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == '*')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'a', 'b', 'c', 'd'},
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'e', 'f', 'g', 'h'}
    };
    int choices[2][2], c = 0, i, j, k, n = BOARD_SIZE*BOARD_SIZE/2, moves = 0, matches = 0;
    shuffle_board(board);
    display_board(board);
    while(1)
    {
        printf("\nEnter the row and column numbers of the first card to flip: ");
        scanf("%d %d", &i, &j);
        if (board[i-1][j-1] == '*')
        {
            choices[c][0] = i-1;
            choices[c][1] = j-1;
            c++;
        }
        else
        {
            printf("\nCard already flipped. Try again!");
            continue;
        }
        printf("\nEnter the row and column numbers of the second card to flip: ");
        scanf("%d %d", &i, &j);
        if (board[i-1][j-1] == '*')
        {
            choices[c][0] = i-1;
            choices[c][1] = j-1;
            c++;
        }
        else
        {
            printf("\nCard already flipped. Try again!");
            c--;
            continue;
        }
        if (check_match(board, choices[0][0], choices[0][1], choices[1][0], choices[1][1]))
        {
            board[choices[0][0]][choices[0][1]] = board[choices[1][0]][choices[1][1]];
            board[choices[1][0]][choices[1][1]] = ' ';
            matches++;
            printf("\nMatch found!");
        }
        else
        {
            printf("\nNo match!");
        }
        display_board(board);
        c = 0;
        if (check_win(board))
        {
            printf("\nCongratulations!! You won in %d moves!", moves);
            break;
        }
        moves++;
    }
    return 0;
}