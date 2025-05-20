//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define MUTATION_RATE 0.1

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    char nucleotides[] = "ACGT";
    int sequence_length, generation_limit;
    double fitness_limit;
    
    printf("Enter length of sequence (up to %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);
    
    printf("Enter generation limit: ");
    scanf("%d", &generation_limit);
    
    printf("Enter fitness limit (0-1 scale): ");
    scanf("%lf", &fitness_limit);
    
    // Initialize first generation
    char population[20][MAX_SEQUENCE_LENGTH+1];
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < sequence_length; j++) {
            population[i][j] = nucleotides[rand() % 4];
        }
        population[i][sequence_length] = '\0';
    }
    
    // Evolution process
    int generation = 1;
    double fitness[20];
    int fit_index[20];
    int best_index = 0;
    double best_fitness = 0.0;
    while (generation <= generation_limit) {
        // Determine fitness of each member
        for (i = 0; i < 20; i++) {
            double score = 0.0;
            for (j = 0; j < sequence_length; j++) {
                if (population[i][j] == 'C' && population[i][(j+1)%sequence_length] == 'G') {
                    score += 2.0; // CG pairs have higher fitness value
                } else if (population[i][j] != 'A' && population[i][j] != 'T') {
                    score -= 1.0; // Non-AT nucleotides have lower fitness value
                }
            }
            fitness[i] = score / (double) sequence_length;
            fit_index[i] = i;
            
            // Keep track of best member
            if (fitness[i] > best_fitness) {
                best_fitness = fitness[i];
                best_index = i;
            }
        }
        
        // Sort by fitness
        for (i = 0; i < 20; i++) {
            for (j = i; j < 20; j++) {
                if (fitness[fit_index[i]] < fitness[fit_index[j]]) {
                    int temp = fit_index[i];
                    fit_index[i] = fit_index[j];
                    fit_index[j] = temp;
                }
            }
        }
        
        // Check if best member meets fitness requirement
        if (best_fitness >= fitness_limit) {
            printf("Generation %d: Best member: %s\n", generation, population[best_index]);
            break;
        }
        
        // Generate new generation
        char new_population[20][MAX_SEQUENCE_LENGTH+1];
        for (i = 0; i < 10; i++) {
            strcpy(new_population[i], population[fit_index[i]]);
        }
        for (i = 10; i < 20; i++) {
            int parent1 = fit_index[rand() % 10];
            int parent2 = fit_index[rand() % 10];
            int crossover = rand() % sequence_length;
            for (j = 0; j < crossover; j++) {
                new_population[i][j] = population[parent1][j];
            }
            for (j = crossover; j < sequence_length; j++) {
                new_population[i][j] = population[parent2][j];
            }
            if ((double) rand() / RAND_MAX < MUTATION_RATE) {
                int mutation = rand() % sequence_length;
                new_population[i][mutation] = nucleotides[rand() % 4];
            }
            new_population[i][sequence_length] = '\0';
        }
        memcpy(population, new_population, sizeof(char) * 20 * (MAX_SEQUENCE_LENGTH+1));
        
        // Output current best member
        printf("Generation %d: Best member: %s (fitness: %.2lf)\n", generation, population[best_index], best_fitness);
        generation++;
    }
    
    // Output final results if limit not met
    if (generation > generation_limit) {
        printf("Generation limit reached. Best member: %s (fitness: %.2lf)\n", population[best_index], best_fitness);
    }
    
    return 0;
}