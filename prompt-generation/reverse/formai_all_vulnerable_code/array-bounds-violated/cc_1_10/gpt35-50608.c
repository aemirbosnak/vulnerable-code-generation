//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000000
#define MAX_SEQUENCE_LENGTH 100

char genome[MAX_GENOME_LENGTH + 1];
char sequence[MAX_SEQUENCE_LENGTH + 1];

void generate_random_genome(int genome_length) {
    srand(time(NULL)); // Seed the random number generator
    
    for (int i = 0; i < genome_length; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
            default:
                fprintf(stderr, "Error generating random genome\n");
                exit(EXIT_FAILURE);
        }
    }
    genome[genome_length] = '\0'; // Make sure to null-terminate the string
}

void search_for_sequence(int genome_length, int sequence_length, int num_searches) {
    int count = 0;
    for (int i = 0; i < num_searches; i++) {
        // Generate a random starting position for the sequence search
        int start_position = rand() % (genome_length - sequence_length);
        
        // Copy the sequence to search from the genome
        strncpy(sequence, genome+start_position, sequence_length);
        sequence[sequence_length] = '\0'; // Make sure to null-terminate the string
        
        // Print out the starting position of the sequence in the genome
        printf("Sequence %d found at position %d\n", i+1, start_position);
        count++;
    }
    
    if (count == 0) {
        printf("Sequence not found in genome\n");
    }
}

int main(void) {
    int genome_length;
    int sequence_length;
    int num_searches;
    
    printf("Enter the length of the genome: ");
    scanf("%d", &genome_length);
    
    printf("Enter the length of the sequence to search: ");
    scanf("%d", &sequence_length);
    
    printf("Enter the number of sequences to search for: ");
    scanf("%d", &num_searches);
    
    if (num_searches <= 0) {
        fprintf(stderr, "Error: number of searches must be greater than zero\n");
        exit(EXIT_FAILURE);
    }
    
    if (genome_length < sequence_length) {
        fprintf(stderr, "Error: genome length must be greater than sequence length\n");
        exit(EXIT_FAILURE);
    }
    
    if (genome_length > MAX_GENOME_LENGTH || sequence_length > MAX_SEQUENCE_LENGTH) {
        fprintf(stderr, "Error: maximum genome length is %d and maximum sequence length is %d\n", MAX_GENOME_LENGTH, MAX_SEQUENCE_LENGTH);
        exit(EXIT_FAILURE);
    }
    
    generate_random_genome(genome_length);
    
    printf("Genome sequence:\n%s\n", genome);
    
    search_for_sequence(genome_length, sequence_length, num_searches);
    
    return 0;
}