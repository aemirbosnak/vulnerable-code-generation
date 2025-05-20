//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
// This program is a simple simulation of genome sequencing.
// It generates a random DNA sequence of a given length and outputs it to the console.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random DNA sequence of a given length
void generate_dna_sequence(char* sequence, int length) {
    srand(time(NULL)); // Seed the random number generator with the current time

    for(int i = 0; i < length; i++) {
        // Choose a random base (A, C, G or T) and append it to the sequence
        sequence[i] = "ACGT"[rand() % 4];
    }

    // Add a newline character at the end of the sequence
    sequence[length] = '\0';
}

// Recursive function to print the DNA sequence in reverse order
void print_sequence_reverse(char* sequence, int length) {
    if(length == 0) {
        // Base case: empty sequence
        return;
    }

    // Recursive case: print the last character and call the function again with the rest of the sequence
    printf("%c", sequence[length - 1]);
    print_sequence_reverse(sequence, length - 1);
}

// Main function
int main() {
    int length;

    // Prompt the user for the length of the DNA sequence
    printf("Enter the length of the DNA sequence: ");
    scanf("%d", &length);

    // Generate the DNA sequence
    char sequence[length + 1]; // Add one for the newline character
    generate_dna_sequence(sequence, length);

    // Print the DNA sequence in reverse order
    printf("The DNA sequence is:\n");
    print_sequence_reverse(sequence, length);

    return 0;
}