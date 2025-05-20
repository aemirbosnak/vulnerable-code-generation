//Gemma-7B DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100];

    printf("Enter the number of players: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", a[i]);
    }

    printf("Enter the number of rounds: ");
    scanf("%d", &k);

    for(l = 0; l < k; l++)
    {
        for(m = 0; m < n; m++)
        {
            b[m] = 0;
        }

        for(i = 0; i < n; i++)
        {
            printf("%s, enter your move: ", a[i]);
            scanf("%d", &j);

            if(b[j] == 0)
            {
                b[j] = a[i];
            }
            else
            {
                printf("Move not valid.\n");
            }
        }

        for(i = 0; i < n; i++)
        {
            printf("%s's move: ", a[i]);
            printf("%d ", b[i]);
        }

        printf("\n");
    }

    return 0;
}