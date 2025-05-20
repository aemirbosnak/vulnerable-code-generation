//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GENOME_SIZE 1000000
#define MAX_READ_LENGTH 100
#define MAX_READS 1000

typedef struct {
    char *sequence;
    int length;
} Read;

typedef struct {
    char *genome;
    int length;
} Genome;

Genome *generate_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->length = length;
    genome->genome = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        genome->genome[i] = rand() % 4;
    }
    return genome;
}

Read *generate_read(int length) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(length * sizeof(char));
    read->length = length;
    for (int i = 0; i < length; i++) {
        read->sequence[i] = rand() % 4;
    }
    return read;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->genome[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Genome *genome = generate_genome(MAX_GENOME_SIZE);
    Read *reads[MAX_READS];

    for (int i = 0; i < MAX_READS; i++) {
        reads[i] = generate_read(MAX_READ_LENGTH);
    }

    for (int i = 0; i < MAX_READS; i++) {
        int j = rand() % genome->length;
        int k = rand() % MAX_READ_LENGTH;
        int l = 0;
        while (l < k && j + l < genome->length) {
            if (genome->genome[j + l]!= reads[i]->sequence[l]) {
                break;
            }
            l++;
        }
        if (l == k) {
            printf("Match found at position %d with length %d\n", j, k);
        }
    }

    return 0;
}