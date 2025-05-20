//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
float calculate_probability(int population, int sightings);
void display_probability(float probability);

int main() {
    // A bright and sunny beginning
    printf("🌟 Welcome to the Alien Invasion Probability Calculator! 🌟\n");
    printf("Let's discover how likely it is that little green men will visit us!\n");
    
    // Random seed for generating creativity
    srand(time(NULL));

    // Gather user input
    int population; 
    int sightings;

    printf("\nEnter the total population of your city (e.g., 100000): ");
    scanf("%d", &population);

    printf("Enter the number of recent alien sightings (e.g., 5): ");
    scanf("%d", &sightings);

    // Calculate the probability based on user inputs
    float probability = calculate_probability(population, sightings);
    display_probability(probability);

    // Exciting conclusion
    printf("\n✨ Thank you for using the Alien Invasion Probability Calculator! ✨\n");
    printf("Remember, whether aliens come or not, it's always more fun to believe! 🌌\n");

    return 0;
}

// Function to calculate the invasion probability
float calculate_probability(int population, int sightings) {
    // Basic validation for positive numbers
    if (population <= 0) {
        printf("⚠️ Oops! Population must be a positive number!\n");
        return 0.0;
    }
    if (sightings < 0) {
        printf("⚠️ Oops! Sightings can't be negative!\n");
        return 0.0;
    }

    // Calculate the probability using a spunky formula
    float probability = (float)sightings / population * 100; // in percentage
    return probability;
}

// Function to display the probability in a joyful manner
void display_probability(float probability) {
    printf("\n📡 Calculating your alien invasion probability... 📡\n");
    sleep(2); // Adding some suspense for a fun twist!

    if (probability > 0) {
        printf("🎉 The probability of an alien invasion is %.2f%%! 🚀\n", probability);
        if (probability > 50) {
            printf("😱 Uh oh! Looks like you might need to build a spaceship!\n");
        } else {
            printf("😌 Phew! Looks like we are safe for now!\n");
        }
    } else {
        printf("🙈 It seems we're in no danger of an alien invasion! Just relax and enjoy life! 🌼\n");
    }
}