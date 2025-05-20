//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Curious Game of Life!\n");
    printf("Prepare for a journey into the abyss of possibility...\n\n");

    // Create a 10x10 grid of cells
    int cells[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    // Simulate the game of life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the next generation of cells
        int next_cells[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
        };

        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                int num_neighbors = 0;
                if (cells[r-1][c] == 1) num_neighbors++;
                if (cells[r+1][c] == 1) num_neighbors++;
                if (cells[r][c-1] == 1) num_neighbors++;
                if (cells[r][c+1] == 1) num_neighbors++;

                if (cells[r][c] == 1 && num_neighbors < 2) next_cells[r][c] = 0;
                if (cells[r][c] == 0 && num_neighbors == 3) next_cells[r][c] = 1;
            }
        }

        // Copy the next generation of cells into the current generation
        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                cells[r][c] = next_cells[r][c];
            }
        }

        // Print the cells
        printf("Generation %d:\n", gen + 1);
        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                printf("%d ", cells[r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }

    system("clear");
    printf("Thank you for witnessing the Curious Game of Life!\n");
    printf("May the cells dance forever...\n\n");

    return 0;
}