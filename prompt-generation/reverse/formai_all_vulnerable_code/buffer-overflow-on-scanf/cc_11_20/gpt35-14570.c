//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    //Initializing variables
    int genome_length;
    int genome[100000];
    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    
    //Taking input from user
    printf("Enter the length of genome (Maximum 100000):\n");
    scanf("%d", &genome_length);
    
    //Checking if genome length is valid
    if(genome_length <= 0 || genome_length > 100000) {
        printf("Invalid length of genome.\n");
        return 1;
    }
    
    //Generating random genome sequence
    srand(time(NULL));
    for(int i=0; i<genome_length; i++) {
        genome[i] = rand() % 4;
    }
    
    //Displaying the genome sequence
    printf("The genome sequence is:\n");
    for(int i=0; i<genome_length; i++) {
        printf("%c", nucleotides[genome[i]]);
    }
    
    //Simulating genome sequencing
    printf("\n\nSimulating genome sequencing...\n");
    printf(" 20%% Complete...\n");
    for(int i=0; i<genome_length; i++) {
        if(i == genome_length*0.2) {
            printf(" 40%% Complete...\n");
        }
        else if(i == genome_length*0.4) {
            printf(" 60%% Complete...\n");
        }
        else if(i == genome_length*0.6) {
            printf(" 80%% Complete...\n");
        }
        else if(i == genome_length*0.8) {
            printf(" 100%% Complete...\n");
        }
    }
    
    //Displaying the sequenced genome
    printf("\n\nThe sequenced genome is:\n");
    for(int i=0; i<genome_length; i++) {
        if(genome[i] == 0) {
            printf("T");
        }
        else if(genome[i] == 1) {
            printf("G");
        }
        else if(genome[i] == 2) {
            printf("C");
        }
        else {
            printf("A");
        }
    }
    printf("\n");
    
    //Terminating the program
    return 0;
}