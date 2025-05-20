//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DNA_SEQ_LENGTH 10000
#define NUM_NUCLEOTIDES 4

char *DNA_nucleotides = "ACGT";

void generate_random_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        int random_nucleotide_index = rand() % NUM_NUCLEOTIDES;
        sequence[i] = DNA_nucleotides[random_nucleotide_index];
    }
    sequence[length] = '\0';
}

int main() {
    srand(time(NULL));

    // Generate a random DNA sequence of length 100
    char *dna_sequence = malloc(MAX_DNA_SEQ_LENGTH * sizeof(char));
    generate_random_dna_sequence(dna_sequence, 100);
    printf("Random DNA sequence of length 100:\n%s\n", dna_sequence);

    // Reverse the DNA sequence
    char *reverse_sequence = malloc(MAX_DNA_SEQ_LENGTH * sizeof(char));
    for (int i = 0; i < strlen(dna_sequence); i++) {
        reverse_sequence[strlen(reverse_sequence) - strlen(dna_sequence) + i] = dna_sequence[i];
    }
    reverse_sequence[strlen(dna_sequence)] = '\0';
    printf("Reverse DNA sequence:\n%s\n", reverse_sequence);

    // Count the number of nucleotides
    int a_count = 0, c_count = 0, g_count = 0, t_count = 0;
    for (int i = 0; i < strlen(dna_sequence); i++) {
        if (dna_sequence[i] == 'A') {
            a_count++;
        } else if (dna_sequence[i] == 'C') {
            c_count++;
        } else if (dna_sequence[i] == 'G') {
            g_count++;
        } else if (dna_sequence[i] == 'T') {
            t_count++;
        }
    }
    printf("Number of nucleotides:\nA: %d\nC: %d\nG: %d\nT: %d\n", a_count, c_count, g_count, t_count);

    free(dna_sequence);
    free(reverse_sequence);

    return 0;
}