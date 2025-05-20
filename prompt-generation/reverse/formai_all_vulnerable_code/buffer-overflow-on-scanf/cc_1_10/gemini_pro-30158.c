//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLUMNS 9
#define BOXES 9

int grid[ROWS][COLUMNS];

int boxes[BOXES][ROWS * COLUMNS];
int rows[ROWS][ROWS * COLUMNS];
int columns[COLUMNS][ROWS * COLUMNS];

int solved = 0;

void init_tables()
{
    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            rows[i][grid[i][j]] = 1;
            columns[j][grid[i][j]] = 1;
        }
    }

    for (i = 0; i < BOXES; i++)
    {
        for (j = 0; j < ROWS * COLUMNS; j++)
        {
            boxes[i][j] = 0;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            int box = i / 3 * 3 + j / 3;
            boxes[box][grid[i][j]] = 1;
        }
    }
}

int find_empty_cell()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            if (grid[i][j] == 0)
            {
                return i * COLUMNS + j;
            }
        }
    }

    return -1;
}

int is_valid_move(int cell, int value)
{
    int row = cell / COLUMNS;
    int column = cell % COLUMNS;
    int box = row / 3 * 3 + column / 3;

    return !rows[row][value] && !columns[column][value] && !boxes[box][value];
}

void solve_sudoku()
{
    int cell;

    while (!solved)
    {
        cell = find_empty_cell();

        if (cell == -1)
        {
            solved = 1;
            break;
        }

        int row = cell / COLUMNS;
        int column = cell % COLUMNS;

        for (int value = 1; value <= ROWS; value++)
        {
            if (is_valid_move(cell, value))
            {
                grid[row][column] = value;
                rows[row][value] = 1;
                columns[column][value] = 1;
                int box = row / 3 * 3 + column / 3;
                boxes[box][value] = 1;

                solve_sudoku();

                if (solved)
                {
                    break;
                }

                grid[row][column] = 0;
                rows[row][value] = 0;
                columns[column][value] = 0;
                boxes[box][value] = 0;
            }
        }
    }
}

void print_sudoku()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    init_tables();

    solve_sudoku();

    print_sudoku();

    return 0;
}