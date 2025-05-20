//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define NUM_CARDS 10

int main()
{
    int i, j, k, flag = 0, player = 1, choice;
    char board[SIZE][SIZE];
    int card[NUM_CARDS][3] = { {1, 1, '1'}, {1, 2, '2'}, {1, 3, '3'}, {1, 4, '4'}, {1, 5, '5'}, {2, 1, '6'}, {2, 2, '7'}, {2, 3, '8'}, {2, 4, '9'}, {2, 5, '10'} };
    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            board[i][j] = 'X';
        }
    }

    for (k = 0; k < NUM_CARDS; k++)
    {
        i = rand() % SIZE;
        j = rand() % SIZE;

        while (board[i][j]!= 'X')
        {
            i = rand() % SIZE;
            j = rand() % SIZE;
        }

        board[i][j] = card[k][0];
        board[i + 1][j] = card[k][1];
        board[i][j + 1] = card[k][2];
    }

    do
    {
        system("clear");

        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                printf(" %c ", board[i][j]);
            }
            printf("\n");
        }

        printf("\nPlayer %d's turn\n", player);
        printf("Enter row: ");
        scanf("%d", &choice);
        printf("Enter column: ");
        scanf("%d", &choice);

        if (board[choice - 1][choice - 1] == 'X')
        {
            board[choice - 1][choice - 1] = 'O';
            board[choice - 1][choice] = 'O';
            board[choice][choice - 1] = 'O';
            printf("\nCorrect!");
            flag = 1;
        }
        else
        {
            printf("\nIncorrect!");
            flag = 0;
        }

        player++;
        if (player > 2)
        {
            player = 1;
        }
    } while (flag == 0);

    printf("\nPlayer %d wins!\n", player);

    return 0;
}