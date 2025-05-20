//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

char* generate_random_sequence(int length) {
    char* sequence = (char*)malloc((length + 1) * sizeof(char));
    char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // null-terminate the string
    return sequence;
}

void print_sequence(char* sequence) {
    printf("DNA Sequence: %s\n", sequence);
}

int compare_sequences(char* seq1, char* seq2) {
    if (strcmp(seq1, seq2) == 0) {
        return 0; // Sequences are identical
    } else {
        return 1; // Sequences are different
    }
}

void print_comparison_result(int result) {
    if (result == 0) {
        printf("The sequences are identical.\n");
    } else {
        printf("The sequences are different.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int length;
    printf("Enter the desired length of DNA sequences: ");
    scanf("%d", &length);

    char* sequence1 = generate_random_sequence(length);
    char* sequence2 = generate_random_sequence(length);

    printf("Generated sequences:\n");
    print_sequence(sequence1);
    print_sequence(sequence2);

    int comparison_result = compare_sequences(sequence1, sequence2);
    print_comparison_result(comparison_result);

    free(sequence1);
    free(sequence2);

    return 0;
}