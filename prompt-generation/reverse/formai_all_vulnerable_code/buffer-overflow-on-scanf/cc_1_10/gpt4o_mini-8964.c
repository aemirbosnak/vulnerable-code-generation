//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define MAX_READ_LENGTH 150
#define NUM_READS 100
#define NUM_BASES 4

const char bases[NUM_BASES] = {'A', 'C', 'G', 'T'};

// Function to generate a random DNA sequence
void generate_random_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = bases[rand() % NUM_BASES];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to simulate sequencing reads from the DNA sequence
void simulate_sequencing_reads(const char *dna_sequence, char reads[NUM_READS][MAX_READ_LENGTH + 1], int read_length) {
    int dna_length = strlen(dna_sequence);
    int start_position;
    
    for (int i = 0; i < NUM_READS; i++) {
        start_position = rand() % (dna_length - read_length + 1);
        strncpy(reads[i], &dna_sequence[start_position], read_length);
        reads[i][read_length] = '\0'; // Null-terminate the read
    }
}

// Function to write the generated sequences and reads to a file
void write_to_file(const char *filename, const char *dna_sequence, char reads[NUM_READS][MAX_READ_LENGTH + 1]) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing\n");
        exit(1);
    }

    fprintf(file, "Generated DNA Sequence:\n%s\n\n", dna_sequence);
    fprintf(file, "Sequencing Reads:\n");
    for (int i = 0; i < NUM_READS; i++) {
        fprintf(file, "%s\n", reads[i]);
    }

    fclose(file);
}

// Function to display the results on the console
void display_results(const char *dna_sequence, char reads[NUM_READS][MAX_READ_LENGTH + 1]) {
    printf("Generated DNA Sequence:\n%s\n\n", dna_sequence);
    printf("Sequencing Reads:\n");
    for (int i = 0; i < NUM_READS; i++) {
        printf("%s\n", reads[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char dna_sequence[MAX_GENOME_LENGTH + 1];
    char reads[NUM_READS][MAX_READ_LENGTH + 1];
    int sequence_length;

    printf("Enter the desired length of the DNA sequence (max %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &sequence_length);
    
    if (sequence_length < 1 || sequence_length > MAX_GENOME_LENGTH) {
        fprintf(stderr, "Invalid sequence length. It must be between 1 and %d.\n", MAX_GENOME_LENGTH);
        return 1;
    }

    generate_random_dna_sequence(dna_sequence, sequence_length);
    simulate_sequencing_reads(dna_sequence, reads, MAX_READ_LENGTH);
    
    display_results(dna_sequence, reads);
    
    // Write to output file
    write_to_file("genome_sequencing_output.txt", dna_sequence, reads);

    printf("Results have been saved to genome_sequencing_output.txt\n");
    return 0;
}