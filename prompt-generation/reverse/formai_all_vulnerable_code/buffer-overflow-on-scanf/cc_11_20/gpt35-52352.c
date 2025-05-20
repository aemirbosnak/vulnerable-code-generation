//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int main() 
{ 
    int base_prob = 50;
    int probability = 50;
    int alien_tech_level = 0;
    int planet_def_level = 0;
    int invasion_chance = 0;
    int invasion_success = 0;
    int invasion_history[10];
    int invasion_count = 0;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the technological advancement level of the alien race (1-10): ");
    scanf("%d", &alien_tech_level);

    printf("\nPlease enter the planetary defense readiness level (1-10): ");
    scanf("%d", &planet_def_level);

    // Calculate base invasion probability
    if (alien_tech_level >= planet_def_level) 
    {
        base_prob = 75;
    } 
    else 
    {
        base_prob = 25;
    }

    probability = base_prob;

    // Generate random factors that could influence invasion outcome
    int fleet_size = rand() % 1000 + 1;
    int invasion_plan = rand() % 10;
    int surprise_attack = rand() % 2;
    int social_infiltration = rand() % 2;
    int diplomatic_relations = rand() % 2;

    // Adjust probability based on random factors
    if (fleet_size > 500) 
    {
        probability += 10;
    } 
    else if (fleet_size < 250) 
    {
        probability -= 10;
    }

    if (invasion_plan > 7) 
    {
        probability += 15;
    } 
    else if (invasion_plan < 3) 
    {
        probability -= 15;
    }

    if (surprise_attack) 
    {
        probability += 25;
    }

    if (social_infiltration) 
    {
        probability += 10;
    }

    if (diplomatic_relations) 
    {
        probability -= 10;
    }

    // Check invasion success
    invasion_chance = rand() % 100 + 1;

    if (invasion_chance <= probability) 
    {
        printf("\n\nThe aliens have invaded successfully!\n\n");
        invasion_success = 1;
    } 
    else 
    {
        printf("\n\nThe planet's defenses have held off the alien invasion!\n\n");
        invasion_success = 0;
    }

    // Save invasion history
    invasion_history[invasion_count] = invasion_success;
    invasion_count++;

    // Display invasion history
    printf("Invasion history: ");
    for (int i = 0; i < invasion_count; i++) 
    {
        if (invasion_history[i]) 
        {
            printf("S ");
        } 
        else 
        {
            printf("F ");
        }
    }
    printf("\n\n");

    return 0; 
}