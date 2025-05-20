//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_BASES 4
#define BASE_A 0
#define BASE_C 1
#define BASE_G 2
#define BASE_T 3

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the length of the genome to be simulated
    int genome_length;
    printf("Enter the length of the genome to be simulated: ");
    scanf("%d", &genome_length);

    // Create an array to store the simulated genome
    char *genome = malloc(genome_length * sizeof(char));

    // Simulate the genome
    printf("Generating the simulated genome: ");
    int max_silent = pow(2.0, 32)/3; 
    int current_silent = max_silent;

    for (int i = 0; i < genome_length; i++) {
        if (current_silent != 0){
            int base = floor((double)rand() / (RAND_MAX + 1.0) * NUM_BASES);
            if (base == BASE_A) {
                genome[i] = 'A';
                current_silent = max_silent;
            } else if (base == BASE_C) {
                genome[i] = 'C';
                current_silent = max_silent;
            } else if (base == BASE_G) {
                genome[i] = 'G';
                current_silent = max_silent;
            } else if (base == BASE_T) {
                genome[i] = 'T';
                current_silent -= 1;
            }
	}
        else{
            genome[i] = 'T';
            current_silent = max_silent;
        }
    }



    // Print the simulated genome
    printf("Simulated genome:\n%s\n", genome);

    // Clean up
    free(genome);

    return 0;
}