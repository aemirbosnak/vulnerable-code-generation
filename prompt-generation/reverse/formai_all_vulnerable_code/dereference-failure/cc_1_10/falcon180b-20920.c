//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define MAX_READ_LENGTH 100
#define MAX_READS 1000
#define MAX_ERRORS 10

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *sequence;
    int length;
    int errors;
} Read;

void generate_genome(Genome *genome) {
    int i;
    for (i = 0; i < MAX_GENOME_LENGTH; i++) {
        genome->sequence[i] = rand() % 4 + 'A';
    }
    genome->length = MAX_GENOME_LENGTH;
}

void generate_reads(Read *reads, Genome *genome, int num_reads, int read_length, int max_errors) {
    int i, j, k;
    for (i = 0; i < num_reads; i++) {
        reads[i].sequence = malloc(read_length + 1);
        reads[i].length = read_length;
        reads[i].errors = 0;
        for (j = 0; j < read_length; j++) {
            k = rand() % genome->length;
            if (genome->sequence[k]!= reads[i].sequence[j]) {
                reads[i].errors++;
            }
            if (reads[i].errors >= max_errors) {
                break;
            }
            reads[i].sequence[j] = genome->sequence[k];
        }
        reads[i].sequence[read_length] = '\0';
    }
}

void print_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    int i;
    for (i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Genome genome;
    generate_genome(&genome);

    Read reads[MAX_READS];
    int num_reads = rand() % MAX_READS + 1;
    generate_reads(reads, &genome, num_reads, MAX_READ_LENGTH, MAX_ERRORS);

    printf("Original genome:\n");
    print_genome(&genome);

    printf("Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d:\n", i+1);
        print_read(&reads[i]);
    }

    return 0;
}