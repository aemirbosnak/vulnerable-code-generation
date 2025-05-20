//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){

    printf("\n Welcome to Genome Sequencing Simulator \n");

    char* nucleotides = "ACGT";  // four DNA nucleotides 
    srand(time(0)); 

    char sequence[100]; // maximum length of sequence is 100 bases 
    int num_bases, i, j, match, mismatch, gap; // variables for simulation inputs 
    int score = 0; // keeps track of alignment score 
    int sim_runs = 10; // number of times user wants to simulate 
    int total_score = 0, sim_score; // variables for computing average score 

    for(i=0; i<sim_runs; i++){ // loop for number of simulations 

        printf("\n\n Simulation %d \n", i+1); 
        printf("\n Please enter the number of bases: "); 
        scanf("%d", &num_bases); 

        if(num_bases<1 || num_bases>100){ // input validation 
            printf("\n Invalid number of bases. Sequence must be between 1 and 100 bases long.\n");
            i--; // decrement to ensure loop doesn't terminate early 
            continue; 
        }

        for(j=0; j<num_bases; j++){ // loop for generating random sequence 
            sequence[j] = nucleotides[rand()%4]; // randomly select one of four nucleotides 
        }
        sequence[num_bases] = '\0'; // add terminating null character 

        printf("\n Random sequence generated: %s \n", sequence);

        printf("\n Please enter the match score: "); 
        scanf("%d", &match); 

        printf("\n Please enter the mismatch score: "); 
        scanf("%d", &mismatch); 

        printf("\n Please enter the gap penalty: "); 
        scanf("%d", &gap); 

        sim_score = 0; // reset score for each simulation 

        // simulate alignment 
        for(j=0; j<num_bases; j++){ 
            if(sequence[j] == nucleotides[rand()%4]){ // match nucleotide 
                sim_score += match; 
            }
            else{
                sim_score += mismatch; 
            }
        }

        // subtract gap penalty for every mismatch 
        sim_score -= gap*(num_bases-1); 

        printf("\n Alignment score: %d ", sim_score);

        // add simulation score to total 
        total_score += sim_score; 
    }

    float avg_score = (float)total_score/sim_runs; // compute average score 

    printf("\n\n Total simulations: %d \n", sim_runs); 
    printf("\n Total score: %d \n", total_score); 
    printf("\n Average score: %.2f \n", avg_score);

    return 0; 
}