//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *name;
    int length;
    char *sequence;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->name = "Random";
    seq->length = length;
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4 + 'A';
    }
    seq->sequence[length] = '\0';
    return seq;
}

void print_sequence(Sequence *seq) {
    printf("Name: %s\n", seq->name);
    printf("Length: %d\n", seq->length);
    printf("Sequence: %s\n", seq->sequence);
}

void generate_reads(Sequence *seq, int read_length, int num_reads, FILE *output_file) {
    srand(time(NULL));
    for (int i = 0; i < num_reads; i++) {
        int start_pos = rand() % (seq->length - read_length);
        char *read_seq = malloc(read_length + 1);
        for (int j = 0; j < read_length; j++) {
            read_seq[j] = seq->sequence[start_pos + j];
        }
        read_seq[read_length] = '\0';
        fprintf(output_file, ">Read_%d\n%s\n", i + 1, read_seq);
        free(read_seq);
    }
}

int main() {
    Sequence *seq = generate_random_sequence(MAX_SEQ_LENGTH);
    print_sequence(seq);

    FILE *output_file = fopen("reads.fasta", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int read_length = MAX_READ_LENGTH;
    int num_reads = (seq->length - read_length) / read_length + 1;
    generate_reads(seq, read_length, num_reads, output_file);

    fclose(output_file);
    free(seq->sequence);
    free(seq);

    return 0;
}