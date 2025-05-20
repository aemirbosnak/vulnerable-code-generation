//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 5
#define MAX_DISTANCE 10

typedef struct {
    int x;
    int y;
} Coordinates;

typedef struct {
    char name[20];
    int distance;
    Coordinates location;
} Planet;

void generate_planets(Planet* planets) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLANETS; i++) {
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].distance = rand() % MAX_DISTANCE + 1;
        planets[i].location.x = rand() % 100;
        planets[i].location.y = rand() % 100;
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    generate_planets(planets);

    printf("Welcome to the Space Adventure Game!\n");
    printf("You are on planet Earth and your mission is to visit all %d planets.\n", NUM_PLANETS);

    int current_planet = 0;
    int current_distance = 0;
    while (current_planet < NUM_PLANETS) {
        Planet current = planets[current_planet];
        printf("\nCurrent planet: %s\n", current.name);
        printf("Distance from Earth: %d light years\n", current.distance);
        printf("Coordinates: (%d,%d)\n", current.location.x, current.location.y);
        
        if (current_distance >= current.distance) {
            printf("Congratulations, you have made it to %s!\n", current.name);
            current_planet++;
            current_distance = 0;
        } else {
            printf("You are currently %d light years away from %s.\n", current.distance - current_distance, current.name);
            printf("What would you like to do? (1: Move closer, 2: Stay put, 3: Quit)\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You moved closer to %s.\n", current.name);
                current_distance++;
            } else if (choice == 2) {
                printf("You stayed put on the current planet.\n");
            } else if (choice == 3) {
                printf("Game over. You quit the space adventure. Try again next time!\n");
                return 0;
            } else {
                printf("Invalid choice. Please choose again.\n");
            }
        }
    }

    printf("Congratulations, you have visited all %d planets and completed the space adventure!\n", NUM_PLANETS);
    return 0;
}