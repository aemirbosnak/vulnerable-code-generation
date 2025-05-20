//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

// Function prototypes
void generate_sequence(char* sequence, int length);
void print_sequence(char* sequence);
void reverse_sequence(char* sequence);
int compare_sequences(char* seq1, char* seq2);

int main(void) {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
    int i;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Prompt user for sequence length
    printf("Enter the length of the DNA sequence: ");
    scanf("%d", &length);

    // Generate random DNA sequence
    generate_sequence(sequence, length);

    // Print original sequence
    printf("Original sequence: ");
    print_sequence(sequence);

    // Reverse the sequence
    reverse_sequence(sequence);

    // Print reversed sequence
    printf("\nReversed sequence: ");
    print_sequence(sequence);

    // Compare original and reversed sequences
    if (compare_sequences(sequence, sequence + length - 1) == 0) {
        printf("\nThe sequence is a palindrome.\n");
    } else {
        printf("\nThe sequence is not a palindrome.\n");
    }

    return 0;
}

// Function to generate a random DNA sequence of given length
void generate_sequence(char* sequence, int length) {
    int i;
    for (i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

// Function to print a DNA sequence
void print_sequence(char* sequence) {
    int i;
    for (i = 0; sequence[i]!= '\0'; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// Function to reverse a DNA sequence
void reverse_sequence(char* sequence) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(sequence) - 1; i < j; i++, j--) {
        temp = sequence[i];
        sequence[i] = sequence[j];
        sequence[j] = temp;
    }
}

// Function to compare two DNA sequences for equality
int compare_sequences(char* seq1, char* seq2) {
    int i;
    for (i = 0; seq1[i] == seq2[i]; i++) {
        if (seq1[i] == '\0' || seq2[i] == '\0') {
            return 0; // Sequences are equal
        }
    }
    return 1; // Sequences are not equal
}