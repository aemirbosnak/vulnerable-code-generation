//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void love_speech() {
    printf("O fair Juliet! What dost thou see in yon sky?\n");
    printf("Art they celestial beings, intent on our demise?\n");
    printf("Fear not, my dear Romeo! For we shall ascertain their intentions!\n");
}

double calculate_probability(int populations, double technology_level, double history_of_invasions) {
    // Calculating probability based on given parameters
    double base_prob = (double)populations / 10000 * technology_level * (1 - history_of_invasions);
    return base_prob > 1 ? 1 : base_prob; // Capping the probability at 1
}

void display_probability(double probability) {
    printf("O Romeo, look closely, and tell me the fate that lies ahead!\n");
    printf("The probability of an alien invasion is %.2f%%.\n", probability * 100);
    if (probability > 0.5) {
        printf("Alas, the heavens foretell doom! Prepare, dear Juliet!\n");
    } else {
        printf("Fear not, for the stars align in our favor, sweet Juliet!\n");
    }
}

int main() {
    int populations;
    double technology_level, history_of_invasions;

    love_speech();

    // Gathering data from our fateful fate
    printf("Enter the human population (in millions): ");
    scanf("%d", &populations);
    
    printf("Enter the technology level (between 0 and 10): ");
    scanf("%lf", &technology_level);
    
    printf("Enter the historical invasion ratio (between 0 and 1): ");
    scanf("%lf", &history_of_invasions);

    // Calling function to calculate
    double probability = calculate_probability(populations, technology_level, history_of_invasions);

    // Displaying the calculated probability elegantly
    display_probability(probability);

    // Closing with hope and dread
    printf("Should we seek shelter or gaze at the stars?\n");
    printf("For the night is dark and full of terrors!\n");

    return 0;
}