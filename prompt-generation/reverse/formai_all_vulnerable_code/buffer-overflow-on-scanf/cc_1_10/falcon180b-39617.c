//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000 // Maximum length of the genome sequence

// Function to generate a random nucleotide
char generate_nucleotide() {
    int random_number = rand() % 4;
    switch(random_number) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N'; // Should never happen
    }
}

// Function to print the genome sequence
void print_genome_sequence(char* sequence, int length) {
    int i;
    for(i=0; i<length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed with current time

    // Prompt user for genome sequence length
    printf("Enter the length of the genome sequence: ");
    int length;
    scanf("%d", &length);

    // Validate sequence length
    if(length <= 0 || length > MAX_SEQUENCE_LENGTH) {
        printf("Invalid sequence length.\n");
        return 1;
    }

    // Allocate memory for genome sequence
    char* sequence = (char*) malloc((length+1) * sizeof(char));
    if(sequence == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate random genome sequence
    int i;
    for(i=0; i<length; i++) {
        sequence[i] = generate_nucleotide();
    }
    sequence[length] = '\0'; // Add null terminator

    // Print genome sequence
    printf("Random genome sequence:\n");
    print_genome_sequence(sequence, length);

    // Free memory
    free(sequence);

    return 0;
}