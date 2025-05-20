//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define colors for terminal output
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

// Function to simulate the alien invasion probability
float calculate_invasion_probability(int reports) {
    float base_probability = 0.05; // 5% base probability
    float culmination_factor = 0.01; // Each report increases the chance by 1%

    return base_probability + (reports * culmination_factor);
}

// Function to display the invasion outcome
void display_invasion_outcome(float probability) {
    printf("\n%s*** Alien Invasion Probability Report ***%s\n", YELLOW, RESET);
    printf("     Calculated Probability: %.2f%%\n\n", probability * 100);

    if (probability < 0.2) {
        printf("%sStatus: Low Alert! Relax, Earth is safe!%s\n", GREEN, RESET);
    } else if (probability < 0.5) {
        printf("%sStatus: Moderate Alert! Stay vigilant!%s\n", YELLOW, RESET);
    } else {
        printf("%sALERT! High Probability of Invasion! Prepare for possible defense!%s\n", RED, RESET);
    }
}

// Main function
int main() {
    int reports = 0;
    char choice;

    // Seed for random number generation
    srand(time(NULL));

    printf("%s=========================================%s\n", GREEN, RESET);
    printf("%s       ALIEN INVASION PROBABILITY       %s\n", GREEN, RESET);
    printf("%s=========================================%s\n", GREEN, RESET);
    
    do {
        printf("\nEnter the number of alien sightings reported (0-100): ");
        scanf("%d", &reports);

        if(reports < 0 || reports > 100) {
            printf("%sInvalid input! Please enter a value between 0 and 100.%s\n", RED, RESET);
            continue;
        }

        float probability = calculate_invasion_probability(reports);
        display_invasion_outcome(probability);

        printf("\nDo you want to calculate again? (y/n): ");
        while ((getchar()) != '\n'); // Clear newline left in buffer
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("%s=========================================%s\n", GREEN, RESET);
    printf("%s Thank you for using the Alien Invasion Probability Calculator! %s\n", GREEN, RESET);
    printf("%s=========================================%s\n", GREEN, RESET);

    return 0;
}