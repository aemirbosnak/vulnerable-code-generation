//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
// Welcome to the C Genome Sequencing Simulator!

// This program simulates the sequencing of a DNA molecule.
// The user can specify the length of the DNA molecule and the error rate.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random DNA sequence.
char *generate_dna_sequence(int length)
{
    // Create an array to store the DNA sequence.
    char *dna_sequence = malloc(length + 1);

    // Initialize the DNA sequence to all A's.
    memset(dna_sequence, 'A', length);

    // Loop through the DNA sequence and randomly change some of the bases.
    for (int i = 0; i < length; i++)
    {
        // Generate a random number between 0 and 3.
        int random_number = rand() % 4;

        // Change the base at the current position to the corresponding base.
        switch (random_number)
        {
        case 0:
            dna_sequence[i] = 'A';
            break;
        case 1:
            dna_sequence[i] = 'C';
            break;
        case 2:
            dna_sequence[i] = 'G';
            break;
        case 3:
            dna_sequence[i] = 'T';
            break;
        }
    }

    // Return the DNA sequence.
    return dna_sequence;
}

// Function to simulate the sequencing of a DNA molecule.
char *sequence_dna(char *dna_sequence, double error_rate)
{
    // Create an array to store the sequenced DNA sequence.
    char *sequenced_dna_sequence = malloc(strlen(dna_sequence) + 1);

    // Loop through the DNA sequence and simulate the sequencing process.
    for (int i = 0; i < strlen(dna_sequence); i++)
    {
        // Generate a random number between 0 and 1.
        double random_number = (double)rand() / (double)RAND_MAX;

        // If the random number is less than the error rate, then change the base at the current position to a random base.
        if (random_number < error_rate)
        {
            // Generate a random number between 0 and 3.
            int random_number = rand() % 4;

            // Change the base at the current position to the corresponding base.
            switch (random_number)
            {
            case 0:
                sequenced_dna_sequence[i] = 'A';
                break;
            case 1:
                sequenced_dna_sequence[i] = 'C';
                break;
            case 2:
                sequenced_dna_sequence[i] = 'G';
                break;
            case 3:
                sequenced_dna_sequence[i] = 'T';
                break;
            }
        }
        else
        {
            // If the random number is greater than or equal to the error rate, then keep the base at the current position the same.
            sequenced_dna_sequence[i] = dna_sequence[i];
        }
    }

    // Return the sequenced DNA sequence.
    return sequenced_dna_sequence;
}

// Main function.
int main()
{
    // Seed the random number generator.
    srand(time(NULL));

    // Get the length of the DNA molecule from the user.
    int length;
    printf("Enter the length of the DNA molecule: ");
    scanf("%d", &length);

    // Get the error rate from the user.
    double error_rate;
    printf("Enter the error rate: ");
    scanf("%lf", &error_rate);

    // Generate a random DNA sequence.
    char *dna_sequence = generate_dna_sequence(length);

    // Simulate the sequencing of the DNA molecule.
    char *sequenced_dna_sequence = sequence_dna(dna_sequence, error_rate);

    // Print the original DNA sequence.
    printf("Original DNA sequence: %s\n", dna_sequence);

    // Print the sequenced DNA sequence.
    printf("Sequenced DNA sequence: %s\n", sequenced_dna_sequence);

    // Free the memory allocated for the DNA sequences.
    free(dna_sequence);
    free(sequenced_dna_sequence);

    return 0;
}