//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, i, j, patternSize;

    printf("Enter the size of the pattern: ");
    scanf("%d", &patternSize);

    // Check if pattern size is an even number
    if(patternSize % 2 != 0)
    {
        printf("Pattern size should be an even number!");
        return 0;
    }

    // Upper half of the pattern
    for(row = 0; row < patternSize/2; row++)
    {
        for(col = 0; col < patternSize; col++)
        {
            if(col == row || col == patternSize-row-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Middle line of the pattern
    for(col = 0; col < patternSize; col++)
        printf("*");
    printf("\n");

    // Lower half of the pattern
    for(row = patternSize/2-1; row >= 0; row--)
    {
        for(col = patternSize-1; col >= 0; col--)
        {
            if(col == row || col == patternSize-row-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}