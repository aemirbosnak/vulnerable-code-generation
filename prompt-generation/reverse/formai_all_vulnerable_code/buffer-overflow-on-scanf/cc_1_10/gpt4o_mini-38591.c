//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 10000
#define SEQUENCING_ERROR_RATE 0.01 // 1% error rate
#define BASES "ACGT"

char* generate_random_genome(int length) {
    char *genome = (char *)malloc(length + 1);
    if (genome == NULL) {
        perror("Failed to allocate memory for genome");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        genome[i] = BASES[rand() % 4]; // Random base from A, C, G, T
    }
    genome[length] = '\0'; // Null-terminate the string

    return genome;
}

void simulate_sequencing_error(char *genome) {
    int length = strlen(genome);
    for (int i = 0; i < length; i++) {
        // Introduce errors based on the error rate
        if ((double)rand() / RAND_MAX < SEQUENCING_ERROR_RATE) {
            genome[i] = BASES[rand() % 4]; // Introduce an error by changing the base
        }
    }
}

void print_genome_stats(const char *genome) {
    int length = strlen(genome);
    int a_count = 0, c_count = 0, g_count = 0, t_count = 0;

    for (int i = 0; i < length; i++) {
        switch (genome[i]) {
            case 'A': a_count++; break;
            case 'C': c_count++; break;
            case 'G': g_count++; break;
            case 'T': t_count++; break;
        }
    }

    printf("Genome Statistics:\n");
    printf("Length: %d\n", length);
    printf("A: %d\n", a_count);
    printf("C: %d\n", c_count);
    printf("G: %d\n", g_count);
    printf("T: %d\n", t_count);
}

void save_genome_to_file(const char *filename, const char *genome) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", genome);
    fclose(file);
}

void load_genome_from_file(const char *filename, char *genome) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    fgets(genome, MAX_GENOME_LENGTH, file);
    fclose(file);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int genome_length;
    printf("Enter genome length (max %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &genome_length);
    if (genome_length < 1 || genome_length > MAX_GENOME_LENGTH) {
        fprintf(stderr, "Invalid genome length. Please enter a value between 1 and %d.\n", MAX_GENOME_LENGTH);
        return EXIT_FAILURE;
    }

    char *original_genome = generate_random_genome(genome_length);
    printf("Original Genome:\n%s\n", original_genome);

    char *sequenced_genome = strdup(original_genome); // Duplicate the original genome for sequencing with errors
    simulate_sequencing_error(sequenced_genome);
    printf("Sequenced Genome with Errors:\n%s\n", sequenced_genome);

    print_genome_stats(sequenced_genome);

    // Save original genome to a file
    save_genome_to_file("original_genome.txt", original_genome);

    // Load genome from the file and print
    char loaded_genome[MAX_GENOME_LENGTH];
    load_genome_from_file("original_genome.txt", loaded_genome);
    printf("Loaded Genome from File:\n%s\n", loaded_genome);

    // Free allocated memory
    free(original_genome);
    free(sequenced_genome);

    return EXIT_SUCCESS;
}