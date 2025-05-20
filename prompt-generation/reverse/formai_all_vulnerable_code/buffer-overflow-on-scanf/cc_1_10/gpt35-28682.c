//FormAI DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

int main()
{
    int rows, i, j, k, l, space;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Upper half of the pattern
    for(i=1; i<=rows; i++)
    {
        // Left half of the pattern
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        
        // Middle space
        space = 2 * rows - 2 * i;
        for(k=1; k<=space; k++)
        {
            printf(" ");
        }
        
        // Right half of the pattern
        for(l=1; l<=i; l++)
        {
            printf("*");
        }
        
        printf("\n");
    }

    // Lower half of the pattern
    for(i=rows; i>=1; i--)
    {
        // Left half of the pattern
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        
        // Middle space
        space = 2 * rows - 2 * i;
        for(k=1; k<=space; k++)
        {
            printf(" ");
        }
        
        // Right half of the pattern
        for(l=1; l<=i; l++)
        {
            printf("*");
        }
        
        printf("\n");
    }

    return 0;
}