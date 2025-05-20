//FormAI DATASET v1.0 Category: Computer Biology ; Style: innovative
// This program is a simulation of a simple genetic algorithm that evolves a population of strings.
// The goal is to produce a target string chosen by the user.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POPULATION_SIZE 100
#define MUTATION_RATE 0.1

char target_string[100];
int target_string_len;

// Returns a random integer between 0 and max (inclusive).
int random_int(int max) {
    return rand() % (max + 1);
}

// Returns a random character from the range [32, 126], which includes all printable ASCII characters.
char random_char() {
    return (char) (random_int(126 - 32) + 32);
}

// Initializes a random population of strings of length target_string_len.
void init_population(char population[][100]) {
    for (int i = 0; i < MAX_POPULATION_SIZE; i++) {
        for (int j = 0; j < target_string_len; j++) {
            population[i][j] = random_char();
        }
        population[i][target_string_len] = '\0';
    }
}

// Returns the fitness of an individual string, which is the number of characters that match the target string.
int fitness(char *individual) {
    int score = 0;
    for (int i = 0; i < target_string_len; i++) {
        if (individual[i] == target_string[i]) {
            score++;
        }
    }
    return score;
}

// Returns the index of the fittest individual in the population.
int find_fittest(char population[][100]) {
    int fittest_index = 0;
    int fittest_score = 0;
    for (int i = 0; i < MAX_POPULATION_SIZE; i++) {
        int score = fitness(population[i]);
        if (score > fittest_score) {
            fittest_index = i;
            fittest_score = score;
        }
    }
    return fittest_index;
}

// Performs crossover and mutation to create a new individual from two parent individuals.
void breed(char *parent1, char *parent2, char *child) {
    int crossover_point = random_int(target_string_len - 1);
    for (int i = 0; i < target_string_len; i++) {
        if (i <= crossover_point) {
            child[i] = parent1[i];
        } else {
            child[i] = parent2[i];
        }

        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            child[i] = random_char();
        }
    }
    child[target_string_len] = '\0';
}

// Selects two parent individuals using roulette wheel selection.
void selection(char population[][100], char *parent1, char *parent2) {
    int total_fitness = 0;
    for (int i = 0; i < MAX_POPULATION_SIZE; i++) {
        total_fitness += fitness(population[i]);
    }

    int wheel_position = random_int(total_fitness);
    int running_total = 0;
    for (int i = 0; i < MAX_POPULATION_SIZE; i++) {
        running_total += fitness(population[i]);
        if (running_total >= wheel_position) {
            strncpy(parent1, population[i], target_string_len);
            break;
        }
    }

    wheel_position = random_int(total_fitness);
    running_total = 0;
    for (int i = 0; i < MAX_POPULATION_SIZE; i++) {
        running_total += fitness(population[i]);
        if (running_total >= wheel_position) {
            strncpy(parent2, population[i], target_string_len);
            break;
        }
    }
}

// Evolves the population until a perfect individual is found or the maximum number of generations is reached.
void evolve(char population[][100]) {
    int generation = 1;
    while (1) {
        int fittest_index = find_fittest(population);
        char fittest_individual[100];
        strncpy(fittest_individual, population[fittest_index], target_string_len);

        if (strcmp(fittest_individual, target_string) == 0) {
            printf("Found match at generation %d!\n", generation);
            printf("%s\n", fittest_individual);
            break;
        }

        if (generation % 10 == 0) {
            printf("Generation %d: %s\n", generation, fittest_individual);
        }

        char parent1[100], parent2[100], child[100];
        selection(population, parent1, parent2);
        breed(parent1, parent2, child);
        strncpy(population[random_int(MAX_POPULATION_SIZE)], child, target_string_len);

        generation++;

        if (generation == 10000) {
            printf("Maximum number of generations reached.\n");
            break;
        }
    }
}

int main() {
    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Get the target string from the user.
    printf("Enter target string: ");
    scanf("%s", target_string);
    target_string_len = strlen(target_string);

    // Initialize the population.
    char population[MAX_POPULATION_SIZE][100];
    init_population(population);

    // Evolve the population.
    evolve(population);

    return 0;
}