//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGHTINGS 100
#define MAX_DEFENSES 10

float calculate_probability(int ufo_sightings, float government_preparedness, float planetary_defense) {
    float base_probability = (float)ufo_sightings / MAX_SIGHTINGS;
    return base_probability * (1 - government_preparedness) * (1 - planetary_defense);
}

void display_probability(float probability) {
    if (probability < 0) {
        probability = 0.0;
    } else if (probability > 1) {
        probability = 1.0;
    }
    
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability * 100);
}

int main() {
    int ufo_sightings;
    float government_preparedness;
    float planetary_defense;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    
    printf("Enter the number of UFO sightings (0 - %d): ", MAX_SIGHTINGS);
    scanf("%d", &ufo_sightings);
    if (ufo_sightings < 0 || ufo_sightings > MAX_SIGHTINGS) {
        printf("Invalid input for UFO sightings. Please restart the program.\n");
        return EXIT_FAILURE;
    }

    printf("Enter your government's preparedness level (0.0 - 1.0): ");
    scanf("%f", &government_preparedness);
    if (government_preparedness < 0.0 || government_preparedness > 1.0) {
        printf("Invalid input for government preparedness. Please restart the program.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the planetary defense effectiveness (0.0 - 1.0): ");
    scanf("%f", &planetary_defense);
    if (planetary_defense < 0.0 || planetary_defense > 1.0) {
        printf("Invalid input for planetary defense. Please restart the program.\n");
        return EXIT_FAILURE;
    }

    float invasion_probability = calculate_probability(ufo_sightings, government_preparedness, planetary_defense);
    display_probability(invasion_probability);

    printf("\nDo you want to explore other factors? (1: Yes, 0: No): ");
    int explore_more;
    scanf("%d", &explore_more);

    while (explore_more) {
        int factor_selection;
        printf("Choose a factor to explore:\n");
        printf("1: Modify UFO sightings\n");
        printf("2: Modify government preparedness\n");
        printf("3: Modify planetary defense\n");
        printf("4: Recalculate invasion probability\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &factor_selection);
        
        switch (factor_selection) {
            case 1:
                printf("Enter the number of UFO sightings (0 - %d): ", MAX_SIGHTINGS);
                scanf("%d", &ufo_sightings);
                if (ufo_sightings < 0 || ufo_sightings > MAX_SIGHTINGS) {
                    printf("Invalid input for UFO sightings.\n");
                }
                break;
            case 2:
                printf("Enter your government's preparedness level (0.0 - 1.0): ");
                scanf("%f", &government_preparedness);
                if (government_preparedness < 0.0 || government_preparedness > 1.0) {
                    printf("Invalid input for government preparedness.\n");
                }
                break;
            case 3:
                printf("Enter the planetary defense effectiveness (0.0 - 1.0): ");
                scanf("%f", &planetary_defense);
                if (planetary_defense < 0.0 || planetary_defense > 1.0) {
                    printf("Invalid input for planetary defense.\n");
                }
                break;
            case 4:
                invasion_probability = calculate_probability(ufo_sightings, government_preparedness, planetary_defense);
                display_probability(invasion_probability);
                break;
            case 5:
                printf("Exiting the program. Stay safe from aliens!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("Would you like to explore other factors? (1: Yes, 0: No): ");
        scanf("%d", &explore_more);
    }
    
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return EXIT_SUCCESS;
}