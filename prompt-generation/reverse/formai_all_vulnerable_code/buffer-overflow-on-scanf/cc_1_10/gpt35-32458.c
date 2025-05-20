//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char board[3][3];
char player = 'X';
int gameover = 0;

void *checkwin(void *);
void drawboard();
void makemove(int, int);

int main()
{
    int i, j;
    pthread_t tid[2];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }

    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("Instructions:\n\n- Enter the row and column number separated by a space to place your symbol on the board.\n\n");

    while (!gameover)
    {
        drawboard();
        int row, col;
        printf("\nPlayer %c's turn: ", player);
        scanf("%d%d", &row, &col);

        if (board[row][col] == '-')
        {
            makemove(row, col);
            pthread_create(&(tid[0]), &attr, checkwin, (void *)"RowCheck");
            pthread_create(&(tid[1]), &attr, checkwin, (void *)"ColCheck");
            pthread_join(tid[0], NULL);
            pthread_join(tid[1], NULL);

            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }
        else
        {
            printf("Invalid move! Try again.\n");
        }
    }

    drawboard();

    if (player == 'X')
        printf("Player O wins!\n");
    else
        printf("Player X wins!\n");

    return 0;
}

void *checkwin(void *param)
{
    char *checkType = (char *)param;
    int i, j, count;

    if (player == 'X')
        count = 3; // Check for X winning
    else
        count = -3; // Check for O winning

    if (checkType == "RowCheck")
    {
        for (i = 0; i < 3; i++)
        {
            int rowVal = 0;
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                    rowVal++;
                else if (board[i][j] == 'O')
                    rowVal--;
            }
            if (rowVal == count)
            {
                gameover = 1;
                pthread_exit(NULL);
            }
        }
    }
    else if (checkType == "ColCheck")
    {
        for (i = 0; i < 3; i++)
        {
            int colVal = 0;
            for (j = 0; j < 3; j++)
            {
                if (board[j][i] == 'X')
                    colVal++;
                else if (board[j][i] == 'O')
                    colVal--;
            }
            if (colVal == count)
            {
                gameover = 1;
                pthread_exit(NULL);
            }
        }
    }

    pthread_exit(NULL);
}

void drawboard()
{
    int i, j;

    printf("\n  0 1 2\n");
    printf("  -------\n");

    for (i = 0; i < 3; i++)
    {
        printf("%d|", i);
        for (j = 0; j < 3; j++)
        {
            printf("%c|", board[i][j]);
        }
        printf("\n  -------\n");
    }
}

void makemove(int row, int col)
{
    board[row][col] = player;
}