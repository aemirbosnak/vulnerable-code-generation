//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(Sequence *seq, int length) {
    char alphabet[] = "ACGT";
    int i;
    for (i = 0; i < length; i++) {
        seq->sequence[i] = alphabet[rand() % strlen(alphabet)];
    }
    seq->length = length;
}

void print_sequence(Sequence seq) {
    int i;
    for (i = 0; i < seq.length; i++) {
        printf("%c", seq.sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num_sequences;
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &num_sequences);

    Sequence *sequences = (Sequence *) malloc(num_sequences * sizeof(Sequence));

    int i;
    for (i = 0; i < num_sequences; i++) {
        int length;
        printf("Enter the length of sequence %d: ", i+1);
        scanf("%d", &length);
        if (length > MAX_SEQ_LENGTH) {
            printf("Error: sequence length must be less than or equal to %d\n", MAX_SEQ_LENGTH);
            exit(1);
        }
        sequences[i].length = length;
        sequences[i].sequence = (char *) malloc(length * sizeof(char));
        generate_random_sequence(&sequences[i], length);
    }

    for (i = 0; i < num_sequences; i++) {
        print_sequence(sequences[i]);
    }

    for (i = 0; i < num_sequences; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}