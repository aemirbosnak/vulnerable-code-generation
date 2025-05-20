//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000
#define NUM_BASES 4
#define A 0
#define C 1
#define G 2
#define T 3

int main()
{
    int genome[MAX_LENGTH];
    int length, mutation_rate, num_mutations, base;
    printf("Enter genome length: ");
    scanf("%d", &length);
    printf("Enter mutation rate (in percentage): ");
    scanf("%d", &mutation_rate);

    // Seed random number generator
    srand(time(NULL));

    // Generate random genome
    for (int i = 0; i < length; i++)
    {
        genome[i] = rand() % NUM_BASES;
    }

    // Print random genome
    printf("Original genome:\n");
    for (int i = 0; i < length; i++)
    {
        switch (genome[i])
        {
        case A:
            printf("A");
            break;
        case C:
            printf("C");
            break;
        case G:
            printf("G");
            break;
        case T:
            printf("T");
            break;
        }
    }
    printf("\n");

    // Introduce mutations
    num_mutations = (mutation_rate * length) / 100;
    for (int i = 0; i < num_mutations; i++)
    {
        // Select random base
        base = rand() % NUM_BASES;

        // Select random position
        int position = rand() % length;

        // Replace base at selected position
        genome[position] = base;
    }

    // Print mutated genome
    printf("Mutated genome:\n");
    for (int i = 0; i < length; i++)
    {
        switch (genome[i])
        {
        case A:
            printf("A");
            break;
        case C:
            printf("C");
            break;
        case G:
            printf("G");
            break;
        case T:
            printf("T");
            break;
        }
    }
    printf("\n");

    return 0;
}