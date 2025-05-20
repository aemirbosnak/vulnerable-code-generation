//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_WEAPONS 5

struct Planet {
    char name[20];
    int distance;
    int population;
};

struct Weapon {
    char name[20];
    int power;
};

struct SpaceShip {
    char name[20];
    int health;
    int fuel;
    struct Weapon WeaponArray[MAX_WEAPONS];
};

void print_planets(struct Planet planet_array[], int size) {
    printf("Planet\tDistance\tPopulation\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%d\t\t%d\n", planet_array[i].name, planet_array[i].distance, planet_array[i].population);
    }
}

void print_weapons(struct SpaceShip ship) {
    printf("Weapons:\n");
    for(int i=0; i<MAX_WEAPONS; i++) {
        printf("%d. %s (Power: %d)\n", i+1, ship.WeaponArray[i].name, ship.WeaponArray[i].power);
    }
}

void travel(struct SpaceShip *ship, struct Planet planet) {
    int travel_time = planet.distance/10;
    if(ship->fuel >= travel_time) {
        printf("Travelling to %s...\n", planet.name);
        ship->fuel -= travel_time;
        printf("Arrived at %s. Distance travelled: %d\n\n", planet.name, planet.distance);
    }
    else {
        printf("Not enough fuel to travel to %s. Refuel first.\n\n", planet.name);
    }
}

void attack(struct SpaceShip *ship, struct SpaceShip *enemy_ship) {
    int choice;
    printf("Choose a weapon:\n");
    print_weapons(*ship);
    printf("Enter choice: ");
    scanf("%d", &choice);
    int power = ship->WeaponArray[choice-1].power;
    enemy_ship->health -= power;
    printf("Attacked with %s. Enemy health: %d\n\n", ship->WeaponArray[choice-1].name, enemy_ship->health);
}

int main() {
    srand(time(NULL));
    
    struct Planet planet_array[MAX_PLANETS] = {
        {"Earth", 0, 1000},
        {"Mars", 100, 200},
        {"Jupiter", 500, 5000},
        {"Saturn", 800, 10000},
        {"Uranus", 1200, 8000},
        {"Neptune", 1500, 3000},
        {"Pluto", 2000, 50},
        {"Mercury", 50, 500},
        {"Venus", 200, 100},
        {"Moon", 10, 50}
    };
    
    struct Weapon weapon_array[MAX_WEAPONS] = {
        {"Laser", 25},
        {"Missile", 50},
        {"Plasma Cannon", 75},
        {"Neutron Bomb", 100},
        {"EMP", 15}
    };
    
    struct SpaceShip my_ship = {"Enterprise", 100, 100, {weapon_array[0], weapon_array[1], weapon_array[2], weapon_array[3], weapon_array[4]}};
    struct SpaceShip enemy_ship = {"Klingon", 100, 100, {weapon_array[0], weapon_array[1], weapon_array[2], weapon_array[3], weapon_array[4]}};
    
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of the spaceship %s\n\n", my_ship.name);
    
    while(1) {
        printf("Current status:\nHealth: %d\nFuel: %d\n\n", my_ship.health, my_ship.fuel);
        printf("Choose an option:\n");
        printf("1. Travel to a planet\n");
        printf("2. Refuel\n");
        printf("3. Attack enemy ship\n");
        printf("4. Quit game\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Available planets:\n");
                print_planets(planet_array, MAX_PLANETS);
                int planet_choice;
                printf("Enter planet number to travel to: ");
                scanf("%d", &planet_choice);
                travel(&my_ship, planet_array[planet_choice-1]);
                break;
            }
            case 2: {
                my_ship.fuel = 100;
                printf("Refueled. Fuel: %d\n\n", my_ship.fuel);
                break;
            }
            case 3: {
                attack(&my_ship, &enemy_ship);
                if(enemy_ship.health <= 0) {
                    printf("You won! Congratulations!\n");
                    exit(0);
                }
                break;
            }
            case 4: {
                printf("Game over. Thanks for playing!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Enter again.\n");
                break;
            }
        }
        if(rand()%2) {
            printf("Enemy ship is attacking!\n");
            attack(&enemy_ship, &my_ship);
            if(my_ship.health <= 0) {
                printf("You lost! Better luck next time...\n");
                exit(0);
            }
        }
        printf("Enemy status:\nHealth: %d\nFuel: %d\n\n", enemy_ship.health, enemy_ship.fuel);
    }
    
    return 0;
}