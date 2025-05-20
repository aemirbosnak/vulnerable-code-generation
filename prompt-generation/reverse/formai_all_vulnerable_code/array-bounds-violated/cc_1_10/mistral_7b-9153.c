//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASES 4
#define LENGTH 1000
#define READ_LENGTH 50
#define NUM_READS 10
#define SEED 1337

typedef struct read {
    char bases[READ_LENGTH];
    int quality[READ_LENGTH];
} read_t;

typedef struct genome {
    char bases[LENGTH];
} genome_t;

void generate_random_read(read_t* read) {
    int i;
    for (i = 0; i < READ_LENGTH; i++) {
        read->bases[i] = 'A' + (rand() % BASES);
        read->quality[i] = rand() % 100;
    }
    read->bases[i] = '\0';
}

void simulate_read(genome_t* genome, read_t* read) {
    int i, error_rate;
    error_rate = (rand() % 100) / 100.0 * 1.0;
    for (i = 0; i < READ_LENGTH; i++) {
        if (rand() % 100 < error_rate * 100.0) {
            read->bases[i] = genome->bases[rand() % LENGTH];
        }
    }
    read->bases[READ_LENGTH] = '\0';
}

void print_read(read_t* read) {
    int i;
    printf("READ: ");
    for (i = 0; i < strlen(read->bases); i++) {
        printf("%c%c", read->bases[i], i % 50 == 0 ? '\n' : ' ');
    }
    printf("QUALITY:\n");
    for (i = 0; i < strlen(read->bases); i++) {
        printf("%d%c", read->quality[i], i % 50 == 0 ? '\n' : ' ');
    }
    printf("\n");
}

void simulate_genome_sequencing(genome_t* genome) {
    int i, j;
    read_t reads[NUM_READS];
    for (i = 0; i < NUM_READS; i++) {
        generate_random_read(&reads[i]);
        simulate_read(genome, &reads[i]);
    }
    for (i = 0; i < NUM_READS; i++) {
        print_read(&reads[i]);
    }
}

int main() {
    genome_t genome;
    int i;
    srand(SEED);
    memset(genome.bases, 'A', LENGTH);
    genome.bases[LENGTH] = '\0';
    simulate_genome_sequencing(&genome);
    return 0;
}