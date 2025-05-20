//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define NUM_SEQUENCES 5
#define ERROR_RATE 0.05

const char nucleotides[] = {'A', 'T', 'C', 'G'};

// Function to generate a random DNA sequence
void generate_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to introduce random sequencing errors
void introduce_errors(char *original, char *sequenced, int length) {
    for (int i = 0; i < length; i++) {
        // Simulate a sequencing error based on the error rate
        if ((double)rand() / RAND_MAX < ERROR_RATE) {
            sequenced[i] = nucleotides[rand() % 4]; // Random change
        } else {
            sequenced[i] = original[i]; // No change
        }
    }
    sequenced[length] = '\0'; // Null-terminate the string
}

// Function to calculate the similarity percentage between two sequences
double calculate_similarity(const char *seq1, const char *seq2, int length) {
    int matches = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            matches++;
        }
    }
    return (double)matches / length * 100.0; // Return percentage
}

// Main function to simulate the genome sequencing
int main() {
    srand(time(0)); // Seed random number generator

    char original_sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH + 1];
    char sequenced_sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH + 1];
    int sequence_length;

    printf("Enter the desired length of DNA sequences (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);

    // Ensure the length is valid
    if (sequence_length < 1 || sequence_length > MAX_SEQUENCE_LENGTH) {
        printf("Invalid sequence length. Exiting.\n");
        return 1;
    }

    // Generate and sequence the DNA
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generate_dna_sequence(original_sequences[i], sequence_length);
        introduce_errors(original_sequences[i], sequenced_sequences[i], sequence_length);

        printf("Original Sequence %d: %s\n", i + 1, original_sequences[i]);
        printf("Sequenced Sequence %d: %s\n", i + 1, sequenced_sequences[i]);
        
        double similarity = calculate_similarity(original_sequences[i], sequenced_sequences[i], sequence_length);
        printf("Similarity Percentage: %.2f%%\n\n", similarity);
    }

    return 0;
}