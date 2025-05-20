//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_NUCLEOTIDES 4
#define MAX_MUTATIONS 10
#define MUTATION_RATE 0.001

char nucleotides[] = {'A', 'C', 'G', 'T'};
char sequence[MAX_SEQUENCE_LENGTH];
int sequence_length;
int num_mutations;

void generate_random_sequence(int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % NUM_NUCLEOTIDES];
    }
    sequence_length = length;
}

void introduce_mutations() {
    for (int i = 0; i < num_mutations; i++) {
        int position = rand() % sequence_length;
        char old_nucleotide = sequence[position];
        char new_nucleotide = nucleotides[rand() % NUM_NUCLEOTIDES];
        sequence[position] = new_nucleotide;
    }
}

void print_sequence() {
    printf("Sequence: ");
    for (int i = 0; i < sequence_length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter sequence length (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);
    generate_random_sequence(sequence_length);
    printf("Original sequence:\n");
    print_sequence();
    printf("Enter number of mutations (max %d): ", MAX_MUTATIONS);
    scanf("%d", &num_mutations);
    introduce_mutations();
    printf("Sequence with mutations:\n");
    print_sequence();
    return 0;
}