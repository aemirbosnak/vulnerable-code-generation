//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>

#define MAX_SIGHTINGS 1000
#define MAX_PREPAREDNESS_LEVEL 10

// Function prototypes
void display_intro();
void input_data(int *sightings, int *humans, int *preparedness);
float calculate_probability(int sightings, int humans, int preparedness);
void display_probability(float probability);

int main() {
    int sightings, humans, preparedness;
    
    // Display introductory message
    display_intro();
    
    // Input data from the user
    input_data(&sightings, &humans, &preparedness);
    
    // Calculate the probability of alien invasion
    float probability = calculate_probability(sightings, humans, preparedness);
    
    // Display the calculated probability
    display_probability(probability);
    
    return 0;
}

void display_intro() {
    printf("=================================\n");
    printf("  Alien Invasion Probability Calculator\n");
    printf("=================================\n");
    printf("This program will help you calculate the probability of an alien invasion based on:\n");
    printf("- UFO sightings\n");
    printf("- Total number of humans in the area\n");
    printf("- Level of government preparedness (1-10)\n\n");
}

void input_data(int *sightings, int *humans, int *preparedness) {
    printf("Enter the number of UFO sightings (max %d): ", MAX_SIGHTINGS);
    scanf("%d", sightings);
    if (*sightings < 0) {
        printf("UFO sightings cannot be negative. Defaulting to 0.\n");
        *sightings = 0;
    } else if (*sightings > MAX_SIGHTINGS) {
        printf("Too many UFO sightings! Capping at %d.\n", MAX_SIGHTINGS);
        *sightings = MAX_SIGHTINGS;
    }
    
    printf("Enter the total number of humans in the area: ");
    scanf("%d", humans);
    if (*humans < 0) {
        printf("The number of humans cannot be negative. Defaulting to 0.\n");
        *humans = 0;
    }
    
    printf("Rate the level of government preparedness (1 to %d): ", MAX_PREPAREDNESS_LEVEL);
    scanf("%d", preparedness);
    if (*preparedness < 1 || *preparedness > MAX_PREPAREDNESS_LEVEL) {
        printf("Invalid preparedness level. Defaulting to 5.\n");
        *preparedness = 5;
    }
}

float calculate_probability(int sightings, int humans, int preparedness) {
    if (humans == 0) {
        return 0.0; // No humans, no invasion
    }
    
    // Calculate probability based on sightings, humans, and preparedness
    float base_probability = (float)sightings / (float)humans;
    float adjusted_probability = base_probability * (MAX_PREPAREDNESS_LEVEL + 1 - preparedness);
    
    // Ensure the probability does not exceed 1.0
    if (adjusted_probability > 1.0) {
        adjusted_probability = 1.0;
    }
    
    return adjusted_probability * 100; // Convert to percentage
}

void display_probability(float probability) {
    printf("=================================\n");
    printf("Probability of Alien Invasion: %.2f%%\n", probability);
    printf("=================================\n");
    if (probability > 75.0) {
        printf("Alert! High probability of an alien invasion. Prepare accordingly!\n");
    } else if (probability > 50.0) {
        printf("Caution! Moderate chance of an alien invasion. Stay vigilant!\n");
    } else {
        printf("Low probability of an alien invasion. You can relax... for now.\n");
    }
}