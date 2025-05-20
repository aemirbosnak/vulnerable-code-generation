//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GENOME_LENGTH 1000

char alpha[] = {'A', 'C', 'G', 'T'};

int main() {
    char genome[MAX_GENOME_LENGTH];
    int genomeLength;
    bool validGenome = false;
    
    //Get user input for genome sequence
    while(!validGenome) {
        printf("Please enter a genome sequence: ");

        fgets(genome, MAX_GENOME_LENGTH, stdin);

        genomeLength = strlen(genome) - 1;
        genome[genomeLength] = '\0';

        //Check if genome sequence is valid
        bool valid = true;
        for(int i = 0; i < genomeLength; i++) {
            bool validChar = false;
            for(int j = 0; j < 4; j++) {
                if(genome[i] == alpha[j]) {
                    validChar = true;
                    break;
                }
            }
            if(!validChar) {
                valid = false;
                break;
            }
        }
        
        if(valid) {
            validGenome = true;
        } else {
            printf("Invalid genome sequence. Please enter a valid sequence.\n");
        }
    }
    
    //Simulate genome sequencing
    int numReads;
    printf("How many reads would you like to simulate? ");
    scanf("%d", &numReads);
    
    printf("\nSimulating genome sequencing...\n\n");
    
    for(int i = 0; i < numReads; i++) {
        //Randomly choose length of read
        int readLength = rand() % 100 + 1;
        
        //Randomly choose starting position in genome
        int startPos = rand() % (genomeLength - readLength + 1);
        
        //Generate read
        char read[readLength+1];
        strncpy(read, genome+startPos, readLength);
        read[readLength] = '\0';
        
        printf("Read #%d: %s\n", i+1, read);
    }
    
    return 0;
}