//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000

int main()
{
    int i, j, seq_length, mutation_rate, num_mutations, pos;
    char sequence[MAX_SEQ_LENGTH], mutated_sequence[MAX_SEQ_LENGTH];

    printf("Enter the length of the sequence: ");
    scanf("%d", &seq_length);

    printf("Enter the sequence: ");
    scanf("%s", sequence);

    printf("Enter the mutation rate (0-100): ");
    scanf("%d", &mutation_rate);

    num_mutations = (mutation_rate * seq_length) / 100;

    printf("\nOriginal sequence: %s\n", sequence);

    for (i = 0; i < num_mutations; i++)
    {
        pos = rand() % seq_length;

        for (j = 0; j < seq_length; j++)
        {
            if (j == pos)
            {
                switch (sequence[j])
                {
                case 'A':
                    mutated_sequence[j] = 'C';
                    break;
                case 'C':
                    mutated_sequence[j] = 'G';
                    break;
                case 'G':
                    mutated_sequence[j] = 'T';
                    break;
                case 'T':
                    mutated_sequence[j] = 'A';
                    break;
                default:
                    break;
                }
            }
            else
            {
                mutated_sequence[j] = sequence[j];
            }
        }

        strcpy(sequence, mutated_sequence);
    }

    printf("\nMutated sequence (%d mutations): %s\n", num_mutations, mutated_sequence);

    return 0;
}