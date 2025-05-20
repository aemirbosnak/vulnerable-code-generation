//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define ALPHABET_SIZE 4
#define MAX_READ_LENGTH 100

char *alphabet = "ACGT";

typedef struct {
    char *name;
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = (Sequence *)malloc(sizeof(Sequence));
    sequence->name = (char *)malloc(30 * sizeof(char));
    sequence->sequence = (char *)malloc((length + 1) * sizeof(char));
    sequence->length = length;

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = alphabet[rand() % ALPHABET_SIZE];
    }

    strcpy(sequence->name, "Random_Sequence");

    return sequence;
}

void print_sequence(Sequence *sequence) {
    printf("Name: %s\n", sequence->name);
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

void generate_reads(Sequence *sequence, int read_length, int num_reads, char **reads) {
    int i, j;
    for (i = 0; i < num_reads; i++) {
        reads[i] = (char *)malloc((read_length + 1) * sizeof(char));
        for (j = 0; j < read_length; j++) {
            reads[i][j] = sequence->sequence[j];
        }
        reads[i][read_length] = '\0';
    }
}

int main() {
    Sequence *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    print_sequence(sequence);

    int read_length = MAX_READ_LENGTH;
    int num_reads = 10;
    char **reads = (char **)malloc(num_reads * sizeof(char *));
    generate_reads(sequence, read_length, num_reads, reads);

    for (int i = 0; i < num_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }

    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);

    free(sequence->name);
    free(sequence->sequence);
    free(sequence);

    return 0;
}