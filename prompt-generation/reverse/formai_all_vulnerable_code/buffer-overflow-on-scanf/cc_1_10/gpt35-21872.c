//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_random_genome(char* genome, int length);

int main() {
    printf("Welcome to Genome Sequencing Simulator!\n");
    printf("Please enter the length of the genome you want to sequence: ");
    int length;
    scanf("%d", &length);

    char* original_genome = malloc(length * sizeof(char));
    char* mutated_genome = malloc(length * sizeof(char));
    
    printf("Generating original genome...\n");
    generate_random_genome(original_genome, length);
    printf("Original genome: %s\n", original_genome);

    printf("Simulating mutation...\n");
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < length; i++) {
        mutated_genome[i] = original_genome[i];
        if (rand() % 10 == 0) { // 10% chance of mutation
            switch(original_genome[i]) {
                case 'A':
                    mutated_genome[i] = 'C';
                    break;
                case 'C':
                    mutated_genome[i] = 'G';
                    break;
                case 'G':
                    mutated_genome[i] = 'T';
                    break;
                case 'T':
                    mutated_genome[i] = 'A';
                    break;
            }
        }
    }
    printf("Mutated genome: %s\n", mutated_genome);

    free(original_genome);
    free(mutated_genome);
    return 0;
}

void generate_random_genome(char* genome, int length) {
    const char* bases = "ACGT";
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < length; i++) {
        int index = rand() % 4; // Randomly choose one of the four bases
        genome[i] = bases[index];
    }
}