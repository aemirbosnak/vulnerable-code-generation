//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000 // Maximum length of the genome sequence
#define MAX_NUM_OF_READS 1000 // Maximum number of reads to simulate
#define READ_LENGTH 100 // Length of each read
#define ERROR_RATE 0.01 // Error rate for each base call

typedef struct {
    char *sequence;
    int length;
} GenomeSequence;

typedef struct {
    char *sequence;
    int start_position;
    int end_position;
} Read;

void generate_genome_sequence(GenomeSequence *genome_sequence) {
    int i;
    for (i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        genome_sequence->sequence[i] = 'A' + rand() % 4; // Randomly generate A, C, G, or T
    }
    genome_sequence->length = MAX_SEQUENCE_LENGTH;
}

void generate_reads(Read *reads, int num_of_reads, GenomeSequence *genome_sequence) {
    int i, j, k;
    srand(time(NULL)); // Seed the random number generator with the current time
    for (i = 0; i < num_of_reads; i++) {
        reads[i].sequence = malloc(READ_LENGTH * sizeof(char));
        reads[i].start_position = rand() % genome_sequence->length;
        reads[i].end_position = reads[i].start_position + READ_LENGTH - 1;
        if (reads[i].end_position >= genome_sequence->length) {
            reads[i].end_position = genome_sequence->length - 1;
        }
        for (j = 0; j < READ_LENGTH; j++) {
            int base_index = reads[i].start_position + j;
            if (base_index >= genome_sequence->length) {
                break;
            }
            int base = genome_sequence->sequence[base_index];
            int error_probability = ERROR_RATE * 100;
            if (rand() % 100 < error_probability) {
                base = (base + rand() % 3) % 4; // Randomly introduce an error
            }
            reads[i].sequence[j] = base + 'A';
        }
    }
}

void print_genome_sequence(GenomeSequence *genome_sequence) {
    int i;
    for (i = 0; i < genome_sequence->length; i++) {
        printf("%c", genome_sequence->sequence[i]);
    }
    printf("\n");
}

void print_reads(Read *reads, int num_of_reads) {
    int i;
    for (i = 0; i < num_of_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i].sequence);
    }
}

int main() {
    GenomeSequence genome_sequence;
    Read reads[MAX_NUM_OF_READS];
    int num_of_reads;

    printf("Enter the number of reads to simulate: ");
    scanf("%d", &num_of_reads);

    generate_genome_sequence(&genome_sequence);
    generate_reads(reads, num_of_reads, &genome_sequence);

    print_genome_sequence(&genome_sequence);
    print_reads(reads, num_of_reads);

    return 0;
}