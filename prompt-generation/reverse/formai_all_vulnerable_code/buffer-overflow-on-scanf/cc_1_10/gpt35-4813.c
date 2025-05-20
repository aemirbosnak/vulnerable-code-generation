//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>
#include <stdlib.h> //for rand() and srand()
#include <time.h> //for time()

//function prototypes
void printIntro();
void enterShip();
void warpDrive();
void explore();
void encounterAlien();

int main() {
    srand(time(0)); //set the seed for rand() to the current time
    printIntro(); //call the printIntro function
    
    //game loop
    while (1) {
        int choice;
        printf("\n\nWhat do you want to do?\n");
        printf("1. Enter your spaceship\n");
        printf("2. Activate warp drive\n");
        printf("3. Explore a nearby planet\n");
        printf("4. Encounter an alien race\n");
        printf("5. Quit game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enterShip();
                break;
            case 2:
                warpDrive();
                break;
            case 3:
                explore();
                break;
            case 4:
                encounterAlien();
                break;
            case 5:
                printf("\n\nThanks for playing!");
                exit(0);
            default:
                printf("\n\nInvalid choice! Try again.");
                break;
        }
    }

    return 0;
}

void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of your own spaceship, exploring the vast expanse of space.\n");
    printf("Your mission is to chart new territories, make contact with new alien races, and bring back the riches of the universe.\n\n");
}

void enterShip() {
    printf("You enter your spaceship and prepare for launch.\n");
}

void warpDrive() {
    printf("You activate the warp drive and zoom through the galaxy at faster than light speed!\n");
}

void explore() {
    int chance = rand() % 10 + 1; //generate a random number between 1 and 10
    if (chance <= 5) {
        printf("You discover a planet that seems uninhabitable.\n");
    } else {
        printf("You discover a lush planet with abundant resources!\n");
    }
}

void encounterAlien() {
    int chance = rand() % 10 + 1; //generate a random number between 1 and 10
    if (chance <= 5) {
        printf("You encounter a friendly alien race who are willing to trade with you.\n");
    } else {
        printf("You encounter a hostile alien race who attack your ship!\n");
    }
}