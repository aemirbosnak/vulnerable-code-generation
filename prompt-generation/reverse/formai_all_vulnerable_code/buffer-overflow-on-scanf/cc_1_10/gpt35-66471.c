//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10

typedef struct planet {
    char name[20];
    int distance;
    int fuel_cost;
} Planet;

Planet solar_system[MAX_PLANETS] = { //preset planets
    {"Mercury", 36, 10},
    {"Venus", 67, 18},
    {"Earth", 93, 25},
    {"Mars", 142, 30},
    {"Jupiter", 484, 50},
    {"Saturn", 886, 70},
    {"Uranus", 1782, 90},
    {"Neptune", 2793, 110},
    {"Pluto", 3672, 130},
    {"Alpha Centauri", 4125, 150}
};

void show_map() { //prints out available planets
    printf("PLANET\tDISTANCE\tFUEL COST\n");
    for(int i = 0; i < MAX_PLANETS; i++) {
        printf("%s\t%d\t\t%d\n", solar_system[i].name, solar_system[i].distance, solar_system[i].fuel_cost);
    }
}

void travel(int *fuel, int *distance, char *curr_planet) { //travels to new planet, updating fuel and distance
    int index;
    do {
        printf("Enter planet to travel to: ");
        scanf("%s", curr_planet);
        
        for(int i = 0; i < MAX_PLANETS; i++) {
            if(strcmp(curr_planet, solar_system[i].name) == 0) {
                index = i;
                break;
            }
        }
        
        if(strcmp(curr_planet, solar_system[index].name) == 0) {
            if(*fuel < solar_system[index].fuel_cost) {
                printf("Insufficient fuel for travel.\n");
            } else {
                *fuel -= solar_system[index].fuel_cost;
                *distance = solar_system[index].distance;
                printf("Travel to %s was successful!\n", curr_planet);
            }
        } else {
            printf("Invalid planet name. Please try again.\n");
        }
    } while(strcmp(curr_planet, solar_system[index].name) != 0);
}

int main() {
    srand(time(NULL)); //seed random number generator
    char choice;
    char curr_planet[20];
    int fuel = 100;
    int distance = 0;
    int random_index = rand() % 6 + 1; //generates random number between 1 and 6
    
    printf("Welcome to the Space Adventure Game!\n");
    printf("You have been assigned to travel from Earth to the furthest planet in our Solar System.\n");
    printf("You have 100 fuel points to start with.\n");
    printf("Let's begin the adventure!\n\n");
    
    do { //game loop
        printf("Current Planet: %s\n", solar_system[random_index].name);
        printf("Distance to next planet: %d\n", solar_system[random_index].distance - distance);
        printf("Fuel remaining: %d\n\n", fuel);
        
        printf("Menu:\n");
        printf("1. Show Map\n");
        printf("2. Travel to new Planet\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                show_map();
                break;
            case '2':
                travel(&fuel, &distance, curr_planet);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        if(distance >= solar_system[MAX_PLANETS-1].distance && fuel > 0) { //winning condition
            printf("Congratulations! You have reached the furthest planet in our Solar System!\n");
            printf("You have accomplished your mission. Thank you for playing!\n");
            break;
        }
        
        if(fuel <= 0) { //losing condition
            printf("Game over. You have run out of fuel points.\n");
            break;
        }
        
        random_index = rand() % 6 + 1; //updates to new random planet
    } while(choice != '3');
    
    return 0;
}