//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int n, i, j, k, l, m, p, q, s=0;
    float a[100][100], b[100][100], c[100][100], sum=0;
    char ch;
    clock_t start, end;
    double cpu_time_used;

    printf("\nEnter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &n, &m);

    printf("\nEnter the elements of the first matrix:\n");

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            printf("\nEnter element a(%d,%d): ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }

    printf("\nEnter the number of rows and columns of the second matrix: ");
    scanf("%d%d", &p, &q);

    if(m!=p)
        printf("\nThe matrices cannot be multiplied with each other.\n");
    else
    {
        printf("\nEnter the elements of the second matrix:\n");

        for(i=0; i<p; i++)
            for(j=0; j<q; j++)
            {
                printf("\nEnter element b(%d,%d): ", i+1, j+1);
                scanf("%f", &b[i][j]);
            }

        for(i=0; i<n; i++)
        {
            for(j=0; j<q; j++)
            {
                s=0;

                for(k=0; k<p; k++)
                {
                    s=s+a[i][k]*b[k][j];
                }

                c[i][j]=s;
            }
        }

        printf("\nProduct of entered matrices:\n");

        for(i=0; i<n; i++)
        {
            for(j=0; j<q; j++)
            {
                printf("\n%f\t", c[i][j]);
            }

            printf("\n\n");
        }
    }

    printf("\nDo you want to perform the same operation again? (y/n): ");
    scanf(" %c", &ch);

    if(ch=='y' || ch=='Y')
        main();
    else
        exit(0);

    return 0;
}