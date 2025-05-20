//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h> // includes library for standard input and output functions.
#include <stdlib.h> // library for random function.

void travelToPlanet(int planet); // prototype for the planet travel function.

int main()
{
    int currentPlanet = 1; // start off on the first planet.
    int continueTravel = 1; // variable to control whether or not to continue.
    
    printf("Welcome to the Space Adventure!\n\n"); // prints the welcome message.
    
    while(continueTravel) // loop to travel to different planets.
    {
        printf("You are currently on Planet %d\n\n", currentPlanet); // prints current planet.
        printf("Where would you like to travel next?\n");
        printf("1. Planet Mars\n");
        printf("2. Planet Jupiter\n");
        printf("3. Planet Saturn\n");
        printf("4. Return to Earth\n");
        printf("Enter the number of your choice: ");
        
        int choice; // variable to store user's choice.
        scanf("%d", &choice); // scans choice from user.
        
        switch(choice) // switch case to handle user's choice.
        {
            case 1:
                travelToPlanet(2); // travel to mars.
                currentPlanet = 2; // update the current planet variable.
                break;
            case 2:
                travelToPlanet(3); // travel to jupiter.
                currentPlanet = 3; // update the current planet variable.
                break;
            case 3:
                travelToPlanet(4); // travel to saturn.
                currentPlanet = 4; // update the current planet variable.
                break;
            case 4:
                printf("\nYou have returned to Earth safely!\n\n"); // prints message.
                continueTravel = 0; // set continue travel to false to exit loop.
                break;
            default:
                printf("\nInvalid choice, please try again.\n\n"); // prints message.
                break;
        }
    }
    
    printf("Thank you for traveling with us!"); // prints final message.
    
    return 0; // ends the program.
}

void travelToPlanet(int planet) // function definition for planet travel.
{
    printf("\nTraveling to planet...");
    for(int i = 0; i < 5; i++)
    {
        printf("."); // prints dots to simulate travel.
        sleep(1); // waits one second before proceeding.
    }
    printf("\n\nWelcome to Planet %d!\n\n", planet); // prints welcome message with planet number.
}