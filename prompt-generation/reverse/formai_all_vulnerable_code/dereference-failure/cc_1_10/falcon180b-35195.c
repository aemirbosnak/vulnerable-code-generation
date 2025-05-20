//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 1000

char *genome_sequence;
char *reads[NUM_READS];
int read_lengths[NUM_READS];
int num_reads;

void generate_genome() {
    genome_sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        genome_sequence[i] = 'A' + rand() % 4;
    }
    genome_sequence[MAX_SEQUENCE_LENGTH - 1] = '\0';
}

void generate_reads() {
    srand(time(NULL));
    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = malloc(MAX_READ_LENGTH * sizeof(char));
        read_lengths[i] = rand() % MAX_READ_LENGTH + 1;
        for (int j = 0; j < read_lengths[i]; j++) {
            reads[i][j] = genome_sequence[rand() % MAX_SEQUENCE_LENGTH];
        }
        reads[i][read_lengths[i]] = '\0';
    }
    num_reads = NUM_READS;
}

void print_genome() {
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        printf("%c", genome_sequence[i]);
    }
    printf("\n");
}

void print_reads() {
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }
}

int main() {
    generate_genome();
    generate_reads();
    print_genome();
    print_reads();
    return 0;
}