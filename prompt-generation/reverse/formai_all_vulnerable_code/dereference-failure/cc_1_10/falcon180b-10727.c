//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 3

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

Sequence *generate_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }

    return sequence;
}

Read *generate_read(Sequence *sequence, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(read_length * sizeof(char));
    read->length = read_length;
    read->position = rand() % (sequence->length - read_length);

    for (int i = 0; i < read_length; i++) {
        read->sequence[i] = sequence->sequence[read->position + i];
    }

    return read;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int count_errors(Read *read, Sequence *sequence) {
    int errors = 0;

    for (int i = 0; i < read->length; i++) {
        if (read->sequence[i]!= sequence->sequence[read->position + i]) {
            errors++;

            if (errors > MAX_ERRORS) {
                break;
            }
        }
    }

    return errors;
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);
    Read *read = generate_read(sequence, MAX_READ_LENGTH);

    int errors = count_errors(read, sequence);

    printf("Sequence:\n");
    print_sequence(sequence);
    printf("Read:\n");
    print_read(read);
    printf("Errors: %d\n", errors);

    return 0;
}