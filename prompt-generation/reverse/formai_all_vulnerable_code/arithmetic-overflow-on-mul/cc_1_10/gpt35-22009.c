//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct planet {
    char name[20];
    int position;
    int resources;
};

void print_planet(struct planet p) {
    printf("Planet name: %s \nPosition: %d \nResources: %d\n\n", p.name, p.position, p.resources);
}

int main() {
    srand(time(NULL));

    struct planet planets[10];
    char names[10][20] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta", "Iota", "Kappa"};

    // randomly generate names, positions, and resources for the ten planets
    for (int i = 0; i < 10; i++) {
        struct planet p = {"", 0, 0};
        int r = rand() % 10;
        sprintf(p.name, "%s%d", names[r], i);
        p.position = i * 1000;
        p.resources = rand() % 10000;
        planets[i] = p;
    }

    // print out the generated planets
    printf("Generated planets: \n");
    for (int i = 0; i < 10; i++) {
        print_planet(planets[i]);
    }

    // travel between planets
    int current_location = 0;
    int fuel = 100000;
    while (fuel > 0) {
        printf("Fuel left: %d\n", fuel);
        printf("Current location: %s\n", planets[current_location].name);
        printf("Pick a planet to travel to: ");

        int destination_index;
        scanf("%d", &destination_index);

        if (destination_index < 0 || destination_index > 9 || destination_index == current_location) {
            printf("Invalid destination. Please choose again.\n");
            continue;
        }

        int distance = abs(planets[current_location].position - planets[destination_index].position);
        int fuel_cost = distance * rand() % 100;
        if (fuel < fuel_cost) {
            printf("Not enough fuel to travel that far. Please choose a closer destination.\n");
            continue;
        } 

        printf("Traveling to %s.\n", planets[destination_index].name);
        fuel -= fuel_cost;
        current_location = destination_index;
    }

    printf("Out of fuel. Game over.");

    return 0;
}