//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to randomly assign nucleotides
char randNucleotide(){
    int num = rand() % 4;

    if(num == 0){
        return 'A';
    }
    else if(num == 1){
        return 'T';
    }
    else if(num == 2){
        return 'C';
    }
    else{
        return 'G';
    }
}

int main(){
    int genomeSize, numMutations;
    char *genome, *mutatedGenome;
    int *positions, *newPositions;
    int i, j, pos, mutPos;

    srand(time(NULL)); // Seed for randomizer
    
    printf("Enter genome length: ");
    scanf("%d", &genomeSize);

    // Memory allocation for original genome and mutated genome
    genome = (char*)malloc((genomeSize + 1) * sizeof(char));
    mutatedGenome = (char*)malloc((genomeSize + 1) * sizeof(char));

    // Generating random nucleotides for original genome
    for(i = 0; i < genomeSize; i++){
        genome[i] = randNucleotide();
    }
    genome[genomeSize] = '\0';

    printf("\nOriginal Genome: %s\n\n", genome);

    printf("Enter number of mutations: ");
    scanf("%d", &numMutations);

    // Memory allocation for position array
    positions = (int*)malloc(numMutations * sizeof(int));
    newPositions = (int*)malloc(numMutations * sizeof(int));

    // Assigning random positions for mutations and ensuring that they don't repeat
    for(i = 0; i < numMutations; i++){
        pos = rand() % genomeSize;

        for(j = 0; j < i; j++){
            if(pos == positions[j]){
                pos = rand() % genomeSize;
                j = -1;
            }
        }
        positions[i] = pos;
    }

    // Copying original genome to mutated genome
    strcpy(mutatedGenome, genome);

    printf("\nMutated Genome: ");

    // Mutating genome at specified positions
    for(i = 0; i < numMutations; i++){
        mutPos = rand() % 4; // Randomly selecting one of the 4 nucleotides
        
        // Ensuring that mutation is not the same as original nucleotide
        while(mutatedGenome[positions[i]] == mutPos){
            mutPos = rand() % 4;
        }
        
        mutatedGenome[positions[i]] = randNucleotide();

        printf("Mutated at Position %d: %c -> %c   ",positions[i], genome[positions[i]], mutatedGenome[positions[i]]);
    }

    mutatedGenome[genomeSize] = '\0';

    printf("\n\nNew Genome: %s\n\n", mutatedGenome);

    free(genome);
    free(mutatedGenome);
    free(positions);
    free(newPositions);

    return 0;
}