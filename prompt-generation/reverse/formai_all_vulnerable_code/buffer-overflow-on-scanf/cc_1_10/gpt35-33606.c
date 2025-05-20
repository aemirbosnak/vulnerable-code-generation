//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
/* Linus Torvalds-style Genome Sequencing Simulator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01
#define POPULATION_SIZE 50
#define GENERATIONS 100

char* generate_random_genome() {
  char* genome = (char*) malloc(GENOME_LENGTH * sizeof(char));

  for (int i = 0; i < GENOME_LENGTH; i++) {
    int nucleotide = rand() % 4;

    switch(nucleotide) {
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
  }

  return genome;
}

void mutate_genome(char* genome) {
  for (int i = 0; i < GENOME_LENGTH; i++) {
    float mutation_chance = (float)rand() / RAND_MAX;

    if (mutation_chance < MUTATION_RATE) {
      int nucleotide = rand() % 4;

      switch(nucleotide) {
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
    }
  }
}

void fitness_sort(char** population, int* fitness_scores) {
  for (int i = 0; i < POPULATION_SIZE; i++) {
    int max_fit_idx = i;

    for (int j = i + 1; j < POPULATION_SIZE; j++) {
      if (fitness_scores[j] > fitness_scores[max_fit_idx]) {
        max_fit_idx = j;
      }
    }

    char* temp_genome = population[i];
    int temp_score = fitness_scores[i];

    population[i] = population[max_fit_idx];
    fitness_scores[i] = fitness_scores[max_fit_idx];

    population[max_fit_idx] = temp_genome;
    fitness_scores[max_fit_idx] = temp_score;
  }
}

int calculate_fitness(char* genome, char* target_genome) {
  int fitness = 0;

  for (int i = 0; i < GENOME_LENGTH; i++) {
    if (genome[i] == target_genome[i]) {
      fitness++;
    }
  }

  return fitness;
}

int main() {
  srand(time(NULL));

  char target_genome[GENOME_LENGTH];
  printf("Enter the target genome (length %d): ", GENOME_LENGTH);
  scanf("%1000s", target_genome);

  char* population[POPULATION_SIZE];
  int fitness_scores[POPULATION_SIZE];

  // Generate random population
  for (int i = 0; i < POPULATION_SIZE; i++) {
    population[i] = generate_random_genome();
    fitness_scores[i] = calculate_fitness(population[i], target_genome);
  }

  // Run evolutionary algorithm
  for (int generation = 0; generation < GENERATIONS; generation++) {
    printf("Generation %d\n", generation + 1);

    // Sort population by fitness
    fitness_sort(population, fitness_scores);

    // Print best genome and its fitness score
    printf("Best genome: %s\n", population[0]);
    printf("Fitness score: %d\n\n", fitness_scores[0]);

    // Create new population
    char* new_population[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
      // Selection
      int parent1_idx = rand() % ((int)(POPULATION_SIZE / 2));
      int parent2_idx = rand() % ((int)(POPULATION_SIZE / 2));

      char* parent1 = population[parent1_idx];
      char* parent2 = population[parent2_idx];

      // Crossover
      int crossover_point = rand() % GENOME_LENGTH;

      char* child = (char*) malloc(GENOME_LENGTH * sizeof(char));

      for (int j = 0; j < crossover_point; j++) {
        child[j] = parent1[j];
      }

      for (int j = crossover_point; j < GENOME_LENGTH; j++) {
        child[j] = parent2[j];
      }

      // Mutation
      mutate_genome(child);

      // Evaluate fitness
      int fitness = calculate_fitness(child, target_genome);

      // Replace old genome with new genome if new genome has higher fitness
      if (fitness > fitness_scores[i]) {
        new_population[i] = child;
        fitness_scores[i] = fitness;
      } else {
        new_population[i] = population[i];
      }
    }

    // Replace old population with new population
    for (int i = 0; i < POPULATION_SIZE; i++) {
      population[i] = new_population[i];
    }
  }

  // Free memory for all genomes
  for (int i = 0; i < POPULATION_SIZE; i++) {
    free(population[i]);
  }

  return 0;
}