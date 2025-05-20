//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 5

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

Genome *generate_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % 4;
    }
    genome->sequence[length] = '\0';

    return genome;
}

Read *generate_read(Genome *genome, int length, int start_position) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(length + 1);
    read->length = length;
    read->position = start_position;

    for (int i = 0; i < length; i++) {
        read->sequence[i] = genome->sequence[start_position + i];
    }
    read->sequence[length] = '\0';

    return read;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
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
    Read *read = generate_read(genome, MAX_READ_LENGTH, rand() % genome->length);

    printf("Genome:\n");
    print_genome(genome);

    printf("Read:\n");
    print_read(read);

    return 0;
}