//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHROMOSOME_SIZE 10000

int checkSuspiciousPatterns(char *chromosome, int len) {
    // check for suspicious patterns
    for (int i = 0; i < len; i++) {
        if (chromosome[i] == 'A' && chromosome[i+1] == 'T' && chromosome[i+2] == 'T' && chromosome[i+3] == 'A') {
            printf("Suspicious pattern found! Exiting program.\n");
            exit(1);
        }
        if (chromosome[i] == 'G' && chromosome[i+1] == 'T' && chromosome[i+2] == 'A' && chromosome[i+3] == 'A') {
            printf("Suspicious pattern found! Exiting program.\n");
            exit(1);
        }
        if (chromosome[i] == 'G' && chromosome[i+1] == 'A' && chromosome[i+2] == 'T' && chromosome[i+3] == 'A') {
            printf("Suspicious pattern found! Exiting program.\n");
            exit(1);
        }
    }
    return 0;
}

int main() {
    char chromosome[MAX_CHROMOSOME_SIZE];
    int chromosomeSize = 0;

    // read in chromosome sequence
    printf("Enter the chromosome sequence : \n");
    fgets(chromosome, MAX_CHROMOSOME_SIZE, stdin);
    chromosomeSize = strlen(chromosome);
    if (chromosome[chromosomeSize-1] == '\n') {
        chromosome[chromosomeSize-1] = '\0';
        chromosomeSize--;
    }

    // print the chromosome sequence
    printf("\nThe chromosome sequence is:\n%s\n", chromosome);

    // check for suspicious patterns
    checkSuspiciousPatterns(chromosome, chromosomeSize);

    // TODO: simulate the sequencing process
    printf("\n--- Sequencing in progress ---\n");

    // print the final sequence
    printf("\nThe final sequence is:\n%s\n", chromosome);

    return 0;
}