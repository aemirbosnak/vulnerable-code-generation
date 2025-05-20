//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our DNA alphabet
const char dna_alphabet[] = {'A', 'C', 'G', 'T'};

int main()
{
    // Set the seed for the random number generator
    srand(time(0));

    // Use 10 bases length for our genome sequence
    const int genome_length = 10;

    // Create an empty genome sequence
    char genome[genome_length];

    // Generate random genome sequence
    for (int i = 0; i < genome_length; i++)
    {
        int random_index = rand() % 4;
        genome[i] = dna_alphabet[random_index];
    }

    // Print the genome sequence
    printf("Your randomly generated genome sequence is: ");
    for (int i = 0; i < genome_length; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");

    // Prompt user for mutation probability
    printf("Enter a mutation probability as a percentage (0-100): ");
    int mutation_probability;
    scanf("%d", &mutation_probability);

    // Mutate the genome sequence based on the user's input probability
    for (int i = 0; i < genome_length; i++)
    {
        int random_num = rand() % 100;
        if (random_num < mutation_probability)
        {
            int random_index = rand() % 4;
            genome[i] = dna_alphabet[random_index];
        }
    }

    // Print the mutated genome sequence
    printf("Your mutated genome sequence is: ");
    for (int i = 0; i < genome_length; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}