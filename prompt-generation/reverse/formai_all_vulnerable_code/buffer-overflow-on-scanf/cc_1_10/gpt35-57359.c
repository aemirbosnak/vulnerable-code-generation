//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Alan Touring
#include <stdio.h>

#define BOARD_SIZE 9
#define BOARD_SECTION_SIZE 3

int board[BOARD_SIZE][BOARD_SIZE];

int find_empty_position(int *row, int *col)
{
    for (*row = 0; *row < BOARD_SIZE; (*row)++)
    {
        for (*col = 0; *col < BOARD_SIZE; (*col)++)
        {
            if (board[*row][*col] == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

int is_valid_row(int row, int num)
{
    int col;

    for (col = 0; col < BOARD_SIZE; col++)
    {
        if (board[row][col] == num)
        {
            return 0;
        }
    }

    return 1;
}

int is_valid_column(int col, int num)
{
    int row;

    for (row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][col] == num)
        {
            return 0;
        }
    }

    return 1;
}

int is_valid_section(int row, int col, int num)
{
    int section_row, section_col;

    section_row = row - row % BOARD_SECTION_SIZE;
    section_col = col - col % BOARD_SECTION_SIZE;

    for (row = section_row; row < section_row + BOARD_SECTION_SIZE; row++)
    {
        for (col = section_col; col < section_col + BOARD_SECTION_SIZE; col++)
        {
            if (board[row][col] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}

int is_valid_move(int row, int col, int num)
{
    return is_valid_row(row, num) && is_valid_column(col, num) && is_valid_section(row, col, num);
}

int solve_board()
{
    int row, col, num;

    if (!find_empty_position(&row, &col))
    {
        return 1;
    }

    for (num = 1; num <= BOARD_SIZE; num++)
    {
        if (is_valid_move(row, col, num))
        {
            board[row][col] = num;

            if (solve_board())
            {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

void print_board()
{
    int row, col;

    printf("-------------------------\n");

    for (row = 0; row < BOARD_SIZE; row++)
    {
        printf("| ");

        for (col = 0; col < BOARD_SIZE; col++)
        {
            printf("%d ", board[row][col]);

            if ((col + 1) % BOARD_SECTION_SIZE == 0)
            {
                printf("| ");
            }
        }

        printf("\n");

        if ((row + 1) % BOARD_SECTION_SIZE == 0)
        {
            printf("-------------------------\n");
        }
    }

    printf("\n");
}

int main()
{
    int row, col;

    printf("Enter %d x %d board:\n", BOARD_SIZE, BOARD_SIZE);

    for (row = 0; row < BOARD_SIZE; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            scanf("%d", &board[row][col]);
        }
    }

    printf("\n");

    if (solve_board())
    {
        printf("Solution:\n");
        print_board();
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}