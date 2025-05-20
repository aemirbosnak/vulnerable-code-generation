//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void printIntro(){
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You have been sent on a mission to explore the unknown depths of space, and discover new worlds and civilizations.\n");
    printf("But beware, danger lurks in every corner of space, and you must be prepared to face it!\n");
    printf("Your ship has a limited supply of fuel and resources, so use them wisely.\n");
    printf("Good luck, Captain!\n");
}

void printOptions(int fuel, int resources){
    printf("You have %d units of fuel and %d units of resources.\n", fuel, resources);
    printf("What would you like to do next?\n");
    printf("1. Explore a new planet.\n");
    printf("2. Search for resources.\n");
    printf("3. Upgrade your ship.\n");
    printf("4. Refuel your ship.\n");
    printf("5. Check your inventory.\n");
    printf("6. Exit game.\n");
}

int getPlayerChoice(){
    int choice;
    scanf("%d", &choice);
    return choice;
}

bool checkFuel(int fuel){
    if(fuel <= 0){
        printf("You have run out of fuel and are stranded in space!\n");
        return false;
    }
    return true;
}

void explorePlanet(int *fuel, int *resources){
    printf("You have arrived at a new planet!\n");
    printf("Scanning planet for resources...\n");
    *fuel -= 10;
    *resources += (rand() % 10) + 1;
    printf("You have found %d units of resources!\n", (rand() % 10) + 1);
}

void searchResources(int *fuel, int *resources){
    printf("You are searching for resources...\n");
    *fuel -= 5;
    *resources += (rand() % 5) + 1;
    printf("You have found %d units of resources!\n", (rand() % 5) + 1);
}

void upgradeShip(int *fuel, int *resources){
    printf("You are upgrading your ship with your resources...\n");
    *fuel -= 5;
    *resources -= 10;
    printf("Your ship has been upgraded!\n");
}

void refuelShip(int *fuel, int *resources){
    printf("You are refueling your ship with your resources...\n");
    *fuel += 20;
    *resources -= 5;
    printf("Your ship has been refueled!\n");
}

void checkInventory(int fuel, int resources){
    printf("You have the following items in your inventory:\n");
    printf("Fuel: %d units\n", fuel);
    printf("Resources: %d units\n", resources);
}

int main(){
    srand(time(NULL));
    int fuel = 50;
    int resources = 50;
    bool play = true;
    int choice;
    
    printIntro();
    
    while(play){
        printOptions(fuel, resources);
        choice = getPlayerChoice();
        
        switch(choice){
            case 1:
                if(checkFuel(fuel)){
                    explorePlanet(&fuel, &resources);
                }
                break;
            case 2:
                if(checkFuel(fuel)){
                    searchResources(&fuel, &resources);
                }
                break;
            case 3:
                upgradeShip(&fuel, &resources);
                break;
            case 4:
                refuelShip(&fuel, &resources);
                break;
            case 5:
                checkInventory(fuel, resources);
                break;
            case 6:
                play = false;
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    printf("Thanks for playing!\n");
    
    return 0;
}