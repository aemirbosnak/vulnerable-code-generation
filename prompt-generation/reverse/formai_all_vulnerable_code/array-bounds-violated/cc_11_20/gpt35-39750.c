//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // Setting up the random seed based on system time
    int genome_length, num_mutations;
    printf("Enter the length of the genome: ");
    scanf("%d", &genome_length);
    printf("Enter the number of mutations: ");
    scanf("%d", &num_mutations);
    char genome[genome_length];
    
    // Initializing the genome with random nucleotides
    int i;
    for(i=0; i<genome_length; i++){
        int num = rand() % 4;
        switch(num){
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
        }
        printf("%c", genome[i]); // Printing the nucleotide as it is generated
    }
    printf("\n");
    
    // Introducing mutations
    int j;
    for(j=0; j<num_mutations; j++){
        int index = rand() % genome_length;
        int num = rand() % 3;
        switch(num){
            case 0:
                genome[index] = 'C';
                break;
            case 1:
                genome[index] = 'G';
                break;
            case 2:
                genome[index] = 'T';
                break;
        }
    }
    
    // Printing the mutated genome
    printf("Mutated genome: ");
    for(i=0; i<genome_length; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
    return 0;
}