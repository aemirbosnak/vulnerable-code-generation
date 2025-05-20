//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 10000
#define MAX_YEARS 1000

// Alien struct
typedef struct {
    char name[20];
    int age;
    int strength;
    double probability;
} Alien;

// Function prototypes
void generateAliens(Alien aliens[], int numAliens);
double calculateInvasionProbability(Alien aliens[], int numAliens, int year);

int main() {
    Alien aliens[MAX_ALIENS];
    int numAliens;

    // Get number of aliens from user
    printf("Enter the number of aliens (max %d): ", MAX_ALIENS);
    scanf("%d", &numAliens);

    // Generate random aliens
    generateAliens(aliens, numAliens);

    // Calculate invasion probability for each year
    for (int year = 1; year <= MAX_YEARS; year++) {
        double probability = calculateInvasionProbability(aliens, numAliens, year);
        printf("Invasion probability in year %d: %.2f%%\n", year, probability * 100);
    }

    return 0;
}

// Generates random aliens
void generateAliens(Alien aliens[], int numAliens) {
    srand(time(NULL));

    for (int i = 0; i < numAliens; i++) {
        aliens[i].age = rand() % 1000;
        aliens[i].strength = rand() % 100;
        sprintf(aliens[i].name, "Alien %d", i + 1);
    }
}

// Calculates the probability of alien invasion in a given year
double calculateInvasionProbability(Alien aliens[], int numAliens, int year) {
    double totalStrength = 0;
    int aliveAliens = 0;

    for (int i = 0; i < numAliens; i++) {
        if (aliens[i].age + year > 0) {
            totalStrength += aliens[i].strength;
            aliveAliens++;
        }
    }

    return ((double)totalStrength / aliveAliens) * 100;
}