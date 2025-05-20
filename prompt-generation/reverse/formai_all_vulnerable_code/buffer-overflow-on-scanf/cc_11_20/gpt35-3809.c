//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Genome Sequencing Simulator!\n\n");
    printf("Please enter the length of the genome that you wish to simulate: ");
    int genome_length;
    scanf("%d", &genome_length);

    char genome[genome_length];

    // Generate a random genome sequence
    srand(time(NULL));
    for(int i=0; i<genome_length; i++){
        int random_num = rand() % 4; // 0=A, 1=C, 2=G, 3=T
        if(random_num == 0){
            genome[i] = 'A';
        }
        else if(random_num == 1){
            genome[i] = 'C';
        }
        else if(random_num == 2){
            genome[i] = 'G';
        }
        else{
            genome[i] = 'T';
        }
    }

    // Print the generated genome sequence
    printf("\nGenerated Genome Sequence: ");
    for(int i=0; i<genome_length; i++){
        printf("%c", genome[i]);
    }
    printf("\n\n");

    // Ask the user for a sequence to search for in the genome
    printf("Please enter a sequence to search for in the genome (maximum length of 5): ");
    char search_sequence[6];
    scanf("%s", search_sequence);

    // Search for the entered sequence in the generated genome
    int search_sequence_length = strlen(search_sequence);
    int found = 0;
    for(int i=0; i<genome_length-search_sequence_length; i++){
        int match = 1;
        for(int j=0; j<search_sequence_length; j++){
            if(genome[i+j] != search_sequence[j]){
                match = 0;
                break;
            }
        }
        if(match == 1){
            printf("%s found in the genome at location %d\n", search_sequence, i);
            found = 1;
        }
    }
    if(found == 0){
        printf("%s not found in the genome\n", search_sequence);
    }

    return 0;
}