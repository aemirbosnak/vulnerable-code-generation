//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LENGTH 10000 // Maximum length of the genome sequence
#define NUCLEOTIDES "ACGT" // Nucleotide bases

// Generate random genome sequence
char* generateSequence(int length) {
    char* seq = (char*) malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        seq[i] = NUCLEOTIDES[rand() % 4];
    }
    seq[length] = '\0';
    return seq;
}

// compare two genome sequences
double compareSequences(char* seq1, char* seq2) {
    int length = strlen(seq1);
    double matches = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            matches++;
        }
    }
    return (matches/length) * 100;
}

int main() {
    int length; // Length of the genome sequence
    char* seq; // Genome sequence
    char* sample; // A sample sequence to be compared with the genome sequence
    srand(time(NULL)); // Seed the random number generator

    // Get length of the genome sequence from the user
    printf("Enter the length of the genome sequence: ");
    scanf("%d", &length);

    // Generate random genome sequence and display it
    printf("\nGenerated Genome Sequence:\n");
    seq = generateSequence(length);
    printf("%s\n", seq);

    // Ask the user if they want to compare the genome sequence with a sample sequence
    char choice;
    printf("\nDo you want to compare the genome sequence with a sample sequence? (y/n) ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        // Generate random sample sequence and display it
        printf("\nEnter the length of the sample sequence: ");
        int sampleLen;
        scanf("%d", &sampleLen);
        printf("\nGenerated Sample Sequence:\n");
        sample = generateSequence(sampleLen);
        printf("%s\n", sample);

        // Compare the genome sequence with the sample sequence and display the match percentage
        double matchPercent = compareSequences(seq, sample);
        printf("\nMatch Percentage: %.2f%%\n", matchPercent);
        free(sample); // Free the sample sequence memory
    }

    free(seq); // Free the genome sequence memory
    return 0;
}