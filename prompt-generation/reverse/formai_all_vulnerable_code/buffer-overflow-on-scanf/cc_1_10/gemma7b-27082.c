//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int row = 0, col = 0;
    char ch;

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &col);

    arr = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        arr[i] = (char *)malloc(col * sizeof(char));
    }

    printf("Enter the character: ");
    scanf("%c", &ch);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ch;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}