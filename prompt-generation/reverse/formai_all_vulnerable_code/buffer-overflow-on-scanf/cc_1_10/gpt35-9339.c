//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random numbers for events
int random_event() {
    int num = rand() % 10 + 1;
    if (num % 2 == 0) {
        printf("You encounter a group of scavengers.\n");
    } else if (num % 3 == 0) {
        printf("You stumble upon a cache of supplies.\n");
    } else {
        printf("Nothing interesting happens.\n");
    }
    return num;
}

int main() {
    srand(time(0));
    int fuel = 1000;            //Starting fuel level
    int distance = 0;           //Starting distance
    char choice;                //Player's choice
    
    printf("Welcome to the Space Adventure!\n");
    printf("You are a lone traveler aboard your spaceship after the apocalypse.\n");
    printf("Your mission is to reach the planet Earth safely.\n");
    printf("You have 1000 gallons of fuel left.\n");
    
    while (distance < 100) {    //Game loop
        printf("\nHow would you like to proceed?\n");
        printf("A. Travel normally\n");
        printf("B. Take a detour\n");
        printf("C. Scavenge for supplies\n");
        scanf("%c", &choice);
        
        switch(choice) {
            case 'A':
            case 'a':
                printf("You travel normally for a distance of 10,000 kilometers.\n");
                distance += 10000;
                fuel -= 200;
                break;
                
            case 'B':
            case 'b':
                printf("You take a detour through an asteroid field.\n");
                distance += 5000;
                fuel -= 100;
                if (random_event() % 2 == 0) {
                    printf("You successfully navigate through the asteroids.\n");
                } else {
                    printf("You get hit by an asteroid and lose 200 gallons of fuel.\n");
                    fuel -= 200;
                }
                break;
                
            case 'C':
            case 'c':
                printf("You scavenge for supplies and find a medkit and some food.\n");
                printf("Your health has been restored, and your hunger has been satisfied.\n");
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
        
        if (fuel <= 0) {    //Lose condition
            printf("You have run out of fuel and are stranded in space. Game over.\n");
            break;
        } else if (distance >= 100) {   //Win condition
            printf("Congratulations! You have made it to Earth safely.\n");
            break;
        }
        
        printf("\nYou have traveled %d kilometers so far.\n", distance);
        printf("You have %d gallons of fuel remaining.\n", fuel);
    }
    
    printf("\nThank you for playing the Space Adventure!\n");
    
    return 0;
}