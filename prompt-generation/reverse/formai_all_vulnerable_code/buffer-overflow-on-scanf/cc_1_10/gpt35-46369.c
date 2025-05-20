//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>

//function to print the current status of the spaceship
void printStatus(char spacecraft[], int fuel_level, int oxygen_level, int distance) {
    printf("\n--- Current Status ---\n");
    printf("%s's fuel level: %d\n", spacecraft, fuel_level);
    printf("%s's oxygen level: %d\n", spacecraft, oxygen_level);
    printf("Distance Travelled: %d\n", distance);
}

//function to simulate a space battle
int spaceBattle(char spacecraft[], int fuel_level, int oxygen_level, int distance) {
    printf("\n--- Space Battle ---\n");
    printf("%s is being attacked by alien ships!\n", spacecraft);
    printf("Defend the ship!\n");

    //reduce fuel and oxygen levels by random amounts
    int fuel_reduction = rand() % 20 + 10;
    int oxygen_reduction = rand() % 15 + 5;
    fuel_level -= fuel_reduction;
    oxygen_level -= oxygen_reduction;

    //return -1 if spaceship is destroyed
    if(fuel_level <= 0 || oxygen_level <= 0) {
        printf("%s has been destroyed! Game Over.\n", spacecraft);
        return -1;
    }

    printf("%s won the space battle! Continue on your quest.\n", spacecraft);
    distance += rand() % 100 + 50;
    return distance;
}

//function to simulate a refueling stop at a space station
int refuelStop(char spacecraft[], int fuel_level, int oxygen_level, int distance) {
    printf("\n--- Refueling Stop ---\n");
    printf("%s has stopped at a space station to refuel.\n", spacecraft);

    //add fuel and oxygen
    int fuel_added = rand() % 30 + 10;
    int oxygen_added = rand() % 25 + 10;
    fuel_level += fuel_added;
    oxygen_level += oxygen_added;

    //make sure levels don't exceed 100
    if(fuel_level > 100) {
        fuel_level = 100;
    }
    if(oxygen_level > 100) {
        oxygen_level = 100;
    }

    printf("%s has refueled and added %d fuel and %d oxygen.\n", spacecraft, fuel_added, oxygen_added);
    return distance;
}

int main() {
    //initialize spaceship stats and variables
    char spaceship[20];
    int fuel_level = 100;
    int oxygen_level = 100;
    int distance_travelled = 0;

    //gather player input
    printf("What is your spaceship's name? ");
    scanf("%s", spaceship);

    //game loop
    while(1) {
        //print current status of spaceship
        printStatus(spaceship, fuel_level, oxygen_level, distance_travelled);

        //ask player for action
        char choice;
        printf("\nWhat would you like to do? (B)attle, (R)efuel, or (Q)uit? ");
        scanf(" %c", &choice);

        //perform action based on player choice
        if(choice == 'B' || choice == 'b') {
            distance_travelled = spaceBattle(spaceship, fuel_level, oxygen_level, distance_travelled);
            if(distance_travelled == -1) {
                break;
            }
        }
        else if(choice == 'R' || choice == 'r') {
            distance_travelled = refuelStop(spaceship, fuel_level, oxygen_level, distance_travelled);
        }
        else if(choice == 'Q' || choice == 'q') {
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

        //reduce fuel and oxygen levels by random amounts
        fuel_level -= rand() % 20 + 10;
        oxygen_level -= rand() % 15 + 5;

        //check if spaceship has run out of fuel or oxygen
        if(fuel_level <= 0 || oxygen_level <= 0) {
            printf("%s has run out of fuel or oxygen! Game over.\n", spaceship);
            break;
        }
    }

    return 0;
}