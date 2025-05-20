//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, m, k, l, count = 0;
    int arr[10][10];
    int sum = 0;
    int magic_sum = 15;
    int magic[3][3] = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    int temp;

    printf("Enter the order of the magic square: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    if (sum!= magic_sum)
    {
        printf("The given elements do not form a magic square.\n");
        exit(0);
    }

    srand(time(0));
    k = rand() % n;
    l = rand() % n;

    while (k == l)
        l = rand() % n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0)
            {
                temp = arr[i][j];
                arr[i][j] = arr[k][j];
                arr[k][j] = temp;
            }
        }
    }

    printf("\nThe magic square is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}