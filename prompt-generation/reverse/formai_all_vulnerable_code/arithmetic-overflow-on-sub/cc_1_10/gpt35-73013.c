//FormAI DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

int main()
{
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("\n");

    // Upper part
    for(i=1; i<=n; i++)
    {
        // Printing stars
        for(j=1; j<=i; j++)
        {
            printf("*");
        }

        // Printing spaces
        for(k=i; k<n; k++)
        {
            printf(" ");
        }

        // Printing stars
        for(j=1; j<=i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    // Lower part
    for(i=n-1; i>=1; i--)
    {
        // Printing stars
        for(j=i; j>=1; j--)
        {
            printf("*");
        }

        // Printing spaces
        for(k=n-i; k>=1; k--)
        {
            printf(" ");
        }

        // Printing stars
        for(j=i; j>=1; j--)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}