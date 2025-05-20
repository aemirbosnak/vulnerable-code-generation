//Code Llama-13B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DNA_LENGTH 1000
#define DNA_BASES 4

// Function to generate a random DNA sequence
char *generate_dna_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = "ACGT"[rand() % DNA_BASES];
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to print a DNA sequence
void print_dna_sequence(char *sequence) {
    printf("%s\n", sequence);
}

// Function to reverse a DNA sequence
char *reverse_dna_sequence(char *sequence) {
    int length = strlen(sequence);
    char *reversed = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed[length - i - 1] = sequence[i];
    }
    reversed[length] = '\0';
    return reversed;
}

// Function to find the longest common substring between two DNA sequences
int find_longest_common_substring(char *sequence1, char *sequence2) {
    int length1 = strlen(sequence1);
    int length2 = strlen(sequence2);
    int max_length = 0;
    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            int length = 0;
            while (sequence1[i + length] == sequence2[j + length] && i + length < length1 && j + length < length2) {
                length++;
            }
            if (length > max_length) {
                max_length = length;
            }
        }
    }
    return max_length;
}

// Main function
int main() {
    // Generate two random DNA sequences
    char *sequence1 = generate_dna_sequence(DNA_LENGTH);
    char *sequence2 = generate_dna_sequence(DNA_LENGTH);

    // Print the original sequences
    printf("Sequence 1:\n");
    print_dna_sequence(sequence1);
    printf("Sequence 2:\n");
    print_dna_sequence(sequence2);

    // Reverse the second sequence
    char *reversed = reverse_dna_sequence(sequence2);

    // Find the longest common substring between the two sequences
    int length = find_longest_common_substring(sequence1, reversed);

    // Print the result
    printf("Longest common substring length: %d\n", length);

    // Free memory
    free(sequence1);
    free(sequence2);
    free(reversed);

    return 0;
}