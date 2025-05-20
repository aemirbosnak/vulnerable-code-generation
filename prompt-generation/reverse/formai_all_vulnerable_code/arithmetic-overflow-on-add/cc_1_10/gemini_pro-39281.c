//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BASE_COUNT 4

// Nucleotide bases
char BASES[] = {'A', 'C', 'G', 'T'};

// Read length
int READ_LENGTH = 100;

// Genome sequence
char* GENOME;
int GENOME_LENGTH;

// Generate a random base
char random_base() {
    return BASES[rand() % BASE_COUNT];
}

// Generate a random read from the genome
char* random_read() {
    char* read = malloc(READ_LENGTH + 1);
    for (int i = 0; i < READ_LENGTH; i++) {
        int pos = rand() % GENOME_LENGTH;
        read[i] = GENOME[pos];
    }
    read[READ_LENGTH] = '\0';
    return read;
}

// Generate reads from the genome
char** generate_reads(int num_reads) {
    char** reads = malloc(num_reads * sizeof(char*));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = random_read();
    }
    return reads;
}

// Print reads to a file
void print_reads(char** reads, int num_reads, char* filename) {
    FILE* f = fopen(filename, "w");
    for (int i = 0; i < num_reads; i++) {
        fprintf(f, "%s\n", reads[i]);
    }
    fclose(f);
}

// Free reads
void free_reads(char** reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main(int argc, char* argv[]) {
    // Check arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <genome_file> <num_reads> <output_file>\n", argv[0]);
        return 1;
    }

    // Read genome
    FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening genome file: %s\n", argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    GENOME_LENGTH = ftell(f);
    rewind(f);
    GENOME = malloc(GENOME_LENGTH + 1);
    fread(GENOME, GENOME_LENGTH, 1, f);
    GENOME[GENOME_LENGTH] = '\0';
    fclose(f);

    // Parse arguments
    int num_reads = atoi(argv[2]);
    char* output_file = argv[3];

    // Generate reads
    char** reads = generate_reads(num_reads);

    // Print reads to file
    print_reads(reads, num_reads, output_file);

    // Free reads
    free_reads(reads, num_reads);

    return 0;
}