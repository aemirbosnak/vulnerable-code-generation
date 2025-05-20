//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_ALIEN_SIZE 100
#define MAX_ATTACK_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    char alien[MAX_ALIEN_SIZE];
    char attack[MAX_ATTACK_SIZE];
    int input_size, alien_size, attack_size;
    int i, j, k;
    int match = 0;
    int total_matches = 0;
    int total_input_size = 0;
    int total_alien_size = 0;
    int total_attack_size = 0;
    double probability;

    // Initialize random seed
    srand(time(NULL));

    // Get user input
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);

    // Get alien input
    printf("Enter alien input: ");
    fgets(alien, MAX_ALIEN_SIZE, stdin);
    alien_size = strlen(alien);

    // Get attack input
    printf("Enter attack input: ");
    fgets(attack, MAX_ATTACK_SIZE, stdin);
    attack_size = strlen(attack);

    // Calculate total input, alien, and attack sizes
    total_input_size += input_size;
    total_alien_size += alien_size;
    total_attack_size += attack_size;

    // Calculate probability of alien invasion
    probability = (double)total_input_size / (double)(total_alien_size * total_attack_size);

    // Calculate total matches
    for (i = 0; i < input_size; i++) {
        for (j = 0; j < alien_size; j++) {
            for (k = 0; k < attack_size; k++) {
                if (input[i] == alien[j]) {
                    match++;
                }
            }
        }
    }

    // Calculate probability of alien invasion based on matches
    probability *= (double)match / (double)(input_size * alien_size * attack_size);

    // Print results
    printf("Total input size: %d\n", total_input_size);
    printf("Total alien size: %d\n", total_alien_size);
    printf("Total attack size: %d\n", total_attack_size);
    printf("Probability of alien invasion: %.4f\n", probability);

    return 0;
}