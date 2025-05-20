//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GALAXIES 100
#define ALIEN_INFLUENCE_FACTOR 0.75
#define TECHNOLOGY_FACTOR 0.85

// Function to generate random float value between min and max
float random_float(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

// Function to calculate the probability of alien invasion
float calculate_alien_invasion_probability(int technology_level, int alien_influence) {
    float base_probability = (float) alien_influence / 100.0;
    base_probability *= TECHNOLOGY_FACTOR - (technology_level / 100.0 * (1 - TECHNOLOGY_FACTOR));
    return base_probability < 0 ? 0 : base_probability;
}

// Function to display invasion probability in a cheerful manner
void display_probability(int galaxy_index, float probability) {
    if (probability > 0.75) {
        printf("🌌 Galaxy %d: High chance of invasion! Be ready! (Probability: %.2f)\n", galaxy_index, probability);
    } else if (probability > 0.50) {
        printf("🌠 Galaxy %d: Moderate chance of invasion! Stay alert! (Probability: %.2f)\n", galaxy_index, probability);
    } else if (probability > 0.25) {
        printf("✨ Galaxy %d: Low chance of invasion! Enjoy your day! (Probability: %.2f)\n", galaxy_index, probability);
    } else {
        printf("🌞 Galaxy %d: Very low chance of invasion! All is well! (Probability: %.2f)\n", galaxy_index, probability);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    printf("🌟 Welcome to the Alien Invasion Probability Calculator! 🌟\n");

    int total_galaxies;
    printf("Enter the number of galaxies to analyze (max %d): ", MAX_GALAXIES);
    scanf("%d", &total_galaxies);

    if (total_galaxies > MAX_GALAXIES || total_galaxies <= 0) {
        printf("🎉 You entered an invalid number! Let’s keep it positive! Exiting...\n");
        return 1;
    }

    for (int i = 0; i < total_galaxies; i++) {
        int technology_level = rand() % 101; // Random technology level between 0 and 100
        int alien_influence = rand() % 101;   // Random alien influence between 0 and 100

        printf("🔮 Analyzing galaxy %d...\n", i + 1);
        printf("   - Technology Level: %d\n", technology_level);
        printf("   - Alien Influence: %d\n", alien_influence);

        float invasion_probability = calculate_alien_invasion_probability(technology_level, alien_influence);
        display_probability(i + 1, invasion_probability);
    }

    printf("🎆 Analysis complete! Stay vigilant and keep watching the stars! 🎆\n");

    return 0;
}