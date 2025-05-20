//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCES 100
#define MAX_LENGTH 1000

typedef struct {
    char *sequence;
    int length;
} DNASequence;

void generate_random_sequence(DNASequence *dna) {
    const char nucleotides[] = "ATGC";
    for (int i = 0; i < dna->length; i++) {
        dna->sequence[i] = nucleotides[rand() % 4];
    }
    dna->sequence[dna->length] = '\0'; // Null-terminate the string
}

void print_sequences(DNASequence *sequences, int count) {
    for (int i = 0; i < count; i++) {
        printf("Sequence %d: %s (Length: %d)\n", i + 1, sequences[i].sequence, sequences[i].length);
    }
}

void free_sequences(DNASequence *sequences, int count) {
    for (int i = 0; i < count; i++) {
        free(sequences[i].sequence);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    DNASequence sequences[MAX_SEQUENCES];
    int num_sequences;

    printf("Enter the number of DNA sequences to generate (max %d): ", MAX_SEQUENCES);
    scanf("%d", &num_sequences);
    if (num_sequences > MAX_SEQUENCES) {
        printf("Number of sequences exceeds the maximum limit!\n");
        return 1;
    }

    // Input lengths for each sequence
    for (int i = 0; i < num_sequences; i++) {
        printf("Enter length for sequence %d (max %d): ", i + 1, MAX_LENGTH);
        scanf("%d", &sequences[i].length);
        if (sequences[i].length > MAX_LENGTH) {
            printf("Length exceeds maximum limit!\n");
            return 1;
        }
        sequences[i].sequence = malloc((sequences[i].length + 1) * sizeof(char));
        if (sequences[i].sequence == NULL) {
            printf("Memory allocation failed!\n");
            free_sequences(sequences, i);
            return 1;
        }
        generate_random_sequence(&sequences[i]);
    }

    printf("\nGenerated DNA Sequences:\n");
    print_sequences(sequences, num_sequences);

    free_sequences(sequences, num_sequences);

    return 0;
}