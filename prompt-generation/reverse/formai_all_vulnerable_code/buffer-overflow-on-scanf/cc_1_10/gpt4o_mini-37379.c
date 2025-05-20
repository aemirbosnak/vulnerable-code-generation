//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 100
#define NUM_ERRORS 5

const char bases[] = "ACGT";

// Function to generate a random DNA sequence
void generate_random_dna(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = bases[rand() % 4]; // Randomly choose A, C, G, or T
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to introduce random errors in the DNA sequence
void introduce_errors(char* original, char* sequenced, int num_errors) {
    for (int i = 0; i < num_errors; i++) {
        int pos = rand() % strlen(original); // Random position to introduce an error
        char original_base = original[pos];
        char new_base;

        // Generate a different base for the error
        do {
            new_base = bases[rand() % 4];
        } while (new_base == original_base); // Ensure new base is different

        sequenced[pos] = new_base; // Introduce the error
    }
}

// Function to display the DNA sequence
void display_sequence(const char* label, const char* sequence) {
    printf("%s: %s\n", label, sequence);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    char original_dna[MAX_SEQUENCE_LENGTH + 1];
    char sequenced_dna[MAX_SEQUENCE_LENGTH + 1];

    int sequence_length;

    // Get the length of the DNA sequence from the user
    printf("Enter the length of the DNA sequence (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);

    // Check if the length is within the allowed limits
    if (sequence_length > MAX_SEQUENCE_LENGTH || sequence_length <= 0) {
        printf("Invalid sequence length. Please enter a value between 1 and %d.\n", MAX_SEQUENCE_LENGTH);
        return 1;
    }

    // Generate a random DNA sequence
    generate_random_dna(original_dna, sequence_length);
    strcpy(sequenced_dna, original_dna); // Copy original DNA to sequenced DNA for modification

    // Introduce errors in the sequenced DNA
    introduce_errors(original_dna, sequenced_dna, NUM_ERRORS);

    // Display the original and sequenced DNA
    display_sequence("Original DNA Sequence", original_dna);
    display_sequence("Sequenced DNA with Errors", sequenced_dna);

    return 0;
}