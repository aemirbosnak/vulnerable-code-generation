//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main()
{
    // Percolation Simulation Parameters
    int sim_size = MAX_SIM_SIZE;
    int num_particles = sim_size * sim_size;
    int iterations = 10000;
    int seed = time(NULL);
    srand(seed);

    // Create the Percolation Lattice
    int **lattice = (int **)malloc(sim_size * sizeof(int *));
    for (int i = 0; i < sim_size; i++)
    {
        lattice[i] = (int *)malloc(sim_size * sizeof(int));
    }

    // Initialize the Lattice
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < sim_size; j++)
        {
            lattice[i][j] = 0;
        }
    }

    // Place the Particles
    for (int i = 0; i < num_particles; i++)
    {
        lattice[rand() % sim_size][rand() % sim_size] = 1;
    }

    // Simulate the Percolation
    for (int iter = 0; iter < iterations; iter++)
    {
        // For each particle, check if it is surrounded by at least one wet particle
        for (int i = 0; i < sim_size; i++)
        {
            for (int j = 0; j < sim_size; j++)
            {
                if (lattice[i][j] == 1)
                {
                    int is_wet = 0;
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (lattice[i + dx][j + dy] == 1)
                            {
                                is_wet = 1;
                            }
                        }
                    }
                    if (is_wet == 0)
                    {
                        lattice[i][j] = 0;
                    }
                }
            }
        }
    }

    // Print the Final Lattice
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < sim_size; j++)
        {
            printf("%d ", lattice[i][j]);
        }
        printf("\n");
    }

    // Free the Lattice
    for (int i = 0; i < sim_size; i++)
    {
        free(lattice[i]);
    }
    free(lattice);

    return 0;
}