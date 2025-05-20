//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Set the seed for the random number generator

    // Define the possible base pairs for the DNA sequence
    char basePairs[] = {'A', 'C', 'G', 'T'};

    int sequenceLength;
    printf("Enter the length of the DNA sequence to generate: ");
    scanf("%d", &sequenceLength);

    char sequence[sequenceLength];
    int i;

    // Generate the DNA sequence
    for (i = 0; i < sequenceLength; i++) {
        sequence[i] = basePairs[rand() % 4];
    }

    // Print the DNA sequence
    printf("Generated DNA sequence is:");
    for (i = 0; i < sequenceLength; i++) {
        printf("%c", sequence[i]);
    }

    // Generate the complementary DNA sequence
    char compSequence[sequenceLength];
    for (i = 0; i < sequenceLength; i++) {
        switch(sequence[i]) {
            case 'A':
                compSequence[i] = 'T';
                break;
            case 'C':
                compSequence[i] = 'G';
                break;
            case 'G':
                compSequence[i] = 'C';
                break;
            case 'T':
                compSequence[i] = 'A';
                break;
        }
    }

    // Print the complementary DNA sequence
    printf("\nGenerated complementary DNA sequence is:");
    for (i = 0; i < sequenceLength; i++) {
        printf("%c", compSequence[i]);
    }

    return 0; // End of the program
}