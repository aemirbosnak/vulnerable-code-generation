//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntroduction();
void initializeGame(char playerShip[], int* playerCredits, int* playerFuel, int* playerHealth);
int randomNumber(int min, int max);
void buyFuel(int* playerCredits, int* playerFuel);
void buyHealth(int* playerCredits, int* playerHealth);
void travel(char playerShip[], int* playerCredits, int* playerFuel, int* playerHealth);
void encounter(char playerShip[], int* playerCredits, int* playerFuel, int* playerHealth);

int main()
{
    char playerShip[20];
    int playerCredits = 1000;
    int playerFuel = 50;
    int playerHealth = 100;
    
    printIntroduction();
    initializeGame(playerShip, &playerCredits, &playerFuel, &playerHealth);
    
    while (playerHealth > 0) {
        travel(playerShip, &playerCredits, &playerFuel, &playerHealth);
        if (playerHealth <= 0) {
            printf("Game Over. Your ship has been destroyed.\n");
            break;
        }
        encounter(playerShip, &playerCredits, &playerFuel, &playerHealth);
        if (playerHealth <= 0) {
            printf("Game Over. Your ship has been destroyed.\n");
            break;
        }
    }
    
    printf("Thanks for playing!");
    return 0;
}

void printIntroduction()
{
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a small spaceship, traveling through the galaxy in search of riches and adventure.\n");
    printf("But beware! There are dangers lurking in the vastness of space...\n\n");
}

void initializeGame(char playerShip[], int* playerCredits, int* playerFuel, int* playerHealth)
{
    printf("Before you begin your journey, you must name your ship:\n");
    scanf("%s", playerShip);
    printf("\nYou start with %d credits, %d units of fuel, and %d percent health.\n\n", *playerCredits, *playerFuel, *playerHealth);
}

int randomNumber(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

void buyFuel(int* playerCredits, int* playerFuel)
{
    int price = randomNumber(10, 20);
    printf("Fuel costs %d credits per unit.\n", price);
    printf("How much fuel would you like to purchase?\n");
    int fuelAmount = 0;
    scanf("%d", &fuelAmount);
    int cost = fuelAmount * price;
    if (*playerCredits >= cost) {
        *playerCredits -= cost;
        *playerFuel += fuelAmount;
        printf("You now have %d units of fuel and %d credits remaining.\n", *playerFuel, *playerCredits);
    }
    else {
        printf("Sorry, you do not have enough credits to purchase that much fuel.\n");
    }
}

void buyHealth(int* playerCredits, int* playerHealth)
{
    int price = randomNumber(25, 50);
    printf("Health costs %d credits per percent.\n", price);
    printf("How much health would you like to purchase?\n");
    int healthAmount = 0;
    scanf("%d", &healthAmount);
    int cost = healthAmount * price;
    if (*playerCredits >= cost) {
        *playerCredits -= cost;
        *playerHealth += healthAmount;
        printf("You now have %d percent health and %d credits remaining.\n", *playerHealth, *playerCredits);
    }
    else {
        printf("Sorry, you do not have enough credits to purchase that much health.\n");
    }
}

void travel(char playerShip[], int* playerCredits, int* playerFuel, int* playerHealth)
{
    printf("You are currently piloting the %s.\n", playerShip);
    printf("You have %d units of fuel and %d percent health.\n", *playerFuel, *playerHealth);
    printf("What would you like to do?\n");
    printf("1. Buy fuel\n");
    printf("2. Buy health\n");
    printf("3. Travel to a new planet\n");
    int choice = 0;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            buyFuel(playerCredits, playerFuel);
            break;
        case 2:
            buyHealth(playerCredits, playerHealth);
            break;
        case 3:
            printf("You set a course for a new planet.\n");
            *playerFuel -= randomNumber(1, 5);
            if (*playerFuel <= 0) {
                printf("You ran out of fuel and your ship drifted into deep space.\n");
                *playerHealth = 0;
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void encounter(char playerShip[], int* playerCredits, int* playerFuel, int* playerHealth)
{
    int encounterType = randomNumber(1, 3);
    switch(encounterType) {
        case 1:
            printf("You encounter a friendly trader.\n");
            printf("They offer to sell you some valuable resources.\n");
            printf("Would you like to buy some?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int traderChoice = 0;
            scanf("%d", &traderChoice);
            if (traderChoice == 1) {
                int resourcePrice = randomNumber(50, 100);
                printf("The trader offers you some resources for %d credits.\n", resourcePrice);
                printf("How many would you like to buy?\n");
                int resourceAmount = 0;
                scanf("%d", &resourceAmount);
                int resourceCost = resourceAmount * resourcePrice;
                if (*playerCredits >= resourceCost) {
                    *playerCredits -= resourceCost;
                    printf("You now have %d credits and %d units of resources.\n", *playerCredits, resourceAmount);
                }
                else {
                    printf("Sorry, you do not have enough credits to make that purchase.\n");
                }
            }
            break;
        case 2:
            printf("You encounter a hostile pirate ship!\n");
            printf("They demand that you surrender your credits and resources.\n");
            printf("What do you do?\n");
            printf("1. Fight\n");
            printf("2. Surrender\n");
            int pirateChoice = 0;
            scanf("%d", &pirateChoice);
            if (pirateChoice == 1) {
                int pirateHealth = randomNumber(50, 100);
                printf("You engage in a battle with the pirate ship!\n");
                printf("The pirate ship has %d percent health.\n", pirateHealth);
                int pirateAttack = randomNumber(10, 20);
                int playerAttack = randomNumber(10, 20);
                while (pirateHealth > 0 && *playerHealth > 0) {
                    pirateHealth -= playerAttack;
                    printf("You attack the pirate ship for %d damage. It now has %d percent health.\n", playerAttack, pirateHealth);
                    if (pirateHealth <= 0) {
                        printf("You have defeated the pirate ship!\n");
                        int pirateCredits = randomNumber(200, 500);
                        printf("You gain %d credits and some valuable resources from the wreckage.\n", pirateCredits);
                        *playerCredits += pirateCredits;
                        break;
                    }
                    *playerHealth -= pirateAttack;
                    printf("The pirate ship attacks you for %d damage. You now have %d percent health.\n", pirateAttack, *playerHealth);
                }
                if (*playerHealth <= 0) {
                    printf("Your ship has been destroyed in the battle.\n");
                }
            }
            else {
                printf("You surrender your credits and resources to the pirate ship.\n");
                int pirateCredits = randomNumber(250, 750);
                printf("You lose %d credits in the transaction.\n", pirateCredits);
                *playerCredits -= pirateCredits;
            }
            break;
        case 3:
            printf("You encounter a strange anomaly in space...\n");
            printf("What do you do?\n");
            printf("1. Investigate\n");
            printf("2. Avoid\n");
            int anomalyChoice = 0;
            scanf("%d", &anomalyChoice);
            if (anomalyChoice == 1) {
                printf("You send a team to investigate the anomaly...\n");
                int anomalyResult = randomNumber(1, 2);
                if (anomalyResult == 1) {
                    printf("Your team returns with some valuable resources!\n");
                    int resourceAmount = randomNumber(1, 10);
                    printf("You gain %d units of valuable resources.\n", resourceAmount);
                }
                else {
                    printf("Your team is lost in the anomaly.\n");
                    *playerHealth = 0;
                }
            }
            break;
        default:
            printf("No encounter...\n");
            break;
    }
}