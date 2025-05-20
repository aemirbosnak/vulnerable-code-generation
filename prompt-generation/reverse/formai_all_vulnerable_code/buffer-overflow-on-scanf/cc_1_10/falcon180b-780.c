//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

void generate_random_sequence(char* sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = (char) rand() % 4;
    }
}

void print_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main() {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;

    // Get user input for sequence length
    printf("Enter the length of the sequence: ");
    scanf("%d", &length);

    // Generate a random DNA sequence of the specified length
    generate_random_sequence(sequence, length);

    // Print the generated sequence
    printf("Generated sequence:\n");
    print_sequence(sequence, length);

    // Reverse the sequence
    for (int i = 0; i < length / 2; i++) {
        char temp = sequence[i];
        sequence[i] = sequence[length - i - 1];
        sequence[length - i - 1] = temp;
    }

    // Print the reversed sequence
    printf("Reversed sequence:\n");
    print_sequence(sequence, length);

    // Count the number of occurrences of each nucleotide base
    int count[4] = { 0 };
    for (int i = 0; i < length; i++) {
        if (sequence[i] == A) {
            count[0]++;
        } else if (sequence[i] == C) {
            count[1]++;
        } else if (sequence[i] == G) {
            count[2]++;
        } else if (sequence[i] == T) {
            count[3]++;
        }
    }

    // Print the nucleotide base counts
    printf("A: %d\n", count[0]);
    printf("C: %d\n", count[1]);
    printf("G: %d\n", count[2]);
    printf("T: %d\n", count[3]);

    return 0;
}