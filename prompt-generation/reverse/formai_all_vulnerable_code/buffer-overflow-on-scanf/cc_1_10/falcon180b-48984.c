//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateGalaxy(int width, int height) {
    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void generatePlanets(int width, int height, int numPlanets) {
    srand(time(NULL));
    int i, j, x, y, planetSize;
    for(i = 0; i < numPlanets; i++) {
        x = rand() % width;
        y = rand() % height;
        planetSize = rand() % 5 + 1;
        for(j = 0; j < planetSize; j++) {
            if(x - j >= 0 && x - j < width) {
                printf("O");
            } else if(x + j >= 0 && x + j < width) {
                printf("O");
            } else if(y - j >= 0 && y - j < height) {
                printf("O");
            } else if(y + j >= 0 && y + j < height) {
                printf("O");
            }
        }
    }
}

void generateStars(int width, int height, int numStars) {
    srand(time(NULL));
    int i, j, x, y;
    for(i = 0; i < numStars; i++) {
        x = rand() % width;
        y = rand() % height;
        printf("*");
    }
}

int main() {
    int width, height, numPlanets, numStars;
    printf("Enter the width of the galaxy: ");
    scanf("%d", &width);
    printf("Enter the height of the galaxy: ");
    scanf("%d", &height);
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);
    printf("Enter the number of stars: ");
    scanf("%d", &numStars);

    generateGalaxy(width, height);
    generatePlanets(width, height, numPlanets);
    generateStars(width, height, numStars);

    return 0;
}