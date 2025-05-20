//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_YEARS 1000

struct Alien {
    int year;
    int probability;
};

void generateAliens(struct Alien aliens[], int numAliens) {
    srand(time(NULL));
    for (int i = 0; i < numAliens; i++) {
        aliens[i].year = rand() % MAX_YEARS + 1;
        aliens[i].probability = rand() % 101;
    }
}

void sortAliens(struct Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens - 1; i++) {
        for (int j = i + 1; j < numAliens; j++) {
            if (aliens[j].year < aliens[i].year) {
                struct Alien temp = aliens[i];
                aliens[i] = aliens[j];
                aliens[j] = temp;
            }
        }
    }
}

void printAliens(struct Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        printf("Year %d: %d%% chance of alien invasion\n", aliens[i].year, aliens[i].probability);
    }
}

int main() {
    int numAliens;
    printf("Enter the number of aliens to generate (max %d): ", MAX_ALIENS);
    scanf("%d", &numAliens);

    struct Alien aliens[MAX_ALIENS];
    generateAliens(aliens, numAliens);
    sortAliens(aliens, numAliens);
    printAliens(aliens, numAliens);

    return 0;
}