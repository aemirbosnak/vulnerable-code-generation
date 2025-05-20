//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int rows, cols;
int **curr_gen, **next_gen;

void init_board(int *arr[])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = rand() % 2;
}

void print_board(int *arr[])
{
    printf("\033c"); // Clear terminal
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%c ", arr[i][j] ? '*' : ' ');
        printf("\n");
    }
}

int get_neighbor_count(int i, int j)
{
    int count = 0;
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if (!(k == 0 && l == 0) && i + k >= 0 && i + k < rows && j + l >= 0 && j + l < cols && curr_gen[i + k][j + l] == 1)
                count++;
    return count;
}

void evolve_board()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int neighbor_count = get_neighbor_count(i, j);
            if (curr_gen[i][j] == 0 && neighbor_count == 3)
                next_gen[i][j] = 1; // Born
            else if (curr_gen[i][j] == 1 && (neighbor_count < 2 || neighbor_count > 3))
                next_gen[i][j] = 0; // Died
            else
                next_gen[i][j] = curr_gen[i][j]; // Survived
        }
    }
}

void swap_boards()
{
    int **tmp = curr_gen;
    curr_gen = next_gen;
    next_gen = tmp;
}

int main()
{
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    curr_gen = (int **)malloc(rows * sizeof(int *));
    next_gen = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        curr_gen[i] = (int *)malloc(cols * sizeof(int));
        next_gen[i] = (int *)malloc(cols * sizeof(int));
    }

    init_board(curr_gen);
    print_board(curr_gen);
    sleep(1);

    char c;
    do
    {
        evolve_board();
        swap_boards();
        print_board(curr_gen);
        sleep(1);

        printf("Press q to quit, any other character to continue: ");
        scanf(" %c", &c);
    } while (c != 'q');

    for (int i = 0; i < rows; i++)
    {
        free(curr_gen[i]);
        free(next_gen[i]);
    }
    free(curr_gen);
    free(next_gen);

    return 0;
}