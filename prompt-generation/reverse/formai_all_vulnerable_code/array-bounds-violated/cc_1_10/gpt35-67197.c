//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 100000
#define MAX_SEQUENCE_LENGTH 100
#define BASES "ATCG"

int main(void) {
    char genome[MAX_GENOME_LENGTH + 1];
    int genome_length, num_sequences;

    // Get the genome from a file or user input
    printf("Enter the genome sequence:\n");
    fgets(genome, MAX_GENOME_LENGTH + 1, stdin);
    genome_length = strlen(genome);
    if (genome[genome_length - 1] == '\n') {
        genome[genome_length - 1] = '\0';
        genome_length--;
    }

    // Generate random sequences and search for them in the genome
    printf("Enter the number of sequences to search for:\n");
    scanf("%d", &num_sequences);
    getchar(); // Consume the newline character left over from scanf

    for (int i = 0; i < num_sequences; i++) {
        char sequence[MAX_SEQUENCE_LENGTH + 1];
        int sequence_length, num_matches = 0;

        // Generate the random sequence
        srand(time(NULL) + i);
        sequence_length = rand() % MAX_SEQUENCE_LENGTH + 1;
        for (int j = 0; j < sequence_length; j++) {
            sequence[j] = BASES[rand() % 4];
        }
        sequence[sequence_length] = '\0';

        // Search for the sequence in the genome
        for (int j = 0; j <= genome_length - sequence_length; j++) {
            if (strncmp(genome + j, sequence, sequence_length) == 0) {
                num_matches++;
            }
        }

        // Print the results
        printf("Sequence %d: %s\n", i + 1, sequence);
        printf("Length: %d\n", sequence_length);
        printf("Number of matches: %d\n\n", num_matches);
    }

    return 0;
}