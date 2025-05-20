//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A playful representation of DNA
const char nucleotides[] = {'A', 'T', 'C', 'G'};

// Function to generate a random DNA sequence
void generate_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to simulate sequencing, with simple error generation
void sequence_dna(char *sequence, char *result, int error_rate) {
    for (int i = 0; i < strlen(sequence); i++) {
        if (rand() % 100 < error_rate) {
            // Introduce an error
            result[i] = nucleotides[rand() % 4];
        } else {
            result[i] = sequence[i];
        }
    }
    result[strlen(sequence)] = '\0'; // Null-terminate the result
}

// Function to display the sequences
void display_sequences(char *original, char *result) {
    printf("Original Sequence: %s\n", original);
    printf("Sequenced Result:  %s\n", result);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    int length;
    int error_rate;

    printf("Welcome to the Happy Genome Sequencing Simulator!\n");
    
    // Get length of DNA sequence from the user
    printf("Enter the length of the DNA sequence you want to simulate: ");
    scanf("%d", &length);

    // Get error rate from the user
    printf("Enter the error rate (0-99, where 0 is no errors): ");
    scanf("%d", &error_rate);

    // Allocate memory for sequences
    char *dna_sequence = (char *)malloc((length + 1) * sizeof(char));
    char *sequenced_result = (char *)malloc((length + 1) * sizeof(char));

    // Generate and sequence the DNA
    generate_dna_sequence(dna_sequence, length);
    sequence_dna(dna_sequence, sequenced_result, error_rate);

    // Display the results
    display_sequences(dna_sequence, sequenced_result);

    // Free allocated memory
    free(dna_sequence);
    free(sequenced_result);

    printf("Thank you for using the Happy Genome Sequencing Simulator! Have a great day!\n");
    return 0;
}