//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000

// Function to generate a random DNA sequence
char* generateSequence(int length) {
    char* sequence = (char*) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to print a DNA sequence
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

// Function to compare two DNA sequences
int compareSequences(char* sequence1, char* sequence2) {
    int length = strlen(sequence1);
    int matches = 0;
    for (int i = 0; i < length; i++) {
        if (sequence1[i] == sequence2[i]) {
            matches++;
        }
    }
    return matches;
}

int main() {
    srand(time(NULL));

    // Generate two random DNA sequences
    char* sequence1 = generateSequence(MAX_SEQUENCE_LENGTH);
    char* sequence2 = generateSequence(MAX_SEQUENCE_LENGTH);

    // Print the sequences
    printf("Sequence 1:\n");
    printSequence(sequence1);
    printf("Sequence 2:\n");
    printSequence(sequence2);

    // Compare the sequences and print the result
    int matches = compareSequences(sequence1, sequence2);
    printf("Number of matches: %d\n", matches);

    return 0;
}