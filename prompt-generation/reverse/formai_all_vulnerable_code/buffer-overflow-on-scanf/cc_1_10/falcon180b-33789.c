//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, x, y, n, m, k;
    int arr[50][50];

    printf("Enter the size of the array: ");
    scanf("%d %d", &n, &m);

    srand(time(NULL));

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            arr[i][j] = rand()%2;
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(arr[i][j] == 0)
            {
                printf("\033[0;31m");
            }
            else
            {
                printf("\033[0;32m");
            }

            printf("%d ", arr[i][j]);

            if(arr[i][j] == 0)
            {
                printf("\033[0m");
            }
            else
            {
                printf("\033[0;32m");
            }
        }

        printf("\n");
    }

    return 0;
}