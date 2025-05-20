//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate alien invasion probability
float calculate_invasion_probability(int number_of_days, float base_probability) {
    float invasion_probability = 0.0;
    for (int i = 1; i <= number_of_days; i++) {
        invasion_probability += base_probability / i; // Increase probability over days
    }
    return invasion_probability;
}

// Function to simulate a cheerful interaction with the user
void cheerful_interaction() {
    printf("\n🌌 Welcome to the Alien Invasion Probability Calculator! 🌌\n");
    printf("Let's figure out how likely it is that aliens will invade Earth!\n");
}

int main() {
    int days;
    float base_prob;

    // Cheerfully greet the user
    cheerful_interaction();

    // Get user input
    printf("Please enter the number of days you want to simulate: ");
    scanf("%d", &days);
    if (days <= 0) {
        printf("🙁 Oops! It seems you entered a negative number or zero. Let's try again!\n");
        return 1;
    }

    printf("Now, let's set a base invasion probability (between 0 and 1): ");
    scanf("%f", &base_prob);
    if (base_prob < 0.0 || base_prob > 1.0) {
        printf("🚨 Please enter a valid probability between 0 and 1!\n");
        return 1;
    }

    // Call function to calculate the probability
    float invasion_chance = calculate_invasion_probability(days, base_prob);

    // Display the cheerful results
    printf("\n🎉 After simulating over %d days, the total alien invasion probability is: %.2f%% 🎉\n",
           days, invasion_chance * 100);

    if (invasion_chance > 0.5) {
        printf("☠️ That sounds quite alarming! You might want to prepare for an alien visit! ☠️\n");
    } else {
        printf("😅 Phew! It looks like we're safe for now! Time to celebrate! 🎈\n");
    }

    // Create a fun loop to keep the user engaged
    char action;
    printf("\nWould you like to run another simulation? (y/n): ");
    while (1) {
        scanf(" %c", &action);
        if (action == 'y' || action == 'Y') {
            printf("Yay! Let's go again!\n");
            main(); // Recursion to restart simulation
        } else if (action == 'n' || action == 'N') {
            printf("Thanks for playing! Until next time! 🌍🚀\n");
            break;
        } else {
            printf("Oops! That's not a valid choice. Please enter 'y' or 'n': ");
        }
    }

    return 0;
}