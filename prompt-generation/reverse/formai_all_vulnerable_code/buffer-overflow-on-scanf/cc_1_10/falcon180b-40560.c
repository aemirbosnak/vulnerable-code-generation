//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_DISTANCE 1000000

typedef struct {
    int x;
    int y;
    int distance;
} Alien;

void generateAliens(Alien *aliens, int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        aliens[i].x = rand() % MAX_DISTANCE;
        aliens[i].y = rand() % MAX_DISTANCE;
        aliens[i].distance = 0;
    }
}

void calculateDistances(Alien *aliens, int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        for (int j = i + 1; j < numAliens; j++) {
            int dx = aliens[i].x - aliens[j].x;
            int dy = aliens[i].y - aliens[j].y;
            int distance = sqrt(dx * dx + dy * dy);
            if (distance < aliens[i].distance) {
                aliens[i].distance = distance;
            }
        }
    }
}

int main() {
    int numAliens;
    printf("Enter the number of aliens: ");
    scanf("%d", &numAliens);

    srand(time(NULL));

    Alien *aliens = malloc(numAliens * sizeof(Alien));

    generateAliens(aliens, numAliens);
    calculateDistances(aliens, numAliens);

    for (int i = 0; i < numAliens; i++) {
        printf("Alien %d is %d units away from the nearest alien.\n", i + 1, aliens[i].distance);
    }

    free(aliens);

    return 0;
}