//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_DISTANCE 100

typedef struct {
    char name[20];
    int distance;
} Planet;

void generatePlanets(Planet planets[]) {
    int i;
    for (i = 0; i < MAX_PLANETS; i++) {
        planets[i].distance = rand() % MAX_DISTANCE + 1;
        sprintf(planets[i].name, "Planet %d", i + 1);
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    int choice;
    int distance;
    int planetIndex;
    int fuel;

    srand(time(NULL));
    generatePlanets(planets);

    printf("Welcome to the Space Adventure!\n");
    printf("You have %d units of fuel left.\n", 100);

    while (fuel > 0) {
        printf("\n");
        printf("You are currently at Planet %s.\n", planets[0].name);
        printf("You have %d units of fuel left.\n", fuel);
        printf("What would you like to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Refuel\n");
        printf("3. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n");
            printf("Which planet would you like to travel to?\n");
            for (planetIndex = 0; planetIndex < MAX_PLANETS; planetIndex++) {
                printf("%d. %s (%d units of fuel)\n", planetIndex + 1, planets[planetIndex].name, planets[planetIndex].distance);
            }
            printf("> ");
            scanf("%d", &planetIndex);

            distance = planets[planetIndex].distance;
            fuel -= distance;

            if (fuel < 0) {
                printf("\n");
                printf("You don't have enough fuel to reach that planet.\n");
            } else {
                printf("\n");
                printf("You have arrived at Planet %s.\n", planets[planetIndex].name);
            }
            break;

        case 2:
            printf("\n");
            printf("You have refueled and now have 100 units of fuel.\n");
            fuel = 100;
            break;

        case 3:
            printf("\n");
            printf("Thanks for playing!\n");
            break;

        default:
            printf("\n");
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}