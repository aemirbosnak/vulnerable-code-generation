//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to wait for some time before next action
void waitFor(unsigned int secs) {
    unsigned int retTime = time(0) + secs;   
    while (time(0) < retTime);               
}

int main() {
    int distance = 500000; //distance to reach the planet
    int fuel = 100; //initial fuel
    int choice;
    int travelTime;
    char planetName[20];
    
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are the captain of a spaceship traveling through the galaxy.\n");
    printf("Your mission is to reach the newly discovered planet.\n");
    printf("The planet is %d kilometers away from your current location.\n", distance);
    printf("You have %d units of fuel remaining.\n", fuel);
    
    //Loop until fuel runs out or planet reached
    while(fuel > 0 && distance > 0) {
        printf("\nWhat do you want to do?\n");
        printf("1. Travel at maximum speed\n");
        printf("2. Travel at half speed\n");
        printf("3. Wait for some time\n");
        printf("4. Refuel the spaceship\n");
        printf("5. Quit the game\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                travelTime = distance / 10000; //maximum speed
                distance -= 10000;
                fuel -= travelTime * 2; //maximum speed consumes double fuel
                printf("\nTraveling at maximum speed...\n");
                break;
            case 2:
                travelTime = distance / 20000; //half speed
                distance -= 20000;
                fuel -= travelTime; //half speed consumes normal fuel
                printf("\nTraveling at half speed...\n");
                break;
            case 3:
                waitFor(5); //wait for 5 seconds
                printf("\nWaiting for some time...\n");
                break;
            case 4:
                fuel += 50; //refuel the spaceship
                printf("\nRefueling the spaceship...\n");
                break;
            case 5:
                printf("\nQuitting the game...\n");
                exit(0); //quit the game
            default:
                printf("\nInvalid choice!\n");
                break;
        }
        
        if(distance <= 0) {
            printf("\nCongratulations! You have reached the planet.\n");
            printf("Enter the name of the planet: ");
            scanf("%s", planetName);
            printf("The planet '%s' will be added to your logbook.\n", planetName);
        }
        else if(fuel <= 0) {
            printf("\nYou have run out of fuel and cannot continue traveling.\n");
            printf("Game Over!\n");
            exit(0); //quit the game
        }
        else {
            printf("\nYou have traveled %d kilometers and have %d units of fuel remaining.\n", (500000 - distance), fuel);
        }
    }
    
    return 0;
}