//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Define the max length of the genome sequence
#define MAX_LENGTH 10000

int main(){
    // Define the bases that make up a DNA sequence
    char bases[4] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    int i, j, seq_length;

    // Ask user for length of genome sequence
    printf("Enter the length of the genome sequence: ");
    scanf("%d", &seq_length);

    // Create an array to store the genome sequence
    char genome_sequence[MAX_LENGTH];

    // Generate random genome sequence
    for(i=0; i<seq_length; i++){
        // Choose a random base from the bases array
        j = rand() % 4;
        genome_sequence[i] = bases[j];
    }

    // Print the generated genome sequence
    printf("\nGenerated Genome Sequence: ");
    for(i=0; i<seq_length; i++){
        printf("%c", genome_sequence[i]);
    }
    printf("\n\n");

    // Randomly generate mutations in the genome sequence
    int num_mutations = rand() % (seq_length / 10);
    int mutation_index, mutation_type, mutation_value;
    for(i=0; i<num_mutations; i++){
        // Choose a random index in the genome sequence to introduce a mutation
        mutation_index = rand() % seq_length;

        // Choose a random type of mutation
        mutation_type = rand() % 3;

        // Introduce mutation based on random type
        switch(mutation_type){
            case 0: // Substitution
                mutation_value = rand() % 3;
                genome_sequence[mutation_index] = bases[mutation_value];
                printf("Substitution at index %d: %c -> %c\n", mutation_index, bases[mutation_index], bases[mutation_value]);
                break;
            case 1: // Deletion
                for(j=mutation_index; j<seq_length-1; j++){
                    genome_sequence[j] = genome_sequence[j+1];
                }
                seq_length--;
                printf("Deletion at index %d\n", mutation_index);
                break;
            case 2: // Insertion
                seq_length++;
                for(j=seq_length-1; j>mutation_index; j--){
                    genome_sequence[j] = genome_sequence[j-1];
                }
                mutation_value = rand() % 4;
                genome_sequence[mutation_index] = bases[mutation_value];
                printf("Insertion at index %d: %c\n", mutation_index, bases[mutation_value]);
                break;
        }
    }

    // Print final genome sequence after mutations
    printf("\nFinal Genome Sequence: ");
    for(i=0; i<seq_length; i++){
        printf("%c", genome_sequence[i]);
    }
    printf("\n\n");

    return 0;
}