//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, x, y, z, score1 = 0, score2 = 0;
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    printf("Enter the number of players (2-4): ");
    scanf("%d", &n);

    if (n == 2)
    {
        printf("Player 1's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 1;
        score1++;
        printf("Player 2's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 2;
        score2++;
    }

    else if (n == 3)
    {
        printf("Player 1's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 1;
        score1++;
        printf("Player 2's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 2;
        score2++;
        printf("Player 3's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 3;
        score1++;
    }

    else if (n == 4)
    {
        printf("Player 1's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 1;
        score1++;
        printf("Player 2's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 2;
        score2++;
        printf("Player 3's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 3;
        score1++;
        printf("Player 4's turn:");
        scanf("%d %d", &x, &y);
        board[x][y] = 4;
        score2++;
    }

    printf("Game Over!\n");
    printf("The winner is: Player %d with a score of %d", score1 > score2 ? score1 : score2, score1 > score2 ? score1 : score2);

    return 0;
}