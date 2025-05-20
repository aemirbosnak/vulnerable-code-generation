//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main()
{
    int rows, cols;
    char **pattern;
    int i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    pattern = (char **)malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++)
    {
        pattern[i] = (char *)malloc(cols * sizeof(char));
    }
    printf("Enter the pattern:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%c", &pattern[i][j]);
        }
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (pattern[i][j] == '*' && i > 0 && j > 0 && pattern[i - 1][j - 1] == '*')
            {
                printf(" ");
            }
            else
            {
                printf("%c", pattern[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++)
    {
        free(pattern[i]);
    }
    free(pattern);
    return 0;
}