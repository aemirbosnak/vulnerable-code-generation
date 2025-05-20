//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char base;
    int quality;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
    int read_length;
} ReadSet;

void generate_random_dna(char *dna, int length) {
    for (int i = 0; i < length; i++) {
        dna[i] = 'A' + rand() % 4;
    }
    dna[length] = '\0';
}

void generate_random_quality_scores(char *quality_scores, int length) {
    for (int i = 0; i < length; i++) {
        quality_scores[i] = '!' + rand() % 33;
    }
    quality_scores[length] = '\0';
}

ReadSet *create_reads(int num_reads, int read_length) {
    ReadSet *reads = malloc(sizeof(ReadSet));
    reads->num_reads = num_reads;
    reads->read_length = read_length;
    reads->reads = malloc(sizeof(Read) * num_reads);

    for (int i = 0; i < num_reads; i++) {
        char dna[read_length + 1];
        char quality_scores[read_length + 1];

        generate_random_dna(dna, read_length);
        generate_random_quality_scores(quality_scores, read_length);

        reads->reads[i].base = dna[0];
        reads->reads[i].quality = quality_scores[0];
    }

    return reads;
}

void print_reads(ReadSet *reads) {
    for (int i = 0; i < reads->num_reads; i++) {
        printf("%c %s\n", reads->reads[i].base, reads->reads[i].quality);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <num_reads> <read_length>\n", argv[0]);
        return 1;
    }

    int num_reads = atoi(argv[1]);
    int read_length = atoi(argv[2]);

    srand(time(NULL));

    ReadSet *reads = create_reads(num_reads, read_length);
    print_reads(reads);

    free(reads->reads);
    free(reads);

    return 0;
}