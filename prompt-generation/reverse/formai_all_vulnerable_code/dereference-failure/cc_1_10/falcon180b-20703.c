//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_ALPHABET_SIZE 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char **alphabet;
    int size;
} Alphabet;

void generate_random_sequence(Sequence *sequence, Alphabet *alphabet) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = alphabet->alphabet[rand() % alphabet->size];
    }
    sequence->sequence[sequence->length] = '\0';
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Alphabet alphabet;
    alphabet.size = 4;
    alphabet.alphabet = malloc(sizeof(char *) * alphabet.size);
    alphabet.alphabet[0] = strdup("A");
    alphabet.alphabet[1] = strdup("C");
    alphabet.alphabet[2] = strdup("G");
    alphabet.alphabet[3] = strdup("T");

    Sequence sequence;
    sequence.length = 1000;
    sequence.sequence = malloc(sizeof(char) * sequence.length + 1);

    generate_random_sequence(&sequence, &alphabet);
    print_sequence(&sequence);

    free(sequence.sequence);
    free(alphabet.alphabet);

    return 0;
}