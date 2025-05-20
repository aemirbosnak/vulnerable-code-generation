//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define ERROR_RATE 0.05 // 5% error rate

// Function declarations
void generateRandomDNA(char *sequence, int length);
void simulateSequencing(char *original, char *simulated);
void introduceErrors(char *sequence, int length);
void printSequence(const char *title, const char *sequence);

int main() {
    int length;
    char originalSequence[MAX_GENOME_LENGTH];
    char simulatedSequence[MAX_GENOME_LENGTH];

    // Seed random number generator
    srand(time(NULL));

    // Get the length of the DNA sequence from the user
    printf("Enter the length of the genome sequence (max %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &length);
    if (length > MAX_GENOME_LENGTH) {
        printf("Length exceeds maximum limit of %d. Setting to %d.\n", MAX_GENOME_LENGTH, MAX_GENOME_LENGTH);
        length = MAX_GENOME_LENGTH;
    }

    // Generate a random DNA sequence
    generateRandomDNA(originalSequence, length);
    printf("\nOriginal DNA Sequence:\n");
    printSequence("Original", originalSequence);

    // Simulate sequencing with possible errors
    simulateSequencing(originalSequence, simulatedSequence);
    
    return 0;
}

void generateRandomDNA(char *sequence, int length) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4]; // Choose a random nucleotide
    }
    sequence[length] = '\0'; // Null-terminate the string
}

void simulateSequencing(char *original, char *simulated) {
    int length = strlen(original);
    // Start with a copy of the original sequence
    strcpy(simulated, original);

    // Introduce errors
    introduceErrors(simulated, length);

    printf("\nSimulated DNA Sequence:\n");
    printSequence("Simulated", simulated);
}

void introduceErrors(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        float randValue = (float)rand() / RAND_MAX; // Generate a random float between 0.0 and 1.0
        if (randValue < ERROR_RATE) {
            // Introduce an error: 1 in 5 chance
            int errorType = rand() % 3; // Randomly choose among deletion, insertion, and substitution
            if (errorType == 0) {
                // Substitution
                const char *nucleotides = "ACGT";
                char originalChar = sequence[i];
                char newChar;
                do {
                    newChar = nucleotides[rand() % 4]; // Choose a new nucleotide
                } while (newChar == originalChar); // Ensure it's different
                sequence[i] = newChar;
                printf("Substituted %c at position %d with %c\n", originalChar, i, newChar);
            } else if (errorType == 1) {
                // Deletion
                printf("Deleted %c at position %d\n", sequence[i], i);
                memmove(&sequence[i], &sequence[i + 1], length - i); // Shift left
                sequence[--length] = '\0'; // Reduce length and null-terminate
                i--; // Stay at the same index for the next check
            } else if (errorType == 2) {
                // Insertion
                if (length < MAX_GENOME_LENGTH - 1) {
                    char newChar = "ACGT"[rand() % 4]; // Random nucleotide for insertion
                    printf("Inserted %c at position %d\n", newChar, i);
                    memmove(&sequence[i + 1], &sequence[i], length - i); // Shift right
                    sequence[i] = newChar; // Insert new character
                    length++; // Increase length
                    sequence[length] = '\0'; // Null-terminate
                }
            }
        }
    }
}

void printSequence(const char *title, const char *sequence) {
    printf("%s Sequence: %s\n", title, sequence);
}