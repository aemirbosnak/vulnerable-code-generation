//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_galaxy(int width, int height) {
    int x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            if (rand() % 2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_planet(int x, int y, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (rand() % 2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int width, height, planet_size;

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter the width of the galaxy: ");
    scanf("%d", &width);
    printf("Please enter the height of the galaxy: ");
    scanf("%d", &height);
    printf("Please enter the size of the planet: ");
    scanf("%d", &planet_size);

    generate_galaxy(width, height);

    int planet_x, planet_y;
    do {
        planet_x = rand() % width;
        planet_y = rand() % height;
    } while (planet_x == 0 || planet_y == 0 || planet_x == width - 1 || planet_y == height - 1);

    generate_planet(planet_x, planet_y, planet_size);

    return 0;
}