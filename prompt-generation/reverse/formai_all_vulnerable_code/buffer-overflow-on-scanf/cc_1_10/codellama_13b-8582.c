//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_ALIENS 100
#define MIN_ALIENS 1
#define PROB_ALIEN_ATTACK 0.05
#define PROB_ALIEN_DEFEND 0.10
#define PROB_ALIEN_RETREAT 0.05
#define PROB_ALIEN_SUCCESS 0.15

// Define struct for aliens
struct aliens {
    int x;
    int y;
    int health;
    int attack;
    int defend;
    int retreat;
    int success;
};

// Function to calculate the probability of an alien attacking
int alien_attack(int health, int attack, int defend) {
    return (rand() % 100) < PROB_ALIEN_ATTACK * health;
}

// Function to calculate the probability of an alien defending
int alien_defend(int health, int attack, int defend) {
    return (rand() % 100) < PROB_ALIEN_DEFEND * health;
}

// Function to calculate the probability of an alien retreating
int alien_retreat(int health, int attack, int defend) {
    return (rand() % 100) < PROB_ALIEN_RETREAT * health;
}

// Function to calculate the probability of an alien success
int alien_success(int health, int attack, int defend) {
    return (rand() % 100) < PROB_ALIEN_SUCCESS * health;
}

// Function to calculate the probability of an alien invasion
int alien_invasion(int num_aliens, int health, int attack, int defend) {
    int alien_actions = 0;
    for (int i = 0; i < num_aliens; i++) {
        if (alien_attack(health, attack, defend)) {
            alien_actions++;
        }
        if (alien_defend(health, attack, defend)) {
            alien_actions++;
        }
        if (alien_retreat(health, attack, defend)) {
            alien_actions++;
        }
        if (alien_success(health, attack, defend)) {
            alien_actions++;
        }
    }
    return alien_actions;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Declare variables
    int num_aliens;
    int health;
    int attack;
    int defend;

    // Get number of aliens from user
    printf("Enter number of aliens: ");
    scanf("%d", &num_aliens);

    // Get health, attack, and defend values from user
    printf("Enter health, attack, and defend values: ");
    scanf("%d %d %d", &health, &attack, &defend);

    // Calculate probability of alien invasion
    int prob_invasion = alien_invasion(num_aliens, health, attack, defend);

    // Print result
    printf("Probability of alien invasion: %d%%\n", prob_invasion);

    return 0;
}