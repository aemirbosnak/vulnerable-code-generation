//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_SEQUENCES 10

// Function prototypes
void generate_random_dna_sequence(char *sequence, int length);
void print_sequence(const char *sequence);
void analyze_sequence(const char *sequence);
void find_substring(const char *sequence, const char *substring);

int main() {
    srand(time(NULL)); // Seed for random number generation
    char sequences[MAX_SEQUENCES][MAX_SEQ_LENGTH];
    int num_sequences, sequence_length;

    // User input for number of sequences and their length
    printf("Welcome to the C Genome Sequencing Simulator!\n");
    printf("How many DNA sequences do you want to generate (max %d)? ", MAX_SEQUENCES);
    scanf("%d", &num_sequences);
    if (num_sequences > MAX_SEQUENCES) {
        printf("Please enter a number less than or equal to %d\n", MAX_SEQUENCES);
        return 1;
    }

    printf("Enter the length for each DNA sequence (max %d): ", MAX_SEQ_LENGTH);
    scanf("%d", &sequence_length);
    if (sequence_length > MAX_SEQ_LENGTH) {
        printf("Please enter a number less than or equal to %d\n", MAX_SEQ_LENGTH);
        return 1;
    }

    // Generating the sequences
    for (int i = 0; i < num_sequences; ++i) {
        generate_random_dna_sequence(sequences[i], sequence_length);
        printf("\nGenerated Sequence %d:\n", i + 1);
        print_sequence(sequences[i]);
        analyze_sequence(sequences[i]);
    }

    // User input to find a substring in generated sequences
    char substring[MAX_SEQ_LENGTH];
    printf("\nEnter a substring to search for in the sequences: ");
    scanf("%s", substring);
    
    for (int i = 0; i < num_sequences; ++i) {
        printf("\nSearching for substring \"%s\" in Sequence %d...\n", substring, i + 1);
        find_substring(sequences[i], substring);
    }

    printf("\nThank you for using the C Genome Sequencing Simulator!\n");
    return 0;
}

// Function to generate a random DNA sequence
void generate_random_dna_sequence(char *sequence, int length) {
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; ++i) {
        sequence[i] = nucleotides[rand() % 4]; // Randomly pick from A, C, G, T
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to print the generated DNA sequence
void print_sequence(const char *sequence) {
    printf("Sequence: %s\n", sequence);
}

// Function to analyze the DNA sequence
void analyze_sequence(const char *sequence) {
    int counts[4] = {0}; // A, C, G, T counts
    for (int i = 0; sequence[i]; ++i) {
        switch (sequence[i]) {
            case 'A': counts[0]++; break;
            case 'C': counts[1]++; break;
            case 'G': counts[2]++; break;
            case 'T': counts[3]++; break;
        }
    }
    printf("Nucleotide composition:\n");
    printf("A: %d, C: %d, G: %d, T: %d\n", counts[0], counts[1], counts[2], counts[3]);
}

// Function to find a substring inside the DNA sequence
void find_substring(const char *sequence, const char *substring) {
    char *position = strstr(sequence, substring);
    if (position) {
        printf("Found substring \"%s\" at position: %ld\n", substring, position - sequence);
    } else {
        printf("Substring \"%s\" not found in this sequence.\n", substring);
    }
}