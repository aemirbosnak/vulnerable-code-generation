//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the four noble nucleotides
#define A   'A'
#define C   'C'
#define G   'G'
#define T   'T'

char* generate_random_sequence(int length) {
    char* sequence = (char*)malloc(length + 1);
    if (!sequence) {
        fprintf(stderr, "Alas! Memory allocation hath failed.\n");
        exit(1);
    }

    const char nucleotides[] = {A, C, G, T};
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4]; // Choosing a nucleotide at random
    }
    sequence[length] = '\0'; // Null-terminate the sequence
    return sequence;
}

void print_sequence(const char* sequence) {
    printf("Behold the noble sequence: %s\n", sequence);
}

void simulate_genome_sequencing(int number_of_runs, int seq_length) {
    for (int i = 0; i < number_of_runs; i++) {
        printf("=== Round %d of Genome Sequencing ===\n", i + 1);
        char* sequence = generate_random_sequence(seq_length);
        print_sequence(sequence);
        free(sequence); // Freeing the memory of the sequence
        printf("\n");
    }
}

int main() {
    srand(time(0)); // Initiating the random numbers through divine timing

    int number_of_runs;
    int seq_length;

    printf("How many noble genome sequences dost thou wish to simulate? ");
    scanf("%d", &number_of_runs);
    printf("What length hath each sequence, oh noble coder? ");
    scanf("%d", &seq_length);

    if (number_of_runs <= 0 || seq_length <= 0) {
        fprintf(stderr, "Noble coder, thou must provide positive integers!\n");
        return 1;
    }

    simulate_genome_sequencing(number_of_runs, seq_length);

    printf("The simulation hath concluded, farewell noble coder!\n");
    return 0;
}