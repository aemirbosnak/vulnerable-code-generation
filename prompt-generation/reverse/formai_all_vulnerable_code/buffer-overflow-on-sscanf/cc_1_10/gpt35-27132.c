//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void fill_board(char board[SIZE][SIZE], char symbols[SIZE*SIZE/2]);
void shuffle_board(char board[SIZE][SIZE], char symbols[SIZE*SIZE/2]);
void display_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
void update_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x1, int y1, int x2, int y2);
int get_input(int *x, int *y);
int check_win(int revealed[SIZE][SIZE]);

int main()
{
    char board[SIZE][SIZE];
    char symbols[SIZE*SIZE/2] = {'H', 'E', 'A', 'R', 'T', 'S', 'L', 'O', 'V', 'E', 'F', 'U'};
    int revealed[SIZE][SIZE] = {{0}};
    int x1, y1, x2, y2;
    int turn_count = 0;

    srand(time(NULL));

    fill_board(board, symbols);
    shuffle_board(board, symbols);

    printf("\n\n");

    while(!check_win(revealed))
    {
        display_board(board, revealed);
        printf("\n\n");

        if(get_input(&x1, &y1))
        {
            if(revealed[x1][y1] == 0)
            {
                revealed[x1][y1] = 1;
                display_board(board, revealed);
                printf("\n\n");

                if(get_input(&x2, &y2))
                {
                    if(revealed[x2][y2] == 0)
                    {
                        revealed[x2][y2] = 1;
                        display_board(board, revealed);
                        printf("\n\n");

                        if(board[x1][y1] != board[x2][y2])
                        {
                            printf("Sorry, the cards do not match!\n");
                            revealed[x1][y1] = 0;
                            revealed[x2][y2] = 0;
                        }
                        else
                        {
                            printf("Congrats, you got a match!\n");
                        }

                        turn_count++;
                    }
                }
            }
        }

        printf("\n");
    }

    printf("You won in %d turns!\n\n", turn_count);

    return 0;
}

void fill_board(char board[SIZE][SIZE], char symbols[SIZE*SIZE/2])
{
    int i, j, k;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            k = i*SIZE + j;
            board[i][j] = symbols[k/2];
        }
    }
}

void shuffle_board(char board[SIZE][SIZE], char symbols[SIZE*SIZE/2])
{
    int i, j, k, l;
    char temp;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            k = rand()%(SIZE*SIZE);
            l = k/SIZE;

            temp = board[i][j];
            board[i][j] = board[l][k%SIZE];
            board[l][k%SIZE] = temp;
        }
    }
}

void display_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE])
{
    int i, j;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if(revealed[i][j] == 0)
            {
                printf("X  ");
            }
            else
            {
                printf("%c  ", board[i][j]);
            }
        }

        printf("\n");
    }
}

void update_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE], int x1, int y1, int x2, int y2)
{
    if(board[x1][y1] != board[x2][y2])
    {
        revealed[x1][y1] = 0;
        revealed[x2][y2] = 0;
    }
}

int get_input(int *x, int *y)
{
    char input[10];

    printf("Enter row and column separated by a space (eg. 1 2): ");

    if(fgets(input, 10, stdin) == NULL)
    {
        return 0;
    }

    if(sscanf(input, "%d %d", x, y) != 2)
    {
        return 0;
    }

    (*x)--;
    (*y)--;

    if((*x) >= 0 && (*x) < SIZE && (*y) >= 0 && (*y) < SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_win(int revealed[SIZE][SIZE])
{
    int i, j;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if(revealed[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}