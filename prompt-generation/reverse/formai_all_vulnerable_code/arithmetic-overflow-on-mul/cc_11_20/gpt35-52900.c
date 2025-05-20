//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to simulate a random event during space travel
void randomEvent(){
    int eventNum = rand() % 3;
    printf("Random Event Occured:");
    switch(eventNum){
        case 0:
            printf(" Ship malfunction!\n");
            break;
        case 1:
            printf(" Alien encounter!\n");
            break;
        case 2:
            printf(" Asteroid field ahead!\n");
            break;
    }
}

int main(){
    srand(time(NULL)); // seeding rand with current time
    printf("Welcome to the Procedural Space Adventure!\n\n");

    // initializing player stats
    int fuel = 100;
    int health = 100;
    int credits = 0;
    int distance = 0;

    // game loop
    while(health > 0 && fuel > 0 && distance < 5000){
        printf("Current Stats: Fuel: %d Health: %d Credits: %d Distance Traveled: %d\n", fuel, health, credits, distance);
        printf("What would you like to do?\n");
        printf("1. Travel to the Next Planet\n");
        printf("2. Buy fuel\n");
        printf("3. Buy health supplies\n");
        printf("4. Buy upgrades for ship\n");
        printf("5. Quit Game\n\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Traveling to the next planet...\n");
                int eventChance = rand() % 6; // 1 in 6 chance of random event
                if(eventChance == 0){
                    randomEvent();
                }
                int distanceTraveled = rand() % 1001 + 500; // traveling between 500 and 1500 light years
                distance += distanceTraveled;
                fuel -= distanceTraveled / 10;
                health -= distanceTraveled / 50;
                credits += rand() % 51 + 50; // earning between 50 and 100 credits
                break;
            case 2:
                printf("Buying fuel...\n");
                printf("Fuel costs 5 credits per unit. How much fuel would you like to buy?\n");
                int fuelToBuy;
                scanf("%d",&fuelToBuy);
                if(credits >= fuelToBuy * 5 && fuelToBuy <= 50){
                    fuel += fuelToBuy;
                    credits -= fuelToBuy * 5;
                }
                else{
                    printf("Invalid amount or not enough credits!\n");
                }
                break;
            case 3:
                printf("Buying health supplies...\n");
                printf("Health supplies cost 10 credits each. How many supplies would you like to buy?\n");
                int suppliesToBuy;
                scanf("%d",&suppliesToBuy);
                if(credits >= suppliesToBuy * 10 && suppliesToBuy <= 20){
                    health += suppliesToBuy * 10;
                    credits -= suppliesToBuy * 10;
                }
                else{
                    printf("Invalid amount or not enough credits!\n");
                }
                break;
            case 4:
                printf("Buying upgrades for ship...\n");
                printf("Upgrades cost 100 credits each. What upgrade would you like to buy?\n");
                printf("1. Improved Engines (+10 fuel efficiency)\n");
                printf("2. Reinforced Hull (+10 max health)\n");
                printf("3. Advanced Sensors (+10% chance to avoid random events)\n");

                int upgradeChoice;
                scanf("%d",&upgradeChoice);
                switch(upgradeChoice){
                    case 1:
                        if(credits >= 100){
                            fuel += 10;
                            credits -= 100;
                            printf("Improved Engines installed!\n");
                        }
                        else{
                            printf("Not enough credits!\n");
                        }
                        break;
                    case 2:
                        if(credits >= 100){
                            health += 10;
                            credits -= 100;
                            printf("Reinforced Hull installed!\n");
                        }
                        else{
                            printf("Not enough credits!\n");
                        }
                        break;
                    case 3:
                        if(credits >= 100){
                            credits -= 100;
                            printf("Advanced Sensors installed!\n");
                        }
                        else{
                            printf("Not enough credits!\n");
                        }
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    // game over
    if(health <= 0){
        printf("Your ship has been destroyed! Game Over.\n");
    }
    else if(fuel <= 0){
        printf("You have run out of fuel and are stranded in space! Game Over.\n");
    }
    else if(distance >= 5000){
        printf("Congratulations, you have made it to the end of the galaxy!\n");
    }

    printf("Final Stats: Fuel: %d Health: %d Credits: %d Distance Traveled: %d\n", fuel, health, credits, distance);

    return 0;
}