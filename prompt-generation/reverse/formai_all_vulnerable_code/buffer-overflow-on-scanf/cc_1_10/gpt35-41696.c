//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global constants
#define OPEN 0
#define BLOCKED 1
#define FULL 2

// Function declarations
void percolate(int n, double p);
void print_lattice(int n, int *lattice);

int main()
{
    int n;
    double p;
    printf("Enter the size of the lattice: ");
    scanf("%d", &n);
    printf("Enter the percolation probability (between 0 and 1): ");
    scanf("%lf", &p);

    srand(time(NULL));
    percolate(n, p);

    return 0;
}

// This function simulates percolation in a lattice of size n
// with percolation probability p.
void percolate(int n, double p)
{
    int *lattice = (int *)calloc(n * n, sizeof(int));

    // Initialize top and bottom row to be FULL
    for (int i = 0; i < n; i++)
    {
        lattice[i] = FULL;
        lattice[n * (n - 1) + i] = FULL;
    }

    // Loop through the rest of the lattice
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double rand_num = (double)rand() / RAND_MAX;
            if (rand_num < p)
            {
                lattice[i * n + j] = BLOCKED;
            }
            else
            {
                lattice[i * n + j] = OPEN;
            }
        }
    }

    // Define the size of interval to be checked
    int interval = n / 10;

    // Loop through the lattice to check for percolation
    for (int i = 1; i < n - 1; i++)
    {
        if (lattice[i * n] == OPEN)
        {
            // Check if any lattice site in the interval has FULL neighbors
            for (int j = 0; j < interval; j++)
            {
                if (lattice[i * n + j] == FULL && (lattice[(i - 1) * n + j] == FULL || lattice[(i + 1) * n + j] == FULL))
                {
                    lattice[i * n] = FULL;
                    break;
                }
            }
        }

        if (lattice[(i + 1) * n - 1] == OPEN)
        {
            // Check if any lattice site in the interval has FULL neighbors
            for (int j = n - interval; j < n; j++)
            {
                if (lattice[i * n + j] == FULL && (lattice[(i - 1) * n + j] == FULL || lattice[(i + 1) * n + j] == FULL))
                {
                    lattice[(i + 1) * n - 1] = FULL;
                    break;
                }
            }
        }
    }

    print_lattice(n, lattice);
    free(lattice);
}

// This function prints out the final state of the lattice
void print_lattice(int n, int *lattice)
{
    printf("\nLattice after percolation:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (lattice[i * n + j] == BLOCKED) 
            {
                printf("# ");
            } 
            else if (lattice[i * n + j] == FULL) 
            {
                printf("O ");
            } 
            else 
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}