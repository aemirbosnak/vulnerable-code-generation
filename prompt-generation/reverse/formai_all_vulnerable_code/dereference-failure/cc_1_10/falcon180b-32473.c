//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 100
#define MAX_ERROR_RATE 0.05

typedef struct {
    int length;
    char *sequence;
} Sequence;

typedef struct {
    int length;
    char *sequence;
    int start_position;
    int end_position;
} Read;

Sequence *generate_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    return sequence;
}

Read *generate_read(Sequence *sequence, int read_length, int error_rate) {
    Read *read = malloc(sizeof(Read));
    read->length = read_length;
    read->sequence = malloc(sizeof(char) * read_length);
    for (int i = 0; i < read_length; i++) {
        int position = rand() % sequence->length;
        char base = sequence->sequence[position];
        if (rand() % 100 < error_rate) {
            base = 'N';
        }
        read->sequence[i] = base;
    }
    read->start_position = 0;
    read->end_position = read_length - 1;
    return read;
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

void print_read(Read *read) {
    printf("Read: %s\n", read->sequence);
    printf("Length: %d\n", read->length);
    printf("Start position: %d\n", read->start_position);
    printf("End position: %d\n", read->end_position);
}

int main() {
    srand(time(NULL));
    Sequence *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);
    Read *read = generate_read(sequence, MAX_READ_LENGTH, MAX_ERROR_RATE);
    print_sequence(sequence);
    print_read(read);
    return 0;
}