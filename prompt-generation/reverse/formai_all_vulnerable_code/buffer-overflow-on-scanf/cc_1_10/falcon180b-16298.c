//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 100
#define MAX_ATTACKS 10
#define MIN_ATTACK_DELAY 1
#define MAX_ATTACK_DELAY 10
#define MIN_ALIEN_STRENGTH 1
#define MAX_ALIEN_STRENGTH 10
#define MIN_DEFENSE_STRENGTH 1
#define MAX_DEFENSE_STRENGTH 10
#define MIN_RANDOM_NUMBER 1
#define MAX_RANDOM_NUMBER 100

// Function to generate a random number within a given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien attack
void simulateAttack(int alienStrength, int defenseStrength) {
    int attackDelay = generateRandomNumber(MIN_ATTACK_DELAY, MAX_ATTACK_DELAY);
    printf("An alien with strength %d has attacked! The attack will happen in %d seconds.\n", alienStrength, attackDelay);
    sleep(attackDelay);
    int attackResult = generateRandomNumber(MIN_RANDOM_NUMBER, MAX_RANDOM_NUMBER);
    if (attackResult > defenseStrength) {
        printf("The attack was successful! The aliens have invaded Earth.\n");
        exit(0);
    } else {
        printf("The attack was unsuccessful! The aliens were repelled.\n");
    }
}

// Function to simulate multiple alien attacks
void simulateInvasion(int aliens, int attacks, int defenseStrength) {
    printf("The aliens are invading! There are %d aliens with strengths ranging from %d to %d.\n", aliens, MIN_ALIEN_STRENGTH, MAX_ALIEN_STRENGTH);
    for (int i = 0; i < aliens; i++) {
        int alienStrength = generateRandomNumber(MIN_ALIEN_STRENGTH, MAX_ALIEN_STRENGTH);
        printf("Alien #%d has strength %d.\n", i + 1, alienStrength);
        simulateAttack(alienStrength, defenseStrength);
    }
}

int main() {
    int defenseStrength;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter your defense strength (1-10): ");
    scanf("%d", &defenseStrength);
    srand(time(NULL));
    int aliens = generateRandomNumber(1, MAX_ALIENS);
    int attacks = generateRandomNumber(1, MAX_ATTACKS);
    printf("There are %d aliens with strengths ranging from %d to %d.\n", aliens, MIN_ALIEN_STRENGTH, MAX_ALIEN_STRENGTH);
    simulateInvasion(aliens, attacks, defenseStrength);
    return 0;
}