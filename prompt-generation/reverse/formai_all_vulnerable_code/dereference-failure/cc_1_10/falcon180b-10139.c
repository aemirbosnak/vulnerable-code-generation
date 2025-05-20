//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set the seed for the random number generator
    srand(time(NULL));

    // Define the number of bases in the genome
    int genome_size = 5000000;

    // Define the number of reads to simulate
    int num_reads = 1000000;

    // Define the length of each read
    int read_length = 100;

    // Allocate memory for the genome
    char *genome = (char *) malloc(genome_size * sizeof(char));

    // Initialize the genome with random nucleotides
    for (int i = 0; i < genome_size; i++) {
        genome[i] = rand() % 4 + 'A';
    }

    // Allocate memory for the reads
    char **reads = (char **) malloc(num_reads * sizeof(char *));

    // Simulate the reads
    for (int i = 0; i < num_reads; i++) {
        reads[i] = (char *) malloc(read_length * sizeof(char));
        for (int j = 0; j < read_length; j++) {
            int offset = rand() % genome_size;
            reads[i][j] = genome[offset];
        }
    }

    // Print the genome
    printf("Genome:\n");
    for (int i = 0; i < genome_size; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // Print the reads
    printf("Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }

    // Free memory
    free(genome);
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}