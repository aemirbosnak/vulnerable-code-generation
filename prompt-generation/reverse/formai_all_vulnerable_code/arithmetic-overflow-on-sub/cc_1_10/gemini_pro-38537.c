//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
// Welcome to the Wasteland Fitness Tracker!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some post-apocalyptic stats
typedef struct {
    char* name;
    int strength;
    int agility;
    int endurance;
    int health;
} Survivor;

// Initialize our survivor
Survivor survivor = {
    .name = "Lone Wanderer",
    .strength = 10,
    .agility = 8,
    .endurance = 12,
    .health = 100
};

// Define some fitness activities
typedef struct {
    char* name;
    int strength_gain;
    int agility_gain;
    int endurance_gain;
    int health_cost;
} Activity;

// Initialize our fitness activities
Activity activities[] = {
    { .name = "Scavenging", .strength_gain = 1, .agility_gain = 2, .endurance_gain = 1, .health_cost = -10 },
    { .name = "Raiding", .strength_gain = 3, .agility_gain = 1, .endurance_gain = 2, .health_cost = -20 },
    { .name = "Hunting", .strength_gain = 2, .agility_gain = 2, .endurance_gain = 1, .health_cost = -15 },
    { .name = "Resting", .strength_gain = 0, .agility_gain = 0, .endurance_gain = 0, .health_cost = -5 }
};

// Main fitness tracker loop
int main() {
    // Print the survivor's stats
    printf("Survivor: %s\n", survivor.name);
    printf("Strength: %d\n", survivor.strength);
    printf("Agility: %d\n", survivor.agility);
    printf("Endurance: %d\n", survivor.endurance);
    printf("Health: %d\n", survivor.health);

    // Loop until the survivor dies
    while (survivor.health > 0) {
        // Print the available activities
        printf("\nAvailable Activities:\n");
        for (int i = 0; i < sizeof(activities) / sizeof(Activity); i++) {
            printf("%d. %s\n", i + 1, activities[i].name);
        }

        // Get the user's input
        int activity_index;
        printf("Choose an activity: ");
        scanf("%d", &activity_index);

        // Perform the selected activity
        Activity activity = activities[activity_index - 1];
        survivor.strength += activity.strength_gain;
        survivor.agility += activity.agility_gain;
        survivor.endurance += activity.endurance_gain;
        survivor.health += activity.health_cost;

        // Print the survivor's updated stats
        printf("\nSurvivor: %s\n", survivor.name);
        printf("Strength: %d\n", survivor.strength);
        printf("Agility: %d\n", survivor.agility);
        printf("Endurance: %d\n", survivor.endurance);
        printf("Health: %d\n", survivor.health);
    }

    // The survivor has died
    printf("\n%s has fallen in the wasteland.\n", survivor.name);

    return 0;
}