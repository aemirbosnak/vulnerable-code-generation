//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define BASES "ACGT"

// Function prototypes
void generate_random_dna(char *dna, int length);
void simulate_sequencing(const char *dna, int read_length);
void write_sequence_to_file(const char *filename, const char *dna);

int main() {
    int genome_length, read_length;
    char DNA[MAX_GENOME_LENGTH + 1];

    srand(time(NULL)); // Seed for random number generation

    // Get genome length from user
    printf("Enter the length of the genome (max %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &genome_length);
    if (genome_length > MAX_GENOME_LENGTH || genome_length <= 0) {
        printf("Invalid genome length. Setting to max length of %d\n", MAX_GENOME_LENGTH);
        genome_length = MAX_GENOME_LENGTH;
    }

    // Generate random DNA sequence
    generate_random_dna(DNA, genome_length);
    printf("Generated Genome Sequence: %s\n", DNA);

    // Get read length from user
    printf("Enter the length of the sequencing read: ");
    scanf("%d", &read_length);
    if (read_length <= 0 || read_length > genome_length) {
        printf("Invalid read length. Setting to %d\n", genome_length);
        read_length = genome_length;
    }

    // Simulate sequencing
    simulate_sequencing(DNA, read_length);

    // Write the genome to a file
    write_sequence_to_file("generated_genome.txt", DNA);

    return 0;
}

// This function generates a random DNA sequence
void generate_random_dna(char *dna, int length) {
    for (int i = 0; i < length; i++) {
        dna[i] = BASES[rand() % 4]; // Randomly select from "ACGT"
    }
    dna[length] = '\0'; // Null-terminate the string
}

// This function simulates the reading of a DNA sequence
void simulate_sequencing(const char *dna, int read_length) {
    int start_position = rand() % (strlen(dna) - read_length + 1); // Random start
    printf("Simulated sequencing read: ");
    for (int i = 0; i < read_length; i++) {
        putchar(dna[start_position + i]);
    }
    putchar('\n');
}

// This function writes the generated genome to a file
void write_sequence_to_file(const char *filename, const char *dna) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    fprintf(file, "%s\n", dna);
    fclose(file);
    printf("Genome sequence written to '%s'\n", filename);
}