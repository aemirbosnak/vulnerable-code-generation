//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayPlayerStatus(int health, int fuel, int shields);
int selectOption();
void displayPlanetInfo(int planetType);
void refuel(int* fuel);
void repair(int* health);
void upgradeShields(int* shields);
int travel(int* fuel);
void handleEvent(int planetType, int* health, int* fuel, int* shields, int* traveledDistance);
void victory();

int main() {
    //initialize variables and seed the random number generator
    int health = 100, fuel = 100, shields = 100, traveledDistance = 0;
    srand(time(NULL));

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Your goal is to travel through space and discover new planets.\n");
    printf("At each planet you visit, you will face different challenges.\n");
    printf("Your success depends on your ability to manage your resources.\n");
    printf("Enjoy your adventure!\n\n");

    //start the game loop
    while(health > 0 && traveledDistance < 1000) {
        displayPlayerStatus(health, fuel, shields);
        int option = selectOption();
        switch(option) {
            case 1:
                refuel(&fuel);
                break;
            case 2:
                repair(&health);
                break;
            case 3:
                upgradeShields(&shields);
                break;
            case 4:
                traveledDistance += travel(&fuel);
                int planetType = rand() % 3;
                displayPlanetInfo(planetType);
                handleEvent(planetType, &health, &fuel, &shields, &traveledDistance);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    //game over
    if(traveledDistance >= 1000) {
        victory();
    } else {
        printf("Game over. You failed to complete your mission.\n");
    }
    return 0;
}

//displays the player's current status
void displayPlayerStatus(int health, int fuel, int shields) {
    printf("Current Status:\n");
    printf("Health: %d\n", health);
    printf("Fuel: %d\n", fuel);
    printf("Shields: %d\n\n", shields);
}

//allows the player to select an option
int selectOption() {
    int option;
    printf("Select an option:\n");
    printf("1. Refuel\n");
    printf("2. Repair ship\n");
    printf("3. Upgrade shields\n");
    printf("4. Travel to new planet\n");
    scanf("%d", &option);
    return option;
}

//displays information about the planet the player has landed on
void displayPlanetInfo(int planetType) {
    printf("You have landed on a ");
    switch(planetType) {
        case 0:
            printf("barren");
            break;
        case 1:
            printf("toxic");
            break;
        case 2:
            printf("lush");
            break;
    }
    printf(" planet.\n");
}

//refuels the ship by a random amount
void refuel(int* fuel) {
    int amount = rand() % 21 + 10;
    *fuel += amount;
    printf("You have refueled by %d units.\n", amount);
}

//repairs the ship by a random amount
void repair(int* health) {
    int amount = rand() % 21 + 10;
    *health += amount;
    printf("You have repaired your ship by %d health points.\n", amount);
}

//upgrades the shields by a random amount
void upgradeShields(int* shields) {
    int amount = rand() % 21 + 10;
    *shields += amount;
    printf("You have upgraded your shields by %d points.\n", amount);
}

//allows the player to travel to a new planet, consuming fuel in the process
int travel(int* fuel) {
    int distance = rand() % 201 + 100;
    *fuel -= distance / 10;
    printf("You have traveled %d light years.\n", distance);
    printf("You have %d fuel remaining.\n", *fuel);
    return distance;
}

//handles the event that occurs on a planet, based on its type
void handleEvent(int planetType, int* health, int* fuel, int* shields, int* traveledDistance) {
    switch(planetType) {
        case 0:
            //barren planet, nothing happens
            printf("This planet is barren. There is nothing to do here.\n");
            break;
        case 1:
            //toxic planet, takes damage
            printf("This planet is toxic. The toxic atmosphere has damaged your ship.\n");
            *health -= 20;
            break;
        case 2:
            //lush planet, opportunity for extra resources
            printf("This planet is lush. You have the opportunity to collect extra resources.\n");
            printf("Would you like to search for resources? (y/n)\n");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'y') {
                int resource = rand() % 3 + 1;
                switch(resource) {
                    case 1:
                        printf("You have found a fuel cell and gained 25 fuel.\n");
                        *fuel += 25;
                        break;
                    case 2:
                        printf("You have found a repair kit and gained 25 health.\n");
                        *health += 25;
                        break;
                    case 3:
                        printf("You have found a shield booster and gained 25 shields.\n");
                        *shields += 25;
                        break;
                }
            }
            break;
    }
    //random chance to take damage from space debris
    int debris = rand() % 100;
    if(debris < 20) {
        printf("Your ship has been hit by space debris.\n");
        *shields -= 10;
        if(*shields < 0) {
            *health += *shields;
            *shields = 0;
            printf("Your shields were destroyed and your ship has taken %d damage.\n", -*shields);
        } else {
            printf("Your shields have taken 10 damage.\n");
        }
    }
    //increase traveled distance and display new status
    *traveledDistance += 50;
    displayPlayerStatus(*health, *fuel, *shields);
}

//called when the player reaches the end of their journey
void victory() {
    printf("Congratulations! You have successfully completed your mission!\n");
    printf("You have traveled 1000 light years and discovered new planets along the way!\n");
    printf("Thanks for playing Procedural Space Adventure!\n");
}