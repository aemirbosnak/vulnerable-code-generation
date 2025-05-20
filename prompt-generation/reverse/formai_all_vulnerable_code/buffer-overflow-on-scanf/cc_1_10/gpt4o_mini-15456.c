//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 200
#define MAX_SEQUENCES 10

// Function to generate a random nucleotide sequence
void generate_random_genome(char* genome, int length) {
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        genome[i] = nucleotides[rand() % 4]; // Randomly select A, C, G, or T
    }
    genome[length] = '\0'; // Null-terminate the string
}

// Function to simulate a genome sequencing process for multiple samples
void simulate_genome_sequencing(int num_samples, int genome_length) {
    char genomes[MAX_SEQUENCES][MAX_GENOME_LENGTH + 1];
    for (int i = 0; i < num_samples; i++) {
        printf("Generating genome for sample %d...\n", i + 1);
        generate_random_genome(genomes[i], genome_length);
        printf("Sample %d: %s\n", i + 1, genomes[i]);
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Announce the start of the simulation
    printf("🎉 Welcome to the Genome Sequencing Simulator! 🎉\n");

    int num_samples, genome_length;

    // Ask the user for the number of samples and the genome length
    printf("How many genome samples would you like to generate? (Max: %d): ", MAX_SEQUENCES);
    scanf("%d", &num_samples);
    if (num_samples < 1 || num_samples > MAX_SEQUENCES) {
        printf("Please enter a number between 1 and %d.\n", MAX_SEQUENCES);
        return 1;
    }

    printf("What is the length of each genome sequence? (Max: %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &genome_length);
    if (genome_length < 1 || genome_length > MAX_GENOME_LENGTH) {
        printf("Please enter a number between 1 and %d.\n", MAX_GENOME_LENGTH);
        return 1;
    }

    // Start the simulation
    printf("Let's generate those genomes! 🚀\n");
    simulate_genome_sequencing(num_samples, genome_length);
    
    // Celebrate the end of the simulation
    printf("🎉 All genomes have been successfully generated! 🎉\n");
    printf("Thank you for playing with our Genome Sequencing Simulator! 🧬\n");

    return 0;
}