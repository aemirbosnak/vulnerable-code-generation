//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the probability of alien invasion based on various factors
double calculate_alien_invasion_probability(int cows, int ufos_sighted, int weather_conditions) {
    double probability = 0.0;

    // Cow abduction rate is 1 in 5000
    probability += (double) ufos_sighted / cows * pow(5000.0, 3.0);

    // Weather conditions affect the probability
    switch (weather_conditions) {
        case 0:
            probability *= 0.9; // Clear sky
            break;
        case 1:
            probability *= 1.2; // Rainy
            break;
        case 2:
            probability *= 1.5; // Cloudy
            break;
        case 3:
            probability *= 2.0; // Thunderstorm
            break;
        default:
            probability = NAN; // Invalid weather condition
            break;
    }

    // Random factor to simulate unpredictability of aliens
    probability *= (double) rand() / RAND_MAX;

    return probability;
}

// Function to print the result in a funny style
void print_result(double probability) {
    if (probability > 0.5) {
        printf("OMG! The probability of alien invasion is %0.2f!!!\n", probability);
        printf("Better start building those flying saucer shelters!\n");
    } else {
        printf("Phew! The probability of alien invasion is only %0.2f.\n", probability);
        printf("Relax, have another beer and enjoy the stars!\n");
    }
}

int main() {
    int cows = 100;
    int ufos_sighted = 3;
    int weather_conditions = 1; // 0 for clear sky, 1 for rainy, 2 for cloudy, 3 for thunderstorm

    srand(time(NULL));

    double probability = calculate_alien_invasion_probability(cows, ufos_sighted, weather_conditions);
    print_result(probability);

    return 0;
}