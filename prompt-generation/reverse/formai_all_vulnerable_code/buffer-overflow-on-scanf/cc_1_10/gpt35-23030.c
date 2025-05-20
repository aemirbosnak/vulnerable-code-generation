//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DISTANCE 100
#define MAX_ENERGY 100
#define FUEL_UNIT 5

typedef struct {
    char name[50];
    int distance;
    int energy;
    int fuel;
    int credits;
} Ship;

void printStatus(Ship ship) {
    printf("==== SHIP STATUS ====\n");
    printf("Name: %s\n", ship.name);
    printf("Distance from Earth: %d light years\n", ship.distance);
    printf("Energy Level: %d%%\n", ship.energy);
    printf("Fuel Level: %d/%d units\n", ship.fuel, MAX_ENERGY);
    printf("Credits: %d\n", ship.credits);
}

int randomEvent() {
    return rand() % 4;
}

void encounterAlien(Ship *ship) {
    printf("You encounter an alien species! They offer to trade technology for credits.\n");
    int cost = rand() % (ship->credits / 2) + 1;
    int techLevel = rand() % 3 + 1;
    printf("Technology level: %d\n", techLevel);
    printf("Cost: %d credits\n", cost);
    printf("Do you want to purchase this technology? (y/n)\n");
    char response;
    scanf(" %c", &response);
    if(response == 'y') {
        ship->credits -= cost;
        printf("Purchase successful! Technology acquired.\n");
    }
}

void findArtifact(Ship *ship) {
    printf("You discover an ancient artifact!\n");
    int value = rand() % 1001 + 500;
    printf("This artifact is estimated to be worth %d credits.\n", value);
    printf("Do you want to sell this artifact for credits? (y/n)\n");
    char response;
    scanf(" %c", &response);
    if(response == 'y') {
        ship->credits += value;
        printf("Artifact sold successfully! Credits acquired.\n");
    }
}

void runOutOfFuel(Ship *ship) {
    printf("You have run out of fuel and are stranded in space. Game over.\n");
    exit(0);
}

void winGame(Ship ship) {
    printf("Congratulations, %s! You have reached the edge of the universe and are the first human to do so!\n", ship.name);
    printf("Final score: %d credits\n", ship.credits);
    exit(0);
}

int main() {
    srand(time(NULL));
    Ship ship;
    strcpy(ship.name, "Odyssey");
    ship.distance = 0;
    ship.energy = 100;
    ship.fuel = MAX_ENERGY;
    ship.credits = 0;
    printStatus(ship);
    while(ship.distance < MAX_DISTANCE) {
        printf("Choose an action:\n");
        printf("1. Travel to a nearby galaxy\n");
        printf("2. Refuel your ship\n");
        printf("3. Check ship status\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(ship.energy < 20) {
                    printf("Energy level too low. Please refuel your ship.\n");
                }
                else {
                    int distanceTraveled = rand() % 11 + 10;
                    ship.distance += distanceTraveled;
                    ship.energy -= distanceTraveled;
                    ship.fuel -= FUEL_UNIT;
                    int event = randomEvent();
                    if(event == 0) {
                        encounterAlien(&ship);
                    }
                    else if(event == 1) {
                        findArtifact(&ship);
                    }
                    else if(event == 2) {
                        printf("You pass through a magnetic asteroid field, which damages your ship's equipment. Energy level reduced by 10%%.\n");
                        ship.energy -= 10;
                    }
                    else {
                        printf("Nothing out of the ordinary happens on this journey.\n");
                    }
                    if(ship.fuel <= 0) {
                        runOutOfFuel(&ship);
                    }
                    if(ship.distance >= MAX_DISTANCE) {
                        winGame(ship);
                    }
                }
                break;
            case 2:
                if(ship.credits < 50) {
                    printf("Not enough credits to refuel your ship.\n");
                }
                else {
                    printf("Refueling your ship...\n");
                    ship.fuel = MAX_ENERGY;
                    ship.credits -= 50;
                    printf("Refueling complete. Fuel level back to maximum.\n");
                }
                break;
            case 3:
                printStatus(ship);
                break;
            default:
                printf("Invalid choice. Please enter 1-3.\n");
        }
    }
    return 0;
}