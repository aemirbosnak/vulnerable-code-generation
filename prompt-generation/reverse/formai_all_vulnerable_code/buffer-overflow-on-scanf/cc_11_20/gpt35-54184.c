//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LEN 1000

int main() {

    char nucleotides[4] = {'A', 'T', 'G', 'C'};
    char genome[MAX_GENOME_LEN];
    int genome_length, mutation_count, insert_count, delete_count;
    
    printf("Enter the length of the genome: ");
    scanf("%d", &genome_length);

    // Generate genome with random nucleotides
    srand(time(0));
    for(int i = 0; i < genome_length; i++) {
        int r = rand() % 4;
        genome[i] = nucleotides[r];
    }

    // Print the genome
    printf("\nGenerated Genome Sequence: \n");
    for(int i = 0; i < genome_length; i++) {
        printf("%c", genome[i]);
    }

    // Prompt user for number of mutations, insertions and deletions
    printf("\n\nEnter number of mutations: ");
    scanf("%d", &mutation_count);
    printf("Enter number of insertions: ");
    scanf("%d", &insert_count);
    printf("Enter number of deletions: ");
    scanf("%d", &delete_count);

    // Apply mutations
    int i = 0;
    while(i < mutation_count) {
        int r = rand() % genome_length;
        int n = rand() % 4;
        if(genome[r] != nucleotides[n]) {
            genome[r] = nucleotides[n];
            i++;
        }
    }

    // Apply insertions
    i = 0;
    while(i < insert_count) {
        int r = rand() % genome_length;
        int n = rand() % 4;
        if(genome_length < MAX_GENOME_LEN) {
            for(int j = genome_length; j > r; j--) {
                genome[j] = genome[j-1];
            }
            genome[r] = nucleotides[n];
            genome_length++;
            i++;
        }
    }

    // Apply deletions
    i = 0;
    while(i < delete_count) {
        int r = rand() % genome_length;
        if(genome_length > 0) {
            for(int j = r; j < genome_length-1; j++) {
                genome[j] = genome[j+1];
            }
            genome[genome_length-1] = '\0';
            genome_length--;
            i++;
        }
    }

    // Print the modified genome
    printf("\n\nModified Genome Sequence: \n");
    for(int i = 0; i < genome_length; i++) {
        printf("%c", genome[i]);
    }

    return 0;
}