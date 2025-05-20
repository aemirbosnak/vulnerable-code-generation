//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 100

// Alien structure definition
typedef struct {
    int type;
    int strength;
    int speed;
    int agility;
} Alien;

// Function to initialize an alien
void initAlien(Alien* a) {
    a->type = rand() % 3;
    a->strength = rand() % 101;
    a->speed = rand() % 101;
    a->agility = rand() % 101;
}

// Function to print an alien's information
void printAlien(Alien a) {
    printf("Type: %d\n", a.type);
    printf("Strength: %d\n", a.strength);
    printf("Speed: %d\n", a.speed);
    printf("Agility: %d\n", a.agility);
}

// Function to simulate an alien invasion
int simulateInvasion(int numAliens) {
    int success = 0;
    int i;
    for (i = 0; i < numAliens; i++) {
        Alien a;
        initAlien(&a);
        if (a.strength > 50 && a.speed > 50 && a.agility > 50) {
            success++;
        }
    }
    return success;
}

// Main function
int main() {
    srand(time(NULL));
    int numAliens;
    printf("Enter the number of aliens to simulate an invasion with: ");
    scanf("%d", &numAliens);
    int success = simulateInvasion(numAliens);
    if (success > 0) {
        printf("The invasion was successful!\n");
    } else {
        printf("The invasion was unsuccessful.\n");
    }
    return 0;
}