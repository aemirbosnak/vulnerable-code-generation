//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random number between range
int getRandomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){

    srand(time(NULL));
    int health = 100; //initial health of the player
    int credits = 1000; //initial credits of the player
    int fuel = 500; //initial fuel of the player
    int planet = 1; //current planet where player is

    printf("Welcome to the Space Adventure Game!\n");
    printf("You are currently on Planet %d with %d Health, %d Credits and %d Fuel.\n", planet, health, credits, fuel);

    while(health > 0 && credits > 0 && fuel > 0 && planet <= 5){

        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Explore planet and earn credits\n");
        printf("2. Buy fuel\n");
        printf("3. Travel to another planet\n");
        printf("4. Quit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            //Exploring planet
            case 1:
                printf("\nYou are exploring Planet %d...\n", planet);
                int randomCredits = getRandomNumber(50, 150);
                printf("You found %d credits on Planet %d!\n", randomCredits, planet);
                credits += randomCredits;
                break;

            //Buying fuel
            case 2:
                printf("\nYou want to buy fuel...\n");
                int amountFuel;
                printf("Enter the amount of fuel you want to buy: ");
                scanf("%d", &amountFuel);
                int costFuel = amountFuel * 10;
                if(costFuel > credits){
                    printf("You do not have enough credits!\n");
                }
                else{
                    credits -= costFuel;
                    fuel += amountFuel;
                    printf("You bought %d fuel for %d credits!\n", amountFuel, costFuel);
                }
                break;

            //Traveling to another planet
            case 3:
                printf("\nYou want to travel to another planet...\n");
                int destinationPlanet;
                printf("Which planet do you want to travel to? (2, 3, 4, 5): ");
                scanf("%d", &destinationPlanet);
                int costTravel = 100 * destinationPlanet;
                if(costTravel > credits){
                    printf("You do not have enough credits!\n");
                }
                else if(destinationPlanet <= planet){
                    printf("You cannot travel to a smaller or same planet!\n");
                }
                else{
                    credits -= costTravel;
                    fuel -= (destinationPlanet - planet) * 50;
                    planet = destinationPlanet;
                    printf("You have reached Planet %d!\n", planet);
                }
                break;

            //Quitting the game
            case 4:
                printf("Quitting the game...\n");
                exit(0);

            //Invalid choice
            default:
                printf("\nInvalid Choice!\n");
                break;
        }

        //Random event - Alien attack
        int chanceOfAttack = getRandomNumber(1, 5);
        if(chanceOfAttack == 1){
            printf("\nWARNING: Alien Attack!\n");
            int damage = getRandomNumber(10, 30);
            health -= damage;
            printf("You have been attacked by aliens and lost %d health!\n", damage);
        }

        //Status update
        printf("\nCurrent Status: Planet %d with %d Health, %d Credits and %d Fuel.\n", planet, health, credits, fuel);

        //Checking if player is out of health, credits or fuel
        if(health <= 0){
            printf("\nGAME OVER: You ran out of health!\n");
            exit(0);
        }
        else if(credits <= 0){
            printf("\nGAME OVER: You ran out of credits!\n");
            exit(0);
        }
        else if(fuel <= 0){
            printf("\nGAME OVER: You ran out of fuel!\n");
            exit(0);
        }
        else if(planet == 5 && credits >= 5000){
            printf("\nCongratulations! You have completed the Space Adventure Game!\n");
            exit(0);
        }
    }

    return 0;
}