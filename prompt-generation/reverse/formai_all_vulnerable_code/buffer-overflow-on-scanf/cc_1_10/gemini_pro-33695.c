//GEMINI-pro DATASET v1.0 Category: Educational ; Style: post-apocalyptic
// In the desolate wasteland, where silence echoes amidst shattered ruins, a lone scavenger roams the forsaken lands.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the scavenger's attributes
struct Scavenger {
    int health;
    int radiation;
    int supplies;
    char* name;
};

// Initialize the scavenger's journey
void startJourney(struct Scavenger* scavenger) {
    scavenger->health = 100;
    scavenger->radiation = 0;
    scavenger->supplies = 10;
    printf("Your name: ");
    char name[20];
    scanf("%s", name);
    scavenger->name = name;

    srand(time(NULL));
}

// Simulate a day of scavenging
void scavenge(struct Scavenger* scavenger) {
    // Randomly encounter events
    int event = rand() % 100;

    // Find supplies
    if (event < 30) {
        scavenger->supplies += rand() % 5;
        printf("Found %d supplies.\n", rand() % 5);
    }
    // Encounter radiation
    else if (event < 60) {
        scavenger->radiation += rand() % 5;
        printf("Exposed to %d rads.\n", rand() % 5);
    }
    // Battle mutants
    else if (event < 80) {
        // Determine battle outcome
        int battle = rand() % 100;
        if (battle < 50) {
            scavenger->health -= rand() % 10;
            printf("Attacked by mutants, lost %d health.\n", rand() % 10);
        } else {
            printf("Defeated mutants.\n");
        }
    }
    // Rest and recover
    else {
        scavenger->health += rand() % 5;
        scavenger->radiation -= rand() % 5;
        printf("Rested and recovered.\n");
    }

    // Check if scavenger survived
    if (scavenger->health <= 0) {
        printf("%s has perished in the wasteland.\n", scavenger->name);
        exit(0);
    }
}

// Display the scavenger's status
void showStatus(struct Scavenger scavenger) {
    printf("Health: %d\n", scavenger.health);
    printf("Radiation: %d\n", scavenger.radiation);
    printf("Supplies: %d\n", scavenger.supplies);
}

// Main function
int main() {
    // Create the scavenger
    struct Scavenger scavenger;
    startJourney(&scavenger);

    // Begin the scavenging journey
    printf("Your journey begins, %s.\n", scavenger.name);

    // Continue scavenging until the scavenger perishes or exits
    while (1) {
        // Scavenge for a day
        scavenge(&scavenger);

        // Display scavenger status
        showStatus(scavenger);

        // Check for exit command
        char command[10];
        printf("Enter 'exit' to end journey: ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            printf("Exiting wasteland.\n");
            exit(0);
        }
    }

    return 0;
}