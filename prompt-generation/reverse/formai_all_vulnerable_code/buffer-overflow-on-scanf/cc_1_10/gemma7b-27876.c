//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void greedy_algs_sync()
{
    int n, i, j, k, total_cakes = 0, current_cakes = 0;
    scanf("Enter the number of guests: ", &n);

    // Allocate memory for the cake distribution
    int *cakes = (int *)malloc(n * sizeof(int));

    // Get the number of cakes each guest wants
    for (i = 0; i < n; i++)
    {
        scanf("Enter the number of cakes desired by guest %d: ", &cakes[i]);
    }

    // Calculate the total number of cakes needed
    for (i = 0; i < n; i++)
    {
        total_cakes += cakes[i];
    }

    // Allocate memory for the cake distribution
    cakes = (int *)realloc(cakes, total_cakes * sizeof(int));

    // Distribute the cakes
    for (i = 0; i < n; i++)
    {
        current_cakes = cakes[i];
        cakes[i] = 0;

        for (j = 0; j < current_cakes; j++)
        {
            printf("Guest %d received a cake.\n", i + 1);
        }
    }

    // Print the remaining cakes
    for (i = 0; i < total_cakes; i++)
    {
        if (cakes[i] > 0)
        {
            printf("There are %d cakes remaining.\n", cakes[i]);
        }
    }

    // Free memory
    free(cakes);
}

int main()
{
    greedy_algs_sync();

    return 0;
}