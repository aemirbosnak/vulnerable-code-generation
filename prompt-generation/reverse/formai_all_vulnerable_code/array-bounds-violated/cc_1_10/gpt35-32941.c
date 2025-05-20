//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>

int main()
{
    char chromosome1[] = "ACTGCGTACGCGTANNNN";
    char chromosome2[] = "TGCATGTGACGTACGNANA";
    char division = '/';

    printf("Welcome to the hilarious world of genetic programming!\n");
    printf("Our program will combine two chromosomes in a unique way!\n");

    printf("\nChromosome 1: %s\n", chromosome1);
    printf("Chromosome 2: %s\n", chromosome2);
    printf("Division sign: %c\n", division);

    printf("\nNow let's combine the chromosomes...\n");

    char combined_chromosome[50];
    int i;
    for (i = 0; i < 20; i++)
    {
        if (chromosome1[i] != 'N' && chromosome2[i] != 'N')
        {
            if (i % 2 == 0)
            {
                combined_chromosome[i] = chromosome1[i];
            }
            else
            {
                combined_chromosome[i] = chromosome2[i];
            }
        }
        else if (chromosome1[i] == 'N')
        {
            combined_chromosome[i] = chromosome2[i];
        }
        else if (chromosome2[i] == 'N')
        {
            combined_chromosome[i] = chromosome1[i];
        }
        else
        {
            combined_chromosome[i] = division;
        }
    }

    printf("\nThe combined chromosome is: %s\n", combined_chromosome);

    printf("\nHope you enjoyed our program!\n");

    return 0;
}