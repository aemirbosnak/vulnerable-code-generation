//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Genome Sequencing Simulator!\n");

    //create random base pairs
    srand(time(0));
    char base_pairs[4] = {'A', 'C', 'G', 'T'};

    //ask for user input for genome length
    int genome_length;
    printf("Enter the length of the genome you want to simulate: ");
    scanf("%d", &genome_length);

    //allocate memory for genome
    char* genome = (char*) malloc(sizeof(char) * genome_length);

    //populate genome with random base pairs
    int i;
    for(i=0; i<genome_length; i++){
        int random_num = rand() % 4;
        genome[i] = base_pairs[random_num];
    }

    //print out genome
    printf("Simulated Genome: ");
    for(i=0; i<genome_length; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    //ask user for sequence to find in genome
    char sequence[genome_length];
    printf("Enter the sequence you want to find in the genome: ");
    scanf("%s", sequence);

    //convert sequence to uppercase
    for(i=0; i<genome_length; i++){
        sequence[i] = toupper(sequence[i]);
    }

    //search genome for sequence
    int sequence_length = strlen(sequence);
    int found = 0;
    for(i=0; i<genome_length-sequence_length+1; i++){
        if(strncmp(&genome[i], sequence, sequence_length) == 0){
            printf("Sequence found at index %d in genome!\n", i);
            found = 1;
         }
    }

    if(found == 0){
        printf("Sequence not found in genome :(\n");
    }

    free(genome);

    return 0;
}