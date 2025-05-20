//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define SEQUENCING_ERROR_RATE 0.01

void generate_random_genome(char *genome, int length) {
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        genome[i] = nucleotides[rand() % 4];
    }
    genome[length] = '\0';  // Null terminate the string
}

void introduce_sequencing_errors(char *genome, int length) {
    for (int i = 0; i < length; i++) {
        if ((double)rand() / RAND_MAX < SEQUENCING_ERROR_RATE) {
            char original_nucleotide = genome[i];
            char new_nucleotide;
            do {
                new_nucleotide = "ACGT"[rand() % 4];
            } while (new_nucleotide == original_nucleotide);
            genome[i] = new_nucleotide;
        }
    }
}

void output_genome(const char *genome) {
    printf("Generated Genome: %s\n", genome);
}

void analyze_genome(const char *genome) {
    int counts[4] = {0};  // A, C, G, T
    int length = strlen(genome);
    
    for (int i = 0; i < length; i++) {
        switch (genome[i]) {
            case 'A': counts[0]++; break;
            case 'C': counts[1]++; break;
            case 'G': counts[2]++; break;
            case 'T': counts[3]++; break;
        }
    }

    printf("Analysis of Genome:\n");
    printf("A: %d (%.2f%%)\n", counts[0], (double)counts[0] / length * 100);
    printf("C: %d (%.2f%%)\n", counts[1], (double)counts[1] / length * 100);
    printf("G: %d (%.2f%%)\n", counts[2], (double)counts[2] / length * 100);
    printf("T: %d (%.2f%%)\n", counts[3], (double)counts[3] / length * 100);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    char genome[MAX_GENOME_LENGTH + 1];

    int genome_length;
    printf("Enter desired genome length (up to %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &genome_length);
    if (genome_length < 1 || genome_length > MAX_GENOME_LENGTH) {
        fprintf(stderr, "Invalid genome length. Please enter a value between 1 and %d.\n", MAX_GENOME_LENGTH);
        return EXIT_FAILURE;
    }

    generate_random_genome(genome, genome_length);
    output_genome(genome);

    printf("Introducing sequencing errors...\n");
    introduce_sequencing_errors(genome, genome_length);
    output_genome(genome);

    analyze_genome(genome);

    return EXIT_SUCCESS;
}