//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

// Function to generate a random DNA sequence
void generateSequence(char* sequence, int length) {
    srand(time(0));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

// Function to print a DNA sequence
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

// Function to reverse a DNA sequence
void reverseSequence(char* sequence) {
    int length = strlen(sequence);
    for (int i = 0; i < length / 2; i++) {
        char temp = sequence[i];
        sequence[i] = sequence[length - i - 1];
        sequence[length - i - 1] = temp;
    }
}

// Function to compare two DNA sequences
int compareSequences(char* sequence1, char* sequence2) {
    int length = strlen(sequence1);
    for (int i = 0; i < length; i++) {
        if (sequence1[i]!= sequence2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Initialize variables
    char* sequence1 = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    char* sequence2 = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    int length;

    // Prompt user for sequence length
    printf("Enter the length of the DNA sequences: ");
    scanf("%d", &length);

    // Generate random DNA sequences
    generateSequence(sequence1, length);
    generateSequence(sequence2, length);

    // Print original sequences
    printf("Original Sequences:\n");
    printSequence(sequence1);
    printSequence(sequence2);

    // Reverse one of the sequences
    reverseSequence(sequence2);

    // Print reversed sequence
    printf("Reversed Sequence:\n");
    printSequence(sequence2);

    // Compare original and reversed sequences
    if (compareSequences(sequence1, sequence2)) {
        printf("The sequences are the same.\n");
    } else {
        printf("The sequences are different.\n");
    }

    free(sequence1);
    free(sequence2);

    return 0;
}