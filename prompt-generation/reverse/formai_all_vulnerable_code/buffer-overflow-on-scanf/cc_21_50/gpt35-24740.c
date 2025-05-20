//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;

    printf("Enter the number of rows to be printed: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(i=n-1; i>=1; i--)
    {
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        for(j=1; j<=(i*2)-1; j++)
        {
            if(j==1 || j==(i*2)-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    for(i=n-1; i>=1; i--)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        for(j=1; j<=(i*2)-1; j++)
        {
            if(j==1 || j==(i*2)-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");

    int k = 0, l = 0;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        while(k != 2*i-1)
        {
            if (k == 0 || k == 2*i-2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            k++;
        }
        k = 0;

        printf("\n");
    } 

    for(i=n-1; i>=1; i--)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        while(k != 2*i-1)
        {
            if (k == 0 || k == 2*i-2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            k++;
        }
        k = 0;

        printf("\n");
    } 

    printf("\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    for(i=n-1; i>=1; i--)
    {
        for(j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        for(j=1; j<=2*i-1; j++)
        {
            if(j==1 || j==2*i-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    for(i=n-1; i>=1; i--)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        for(j=1; j<=2*i-1; j++)
        {
            if(j==1 || j==2*i-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}