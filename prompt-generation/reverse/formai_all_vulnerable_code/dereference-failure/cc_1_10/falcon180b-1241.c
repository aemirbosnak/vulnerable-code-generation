//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int *counts;
    int alphabet_size;
} Alphabet;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        char letter = 'a' + rand() % MAX_ALPHABET_SIZE;
        sequence->sequence[i] = letter;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

Alphabet *count_letters(Sequence *sequence) {
    Alphabet *alphabet = malloc(sizeof(Alphabet));
    alphabet->alphabet_size = MAX_ALPHABET_SIZE;
    alphabet->counts = malloc(alphabet->alphabet_size * sizeof(int));

    for (int i = 0; i < alphabet->alphabet_size; i++) {
        alphabet->counts[i] = 0;
    }

    for (int i = 0; i < sequence->length; i++) {
        char letter = sequence->sequence[i];
        int index = letter - 'a';
        alphabet->counts[index]++;
    }

    return alphabet;
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
}

void print_alphabet(Alphabet *alphabet) {
    printf("Alphabet:\n");
    for (int i = 0; i < alphabet->alphabet_size; i++) {
        printf("%c: %d\n", 'a' + i, alphabet->counts[i]);
    }
}

int main() {
    int sequence_length = 100;
    Sequence *sequence = generate_random_sequence(sequence_length);
    Alphabet *alphabet = count_letters(sequence);

    print_sequence(sequence);
    print_alphabet(alphabet);

    free(sequence->sequence);
    free(sequence);
    free(alphabet->counts);
    free(alphabet);

    return 0;
}