//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

    //creating a procedural space adventure game

    //setting game variables
    int hullHealth = 100;
    int fuelLevel = 50;
    int alienAttackChance = 20;
    int asteroidAttackChance = 10;
    int credits = 500;
    int win = 0;

    //setting player name
    char name[50];
    printf("Welcome to the Space Adventure game!\n");
    printf("Please enter your name: ");
    scanf("%s",name);

    //starting game
    printf("Hello %s. Your adventure starts now!\n",name);

    //giving the player a choice
    printf("Do you want to explore the galaxy or go to the nearest space station?\n");
    printf("1. Explore the galaxy\n");
    printf("2. Go to the space station\n");

    int choice;
    scanf("%d",&choice);

    if(choice == 1){
        //exploring the galaxy
        printf("You are now exploring the vastness of space. Who knows what lies ahead?\n");

        //setting up encounters
        srand(time(NULL));  //creating seed for random function
        int chanceRoll;

        while(hullHealth > 0 && fuelLevel > 0 && win == 0){
            //random chance encounters
            chanceRoll = rand() % 100 + 1;
            if(chanceRoll <= alienAttackChance){
                printf("You encountered hostile aliens!\n");
                hullHealth -= 20;
            }
            if(chanceRoll <= asteroidAttackChance){
                printf("You are under attack by asteroids!\n");
                hullHealth -= 10;
            }
            //fuel consumption
            fuelLevel -= 5;

            //checking health and fuel level
            if(hullHealth <= 0){
                printf("Game Over. Your ship was destroyed.\n");
            }
            else if(fuelLevel <= 0){
                printf("Game Over. You are out of fuel.\n");
            }

            //player wins if they reach 1000 credits
            else if(credits >= 1000){
                printf("Congratulations! You reached 1000 credits! You win!\n");
                win = 1;
            }
        }
    }
    else if(choice == 2){
        //going to the space station
        printf("You have arrived at the space station.\n");

        //adding credits
        credits += 100;

        //refueling
        fuelLevel = 100;

        //repairing ship
        hullHealth = 100;

        //giving player a choice to upgrade ship
        printf("Do you want to purchase ship upgrades?\n");
        printf("1. Upgrade hull plating (+50 credits, +20 hull health)\n");
        printf("2. Upgrade engines (+75 credits, +10 fuel)\n");

        int upgradeChoice;
        scanf("%d",&upgradeChoice);

        if(upgradeChoice == 1){
            //upgrading hull plating
            if(credits >= 50){
                printf("You upgraded your hull plating!\n");
                credits -= 50;
                hullHealth += 20;
            }
            else{
                printf("Sorry, you do not have enough credits to purchase that upgrade.\n");
            }
        }
        else if(upgradeChoice == 2){
            //upgrading engines
            if(credits >= 75){
                printf("You upgraded your engines!\n");
                credits -= 75;
                fuelLevel += 10;
            }
            else{
                printf("Sorry, you do not have enough credits to purchase that upgrade.\n");
            }
        }
        else{
            printf("Invalid choice.\n");
        }
    }
    else{
        printf("Invalid choice. Restart the game and choose 1 or 2.\n");
    }

    return 0;
}