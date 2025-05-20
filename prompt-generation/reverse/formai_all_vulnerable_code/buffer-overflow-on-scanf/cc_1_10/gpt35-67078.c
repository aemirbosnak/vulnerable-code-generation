//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000
#define NUM_NUCLEOTIDES 4

char nucleotides[NUM_NUCLEOTIDES] = {'A', 'T', 'C', 'G'};

void generate_random_genome(char *genome, int genome_size)
{
    srand(time(NULL));
    
    for (int i = 0; i < genome_size; i++)
    {
        int rand_index = rand() % NUM_NUCLEOTIDES;
        genome[i] = nucleotides[rand_index];
    }
}

void mutate_genome(char *genome, int genome_size)
{
    srand(time(NULL));

    for (int i = 0; i < genome_size; i++)
    {
        int rand_index = rand() % NUM_NUCLEOTIDES;

        // if the randomly generated nucleotide is the same as the current one, skip
        if (genome[i] == nucleotides[rand_index])
            continue;

        // else, mutate the current nucleotide with the randomly generated one
        genome[i] = nucleotides[rand_index];
    }
}

void print_genome(char *genome, int genome_size)
{
    printf("Genome: ");
    for (int i = 0; i < genome_size; i++)
        printf("%c", genome[i]);
    printf("\n");
}

int main()
{
    int genome_size;
    printf("Enter genome size: ");
    scanf("%d", &genome_size);

    char genome[MAX_GENOME_SIZE];
    generate_random_genome(genome, genome_size);
    
    printf("Initial ");
    print_genome(genome, genome_size);

    int num_mutations;
    printf("Enter number of mutations: ");
    scanf("%d", &num_mutations);

    for (int i = 0; i < num_mutations; i++)
    {
        mutate_genome(genome, genome_size);
        printf("Mutated ");
        print_genome(genome, genome_size);
    }

    return 0;
}