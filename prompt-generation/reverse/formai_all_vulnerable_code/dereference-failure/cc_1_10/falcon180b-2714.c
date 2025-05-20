//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char* sequence;
    int length;
} Sequence;

typedef struct {
    Sequence* sequences;
    int num_sequences;
} SequencingResult;

void initialize_alphabet(char* alphabet) {
    int i;
    for (i = 0; i < MAX_ALPHABET_SIZE; i++) {
        alphabet[i] = 'A' + i;
    }
}

int compare_sequences(const void* a, const void* b) {
    Sequence* seq1 = *(Sequence**)a;
    Sequence* seq2 = *(Sequence**)b;
    return strcmp(seq1->sequence, seq2->sequence);
}

SequencingResult* run_sequencing_simulation(int num_sequences, int min_length, int max_length) {
    SequencingResult* result = malloc(sizeof(SequencingResult));
    result->num_sequences = 0;
    result->sequences = malloc(sizeof(Sequence) * num_sequences);

    srand(time(NULL));
    char alphabet[MAX_ALPHABET_SIZE];
    initialize_alphabet(alphabet);

    int i;
    for (i = 0; i < num_sequences; i++) {
        int length = rand() % (max_length - min_length + 1) + min_length;
        char* sequence = malloc(sizeof(char) * length);
        int j;
        for (j = 0; j < length; j++) {
            sequence[j] = alphabet[rand() % MAX_ALPHABET_SIZE];
        }
        result->sequences[i] = (Sequence) {
           .sequence = sequence,
           .length = length
        };
        result->num_sequences++;
    }

    qsort(result->sequences, result->num_sequences, sizeof(Sequence), compare_sequences);

    return result;
}

void print_sequencing_result(SequencingResult* result) {
    int i;
    for (i = 0; i < result->num_sequences; i++) {
        Sequence* seq = &result->sequences[i];
        printf("%d. Sequence: %s (%d bp)\n", i + 1, seq->sequence, seq->length);
    }
}

int main() {
    int num_sequences;
    printf("Enter the number of sequences to simulate: ");
    scanf("%d", &num_sequences);

    int min_length;
    printf("Enter the minimum sequence length: ");
    scanf("%d", &min_length);

    int max_length;
    printf("Enter the maximum sequence length: ");
    scanf("%d", &max_length);

    SequencingResult* result = run_sequencing_simulation(num_sequences, min_length, max_length);
    printf("\nSequencing results:\n");
    print_sequencing_result(result);

    free(result->sequences);
    free(result);
    return 0;
}