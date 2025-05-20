//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000
#define NUM_SEQUENCES 5
#define NUCLEOTIDES "ACGT"

// Function to generate a random DNA sequence of given length
void generate_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; ++i) {
        sequence[i] = NUCLEOTIDES[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to calculate GC content
float calculate_gc_content(const char *sequence) {
    int gc_count = 0;
    int length = strlen(sequence);
    for (int i = 0; i < length; ++i) {
        if (sequence[i] == 'G' || sequence[i] == 'C') {
            gc_count++;
        }
    }
    return (float)gc_count / length * 100; // Return GC content percentage
}

// Function to count the occurrences of each nucleotide
void count_nucleotides(const char *sequence, int *counts) {
    for (int i = 0; i < strlen(sequence); ++i) {
        switch (sequence[i]) {
            case 'A': counts[0]++; break;
            case 'C': counts[1]++; break;
            case 'G': counts[2]++; break;
            case 'T': counts[3]++; break;
        }
    }
}

// Function to print the nucleotide counts
void print_nucleotide_counts(int *counts) {
    printf("Nucleotide Counts:\n");
    printf("A: %d\n", counts[0]);
    printf("C: %d\n", counts[1]);
    printf("G: %d\n", counts[2]);
    printf("T: %d\n", counts[3]);
}

// Function to display the sequences
void display_sequences(char sequences[NUM_SEQUENCES][MAX_LENGTH], int length) {
    printf("\nGenerated DNA Sequences:\n");
    for (int i = 0; i < NUM_SEQUENCES; ++i) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char sequences[NUM_SEQUENCES][MAX_LENGTH];
    int length;

    printf("Welcome to the DNA Sequencing Simulator!\n");
    printf("Enter the length of the DNA sequences (up to %d): ", MAX_LENGTH - 1);
    scanf("%d", &length);

    if (length < 1 || length > MAX_LENGTH - 1) {
        printf("Invalid length! Please enter a value between 1 and %d.\n", MAX_LENGTH - 1);
        return 1;
    }

    // Generate random DNA sequences
    for (int i = 0; i < NUM_SEQUENCES; ++i) {
        generate_dna_sequence(sequences[i], length);
    }

    display_sequences(sequences, length);

    // Analyze each sequence
    for (int i = 0; i < NUM_SEQUENCES; ++i) {
        float gc_content = calculate_gc_content(sequences[i]);
        printf("GC Content of Sequence %d: %.2f%%\n", i + 1, gc_content);
        
        int counts[4] = {0, 0, 0, 0}; // Initialize nucleotide counts
        count_nucleotides(sequences[i], counts);
        print_nucleotide_counts(counts);
    }

    printf("\nThanks for using the DNA Sequencing Simulator. Keep coding and exploring the genetic codes!\n");

    return 0;
}