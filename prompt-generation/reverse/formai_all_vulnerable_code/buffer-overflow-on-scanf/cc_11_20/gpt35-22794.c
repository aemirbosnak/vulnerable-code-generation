//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, i, j, k, space1, space2;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    if(rows < 5)
    {
        printf("Please enter a number greater than or equal to 5!\n");
        exit(0);
    }
    for(i = 1; i <= rows; i++)
    {
        for(j = i; j < rows; j++)
        {
            printf(" ");
        }
        for(k = 1; k <= i * 2 - 1; k++)
        {
            if(k == 1 || k == i * 2 - 1)
            {
                printf("*");
            }
            else if(i == rows / 2 + 1)
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
    space1 = rows - 2;
    for(i = rows - 2; i >= 1; i--)
    {
        for(j = rows - 1; j > i; j--){
            printf(" ");
        }
        for(k = 1; k <= i * 2 - 1; k++)
        {
            if(k == 1 || k == i * 2 - 1)
            {
                printf("*");
            }
            else if(i == rows / 2 + 1)
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
    return 0;
}