//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GENOME_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_READS 100000
#define MAX_MISMATCHES 2

typedef struct {
    char *genome;
    int genome_length;
    char **reads;
    int num_reads;
} Genome;

void generate_genome(Genome *genome) {
    char *bases = "ACGT";
    genome->genome = malloc(MAX_GENOME_LENGTH * sizeof(char));
    genome->genome_length = rand() % MAX_GENOME_LENGTH + 1;
    for (int i = 0; i < genome->genome_length; i++) {
        genome->genome[i] = bases[rand() % 4];
    }
}

void generate_reads(Genome *genome) {
    srand(time(NULL));
    genome->reads = malloc(MAX_READS * sizeof(char *));
    genome->num_reads = rand() % MAX_READS + 1;
    for (int i = 0; i < genome->num_reads; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        char *read = malloc(read_length * sizeof(char));
        for (int j = 0; j < read_length; j++) {
            read[j] = genome->genome[rand() % genome->genome_length];
        }
        genome->reads[i] = read;
    }
}

int count_mismatches(char *genome, char *read) {
    int mismatches = 0;
    for (int i = 0; i < strlen(read); i++) {
        if (genome[i]!= read[i]) {
            mismatches++;
        }
        if (mismatches > MAX_MISMATCHES) {
            break;
        }
    }
    return mismatches;
}

int main() {
    Genome genome;
    generate_genome(&genome);
    generate_reads(&genome);

    int total_mismatches = 0;
    for (int i = 0; i < genome.num_reads; i++) {
        int mismatches = count_mismatches(genome.genome, genome.reads[i]);
        total_mismatches += mismatches;
    }

    double error_rate = (double) total_mismatches / (genome.genome_length * genome.num_reads);
    printf("Error rate: %.2f%%\n", error_rate * 100);

    return 0;
}