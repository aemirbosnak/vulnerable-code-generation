//Code Llama-13B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_GENOME_SIZE 10000
#define MAX_READ_SIZE 100
#define MAX_MISMATCHES 5
#define MAX_CIGAR_OPS 100

typedef struct {
    int pos;
    int len;
} cigar_t;

typedef struct {
    int id;
    char* name;
    char* seq;
    int len;
    bool reverse_complement;
} genome_t;

typedef struct {
    int id;
    char* name;
    char* seq;
    int len;
    bool reverse_complement;
    cigar_t* cigar;
    int n_cigar;
} read_t;

void generate_genome(genome_t* genome, int genome_size) {
    genome->id = 1;
    genome->name = "genome";
    genome->seq = (char*)malloc(genome_size * sizeof(char));
    genome->len = genome_size;
    genome->reverse_complement = false;

    for (int i = 0; i < genome_size; i++) {
        genome->seq[i] = rand() % 4;
    }
}

void generate_read(read_t* read, int read_size, genome_t* genome, int start_pos, int end_pos) {
    read->id = 1;
    read->name = "read";
    read->seq = (char*)malloc(read_size * sizeof(char));
    read->len = read_size;
    read->reverse_complement = false;
    read->cigar = (cigar_t*)malloc(MAX_CIGAR_OPS * sizeof(cigar_t));
    read->n_cigar = 0;

    for (int i = 0; i < read_size; i++) {
        read->seq[i] = genome->seq[start_pos + i];
    }

    for (int i = 0; i < MAX_CIGAR_OPS; i++) {
        read->cigar[i].pos = 0;
        read->cigar[i].len = 0;
    }

    int n_matches = 0;
    int n_mismatches = 0;
    int n_insertions = 0;
    int n_deletions = 0;

    for (int i = 0; i < read_size; i++) {
        if (read->seq[i] == genome->seq[start_pos + i]) {
            n_matches++;
        } else {
            n_mismatches++;
        }
    }

    if (n_matches > 0) {
        read->cigar[read->n_cigar].pos = start_pos;
        read->cigar[read->n_cigar].len = n_matches;
        read->n_cigar++;
    }

    if (n_mismatches > 0) {
        read->cigar[read->n_cigar].pos = start_pos + n_matches;
        read->cigar[read->n_cigar].len = n_mismatches;
        read->n_cigar++;
    }

    if (n_insertions > 0) {
        read->cigar[read->n_cigar].pos = start_pos + n_matches + n_mismatches;
        read->cigar[read->n_cigar].len = n_insertions;
        read->n_cigar++;
    }

    if (n_deletions > 0) {
        read->cigar[read->n_cigar].pos = start_pos + n_matches + n_mismatches + n_insertions;
        read->cigar[read->n_cigar].len = n_deletions;
        read->n_cigar++;
    }
}

void print_read(read_t* read) {
    printf("Read ID: %d\n", read->id);
    printf("Read Name: %s\n", read->name);
    printf("Read Sequence: %s\n", read->seq);
    printf("Read Length: %d\n", read->len);
    printf("Read Reverse Complement: %s\n", read->reverse_complement ? "true" : "false");
    printf("Read Cigar: ");
    for (int i = 0; i < read->n_cigar; i++) {
        printf("%dM%dI%dD", read->cigar[i].pos, read->cigar[i].len);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    genome_t genome;
    generate_genome(&genome, MAX_GENOME_SIZE);

    read_t read;
    generate_read(&read, MAX_READ_SIZE, &genome, 100, 200);

    print_read(&read);

    return 0;
}