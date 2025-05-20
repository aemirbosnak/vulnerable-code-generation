//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, p, q, r, s, t, u, v, w, x, y, z;
    int a[100][100];
    char b[100];
    
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    printf("Enter the value to be added to all elements of the matrix: ");
    scanf("%d", &k);
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] += k;
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}