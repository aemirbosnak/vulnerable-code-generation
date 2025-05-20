//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void printTable(int row, int col, char ***table);

int main()
{
    char ***table = NULL;
    int r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    table = (char ***)malloc(r * sizeof(char **));
    for (int i = 0; i < r; i++)
    {
        table[i] = (char **)malloc(c * sizeof(char *));
        for (int j = 0; j < c; j++)
        {
            table[i][j] = (char *)malloc(20 * sizeof(char));
        }
    }

    printTable(r, c, table);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            free(table[i][j]);
        }
        free(table[i]);
    }

    free(table);

    return 0;
}

void printTable(int row, int col, char ***table)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", table[i][j]);
        }
        printf("\n");
    }
}