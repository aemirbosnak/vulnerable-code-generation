//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printIntro() {
    printf("\n\nWelcome to the Decentralized Space Adventure.\n\n");
    printf("You wake up on an unknown planet. You look around to find everything strange and unfamiliar.\n");
    printf("The air feels different. The ground looks weird.\n\n");
    printf("You see two moons rising over the horizon, and many stars shinning above you.\n");
    printf("You realized that you are stranded in an unknown planet with no idea\n");
    printf("about how you got here and how to get back to your home planet.\n\n");
    printf("Your only hope is to find a way to communicate and ask for help to get back home.\n\n");
}

void printPlanetInfo() {
    printf("\n\nYou look around and see that the planet is full of life. Many strange creatures\n");
    printf("are roaming around, some flying and some swimming. You also see that\n");
    printf("there are some ruins of what seems to be an ancient civilization that might\n");
    printf("have vanished a long time ago.\n\n");
}

void printPlanetMap() {
    printf("\n\nYou have decided to explore the planet and hopefully find a way home.\n");
    printf("You have a map of the planet and have marked a few locations that look interesting.\n");
    printf("You start your journey towards the first location on your map.\n\n");
}

int rollDice(int diceSize) {
    return rand() % diceSize + 1;
}

void printDiceRoll(int rolls[], int count, int total) {
    printf("\n\nYou roll the dice and get: ");
    for(int i = 0; i < count - 1; i++) {
        printf("%d, ", rolls[i]);
    }
    printf("%d. Total: %d", rolls[count - 1], total);
}

int main() {
    srand(time(NULL));
    int distToHQ = 10000;
    int distToSignal = 5000;
    int distToCom = 3000;
    int distToShip = 1000;
    int loc = 0;
    int rolls[3];
    int total = 0;
    
    printIntro();
    
    while(1) {
        printf("\n\nYou are currently at location %d. Where do you want to go?\n", loc);
        printf("1. Headquarters (distance %d)\n", distToHQ);
        printf("2. Signal Station (distance %d)\n", distToSignal);
        printf("3. Communications Center (distance %d)\n", distToCom);
        printf("4. Abandoned Ship (distance %d)\n", distToShip);
        printf("\nChoice: ");
        
        int choice;
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("\n\nYou start your journey towards Headquarters.\n");
            int rolls[3];
            rolls[0] = rollDice(6);
            rolls[1] = rollDice(6);
            rolls[2] = rollDice(6);
            total = rolls[0] + rolls[1] + rolls[2];
            printDiceRoll(rolls, 3, total);
            loc = 1;
        }
        else if(choice == 2) {
            printf("\n\nYou start your journey towards Signal Station.\n");
            int rolls[2];
            rolls[0] = rollDice(6);
            rolls[1] = rollDice(6);
            total = rolls[0] + rolls[1];
            printDiceRoll(rolls, 2, total);
            loc = 2;
        }
        else if(choice == 3) {
            printf("\n\nYou start your journey towards Communications Center.\n");
            int rolls[1];
            rolls[0] = rollDice(6);
            total = rolls[0];
            printDiceRoll(rolls, 1, total);
            loc = 3;
        }
        else if(choice == 4) {
            printf("\n\nYou start your journey towards the abandoned ship.\n");
            int rolls[3];
            rolls[0] = rollDice(6);
            rolls[1] = rollDice(6);
            rolls[2] = rollDice(6);
            total = rolls[0] + rolls[1] + rolls[2];
            printDiceRoll(rolls, 3, total);
            loc = 4;
        }
        else {
            printf("\n\nInvalid choice. Please try again.\n");
            continue;
        }
        
        if(loc == 1) {
            if(total >= distToHQ) {
                printf("\n\nYou have finally reached Headquaters.\n");
                printf("You managed to contact the authorities and they will send a rescue team for you.\n");
                printf("Congratulations, You Won the Game!\n\n");
                break;
            } else {
                distToHQ -= total;
            }
        } else if(loc == 2) {
            if(total >= distToSignal) {
                printf("\n\nYou have finally reached Signal Station.\n");
                printf("You found a way to comunicate with a distant planet.\n");
                printf("You tried to ask for help, but they did not understand you.\n\n");
                printPlanetInfo();
            } else {
                distToSignal -= total;
            }
        } else if(loc == 3) {
            if(total >= distToCom) {
                printf("\n\nYou have finally reached the Communications Center.\n");
                printf("You searched the logs, but found nothing helpful.\n\n");
                printPlanetMap();
            } else {
                distToCom -= total;
            }
        } else if(loc == 4) {
            if(total >= distToShip) {
                printf("\n\nYou have finally reached the Abandoned Ship.\n");
                printf("You found lots of supplies, but nothing that will help you leave this planet.\n\n");
                printPlanetMap();
            } else {
                distToShip -= total;
            }
        }
    }
    
    return 0;
}