//Falcon-180B DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

void generateTable(int table[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            table[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

void printTable(int table[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS)
    {
        printf("Error: Table dimensions are too large.\n");
        return 1;
    }

    int table[MAX_ROWS][MAX_COLS];
    generateTable(table, rows, cols);
    printf("Generated table:\n");
    printTable(table, rows, cols);

    return 0;
}