//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_BASES 4
#define MUTATION_CHANCE 0.001

int main() {
    char sequence[MAX_SEQ_LENGTH];
    int seq_length = 0;
    float mutation_chance = MUTATION_CHANCE;
    srand(time(NULL)); // Seed the random number generator with current time
    
    // Prompt user for input
    printf("Enter the length of the DNA sequence to simulate (max %d): ", MAX_SEQ_LENGTH);
    scanf("%d", &seq_length);
    
    // Validate input
    if(seq_length > MAX_SEQ_LENGTH) {
        printf("Maximum sequence length exceeded. Exiting program.\n");
        return 0;
    }
    if(seq_length <= 0) {
        printf("Invalid sequence length. Exiting program.\n");
        return 0;
    }
    
    // Generate random sequence
    const char Bases[MAX_BASES] = {'A', 'T', 'C', 'G'};
    for(int i = 0; i < seq_length; i++) {
        sequence[i] = Bases[rand() % MAX_BASES];
    }
    sequence[seq_length] = '\0';

    // Print original sequence
    printf("Original DNA sequence:\n%s\n\n", sequence);
    
    // Simulate mutations
    for(int i = 0; i < seq_length; i++) {
        float rand_val = ((float)rand() / (float)RAND_MAX);
        if(rand_val < mutation_chance) {
            int new_base_index = rand() % MAX_BASES;
            char new_base = Bases[new_base_index];
            sequence[i] = new_base;
        }
    }
    
    // Print mutated sequence
    printf("Mutated DNA sequence:\n%s\n", sequence);
    
    return 0;
}