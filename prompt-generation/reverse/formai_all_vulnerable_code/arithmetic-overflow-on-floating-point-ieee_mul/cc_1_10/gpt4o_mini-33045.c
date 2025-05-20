//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 1000

typedef struct {
    double likelihood;
    double distance;
    double technology_level;
} AlienRace;

void inputAlienData(AlienRace *alien) {
    printf("Enter the likelihood of invasion (0.0 to 1.0): ");
    scanf("%lf", &alien->likelihood);
    
    printf("Enter the distance from Earth (in light years): ");
    scanf("%lf", &alien->distance);
    
    printf("Enter the technology level (1 to 10): ");
    scanf("%lf", &alien->technology_level);
}

double calculateProbability(AlienRace alien) {
    double distance_factor = 1.0 / (1.0 + alien.distance);
    double tech_factor = alien.technology_level / 10.0;

    return alien.likelihood * distance_factor * tech_factor;
}

void simulateInvasions(int num_simulations, double *results) {
    for (int i = 0; i < num_simulations; i++) {
        results[i] = (double)rand() / RAND_MAX; // Random likelihood
    }
}

double averageProbability(double *results, int num_results) {
    double sum = 0.0;
    for (int i = 0; i < num_results; i++) {
        sum += results[i];
    }
    return sum / (double)num_results;
}

void displaySummary(double probability, int num_simulations) {
    printf("\n=== Invasion Probability Summary ===\n");
    printf("Number of simulations: %d\n", num_simulations);
    printf("Calculated Invasion Probability: %.4f\n", probability);
    
    if (probability < 0.2) {
        printf("Low probability of invasion. Relax!\n");
    } else if (probability < 0.5) {
        printf("Moderate probability of invasion. Stay alert!\n");
    } else {
        printf("High probability of invasion! Prepare your defenses!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    AlienRace alien;
    int num_simulations;
    double invasion_probabilities[MAX_SAMPLES];

    printf("=== Alien Invasion Probability Calculator ===\n");
    
    inputAlienData(&alien);
    
    printf("Enter the number of simulations to run (up to %d): ", MAX_SAMPLES);
    scanf("%d", &num_simulations);
    
    if (num_simulations > MAX_SAMPLES) {
        num_simulations = MAX_SAMPLES;
        printf("Max samples exceeded. Running %d simulations.\n", MAX_SAMPLES);
    }

    for (int i = 0; i < num_simulations; i++) {
        invasion_probabilities[i] = calculateProbability(alien);
    }

    double average_prob = averageProbability(invasion_probabilities, num_simulations);
    displaySummary(average_prob, num_simulations);

    return 0;
}