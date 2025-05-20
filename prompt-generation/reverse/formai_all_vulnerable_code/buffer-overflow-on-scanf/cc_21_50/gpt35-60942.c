//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //seed random generator

    //initialize variables
    int spaceshipHealth = 100;
    int alienHealth = 50;
    int fuel = 50;
    int asteroids = 0;
    int aliensKilled = 0;
    int gameOn = 1;

    //begin game loop
    while (gameOn == 1){

        //print spaceship status
        printf("Spaceship Health: %d\nFuel: %d\nAsteroids Collected: %d\nAliens Killed: %d\n", spaceshipHealth, fuel, asteroids, aliensKilled);

        //random event generator
        int randEvent = rand() % 4; 
        switch (randEvent){
            //asteroid field 
            case 0: 
                printf("You stumble upon a field of asteroids.\n");
                printf("Do you want to collect them? [1] Yes [0] No: ");
                int collectAsteroids;
                scanf("%d", &collectAsteroids);
                if (collectAsteroids == 1){
                    asteroids += 10;
                    printf("You collect 10 asteroids.\n");
                } else {
                    printf("You choose to leave the asteroids behind.\n");
                }
                break;
            //alien encounter
            case 1:
                printf("You encounter an alien spaceship!\n");
                //alien challenge loop
                while (alienHealth > 0 && spaceshipHealth > 0){
                    printf("Alien Health: %d\nSpaceship Health: %d\n", alienHealth, spaceshipHealth);
                    printf("What do you want to do? [1] Attack [2] Defend [3] Use Fuel: ");
                    int action;
                    scanf("%d", &action);
                    switch (action){
                        //attack
                        case 1:
                            alienHealth -= 20;
                            printf("You attack the alien spaceship and deal 20 damage.\n");
                            break;
                        //defend
                        case 2:
                            spaceshipHealth += 10;
                            printf("You activate shields and increase your spaceship health by 10.\n");
                            break;
                        //use fuel
                        case 3:
                            fuel -= 10;
                            spaceshipHealth -= 10;
                            printf("You use fuel to boost your spaceship and deal 10 damage to the alien spaceship.\n");
                            break;
                        default:
                            printf("Invalid action, try again.\n");
                    }
                    //alien attack
                    if (alienHealth > 0){
                        spaceshipHealth -= 15;
                        printf("The alien spaceship attacks and deals 15 damage.\n");
                    }
                }
                //alien defeated
                if (alienHealth <= 0){
                    printf("Congratulations! You defeated the alien spaceship.\n");
                    aliensKilled++;
                } else {
                    //spaceship destroyed
                    printf("Sorry, your spaceship was destroyed by the alien spaceship.\n");
                    gameOn = 0; //end game
                }
                break;
            //refuel
            case 2:
                printf("You find a planet with a fuel station.\n");
                printf("Do you want to refuel? [1] Yes [0] No: ");
                int refuel;
                scanf("%d", &refuel);
                if (refuel == 1){
                    fuel += 20;
                    printf("You refuel your spaceship with 20 fuel.\n");
                } else {
                    printf("You choose to leave the planet without refueling.\n");
                }
                break;
            //random event
            case 3: 
                printf("You discover something strange in space.\n");
                printf("Do you investigate? [1] Yes [0] No: ");
                int investigate;
                scanf("%d", &investigate);
                if (investigate == 1){
                    printf("You investigate the strange object.\n");
                    int randArtifact = rand() % 3;
                    switch (randArtifact){
                        case 0:
                            printf("You find an ancient artifact that increases your spaceship health by 20.\n");
                            spaceshipHealth += 20;
                            break;
                        case 1:
                            printf("You find an alien relic that increases your attack damage by 10.\n");
                            break;
                        case 2:
                            printf("You find a mysterious crystal that doubles the amount of asteroids you can collect.\n");
                            asteroids *= 2;
                            break;
                    }
                } else {
                    printf("You choose to leave the strange object alone.\n");
                }
                break;
        }
        //fuel consumption and game over check
        if (fuel <= 0){
            printf("You ran out of fuel and your spaceship was stranded in space.\n");
            gameOn = 0; //end game
        } else {
            fuel -= 10;
        }

        //asteroid collection
        if (asteroids > 0){
            printf("You collect 1 asteroid.\n");
            asteroids--;
        }
    }

    //game over message
    printf("Game Over. Thanks for playing!\n");

    return 0;
}