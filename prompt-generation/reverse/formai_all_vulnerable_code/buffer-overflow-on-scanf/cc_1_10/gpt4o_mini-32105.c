//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10

// Define nucleotide bases
const char nucleotides[] = {'A', 'T', 'C', 'G'};

// Function to generate a random nucleotide sequence
void generate_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4]; // Randomly select a nucleotide
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to calculate the GC content of a sequence
float calculate_gc_content(const char *sequence) {
    int gc_count = 0;
    int length = strlen(sequence);
    
    for (int i = 0; i < length; i++) {
        if (sequence[i] == 'G' || sequence[i] == 'C') {
            gc_count++;
        }
    }
    return (float)gc_count / length * 100; // Return GC content as a percentage
}

// Function to simulate sequencing errors
void introduce_errors(char *sequence, float error_rate) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if ((float)rand() / RAND_MAX < error_rate) {
            // Introduce an error: replace with a random nucleotide
            sequence[i] = nucleotides[rand() % 4];
        }
    }
}

// Function to print the sequences
void print_sequences(char sequences[][MAX_SEQUENCE_LENGTH], int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

// Entry point of the program
int main() {
    srand(time(NULL)); // Seed for random number generator
    char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH];
    int sequence_length;

    // Get the desired sequence length from the user
    printf("Enter the length of the sequences (max %d): ", MAX_SEQUENCE_LENGTH - 1);
    scanf("%d", &sequence_length);
    
    if (sequence_length >= MAX_SEQUENCE_LENGTH) {
        printf("Sequence length is too long! Adjusting to maximum.\n");
        sequence_length = MAX_SEQUENCE_LENGTH - 1;
    }

    // Generate sequences
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generate_sequence(sequences[i], sequence_length);
        printf("Generated Sequence %d: %s\n", i + 1, sequences[i]);
    }

    // Calculate and display GC content for each sequence
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        float gc_content = calculate_gc_content(sequences[i]);
        printf("GC Content of Sequence %d: %.2f%%\n", i + 1, gc_content);
    }

    // Introduce sequencing errors based on user-defined error rate
    float error_rate;
    printf("Enter the error rate for sequencing (0.0 to 1.0): ");
    scanf("%f", &error_rate);
    
    if (error_rate < 0.0 || error_rate > 1.0) {
        printf("Error rate must be between 0.0 and 1.0. Setting to 0.05.\n");
        error_rate = 0.05;
    }

    // Introduce errors in sequences
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        introduce_errors(sequences[i], error_rate);
        printf("Sequencing with errors for Sequence %d: %s\n", i + 1, sequences[i]);
    }

    // Print final sequences with errors
    print_sequences(sequences, NUM_SEQUENCES);

    return 0;
}