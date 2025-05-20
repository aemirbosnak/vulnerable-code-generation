//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, x, y, z;

    printf("Enter the number of warriors: ");
    scanf("%d", &n);

    printf("Enter the number of battles: ");
    scanf("%d", &m);

    printf("Enter the number of moves per battle: ");
    scanf("%d", &x);

    printf("Enter the number of warriors in each team: ");
    scanf("%d", &y);

    printf("Enter the number of moves for each warrior: ");
    scanf("%d", &z);

    // Calculate the total number of moves
    k = m * x;

    // Allocate memory for the warriors' moves
    int *moves = (int *)malloc(n * k * sizeof(int));

    // Get the warriors' moves
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d", &moves[i * k + j]);
        }
    }

    // Calculate the winner
    l = 0;
    for (i = 0; i < n; i++)
    {
        int points = 0;
        for (j = 0; j < k; j++)
        {
            points += moves[i * k + j];
        }

        if (points > l)
        {
            l = points;
        }
    }

    // Print the winner
    printf("The winner is: ");
    printf("%d", l);

    return 0;
}