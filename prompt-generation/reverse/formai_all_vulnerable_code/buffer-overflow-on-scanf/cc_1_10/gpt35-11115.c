//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Game constants
#define MAX_PLANETS 10
#define MAX_RESOURCES 3
#define MAX_ENEMIES 5
#define MAX_PLAYER_NAME 20
#define MAX_ENEMY_NAME 15

// Function prototypes
void displayWelcomeScreen();
void displayMainMenu();
void generatePlanets();
void displayPlanets();
void displayPlanetDetails(int planetNum);
void generateEnemies();
void displayEnemies();
void displayEnemyDetails(int enemyNum);
void travelToPlanet();
void shop();
void fightEnemy();
void displayPlayerStats();
void gameOver();

// Global variables
int currentPlanet = 0;
int enemiesDefeated = 0;
int playerHealth = 100;
int playerCredits = 100;
char playerName[MAX_PLAYER_NAME];
char resources[MAX_RESOURCES][15] = {"Fuel", "Food", "Water"};
char enemyNames[MAX_ENEMIES][MAX_ENEMY_NAME] = {"ExoGuardian", "Spaceling", "Toxic Spore", "Orbital Sentinel", "Galactic Spectre"};

// Planet structure definition
struct Planet {
    char planetName[15];
    int resourcePrices[MAX_RESOURCES];
};

// Enemy structure definition
struct Enemy {
    char enemyName[MAX_ENEMY_NAME];
    int enemyHealth;
    int enemyDamage;
};

struct Planet planets[MAX_PLANETS];
struct Enemy enemies[MAX_ENEMIES];

int main() {
    srand(time(NULL)); // Seed the random number generator
    displayWelcomeScreen();
    printf("Please enter your name: ");
    scanf("%s", playerName);
    generatePlanets();
    generateEnemies();
    while(1) {
        displayMainMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayPlanets();
                break;
            case 2:
                travelToPlanet();
                break;
            case 3:
                shop();
                break;
            case 4:
                fightEnemy();
                break;
            case 5:
                displayPlayerStats();
                break;
            case 6:
                gameOver();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Displays the welcome screen
void displayWelcomeScreen() {
    printf("********************************************\n");
    printf("           Procedural Space Adventure         \n");
    printf("********************************************\n");
    printf("\n");
}

// Displays the main menu
void displayMainMenu() {
    printf("\n");
    printf("********************************************\n");
    printf("                    Main Menu                 \n");
    printf("********************************************\n");
    printf("1. View Planets\n");
    printf("2. Travel to Planet\n");
    printf("3. Shop\n");
    printf("4. Fight Enemy\n");
    printf("5. View Player Stats\n");
    printf("6. Quit Game\n");
    printf("********************************************\n");
}

// Generates the planets
void generatePlanets() {
    for(int i = 0; i < MAX_PLANETS; i++) {
        sprintf(planets[i].planetName, "Planet %d", i + 1);
        for(int j = 0; j < MAX_RESOURCES; j++) {
            int price = rand() % 11 + 5;
            planets[i].resourcePrices[j] = price;
        }
    }
}

// Displays the planet list
void displayPlanets() {
    printf("\n");
    printf("********************************************\n");
    printf("                  Planet List                \n");
    printf("********************************************\n");
    for(int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s\n", i + 1, planets[i].planetName);
    }
    printf("********************************************\n");
}

// Displays the planet details
void displayPlanetDetails(int planetNum) {
    printf("\n");
    printf("********************************************\n");
    printf("               %s Planet Details             \n", planets[planetNum].planetName);
    printf("********************************************\n");
    for(int i = 0; i < MAX_RESOURCES; i++) {
        printf("%s: %d credits\n", resources[i], planets[planetNum].resourcePrices[i]);
    }
    printf("********************************************\n");
}

// Generates the enemies
void generateEnemies() {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        sprintf(enemies[i].enemyName, "%s Class Enemy", enemyNames[i]);
        enemies[i].enemyHealth = rand() % 51 + 50;
        enemies[i].enemyDamage = rand() % 26 + 25;
    }
}

// Displays the enemy list
void displayEnemies() {
    printf("\n");
    printf("********************************************\n");
    printf("                  Enemy List                 \n");
    printf("********************************************\n");
    for(int i = 0; i < MAX_ENEMIES; i++) {
        printf("%d. %s\n", i + 1, enemies[i].enemyName);
    }
    printf("********************************************\n");
}

// Displays the enemy details
void displayEnemyDetails(int enemyNum) {
    printf("\n");
    printf("********************************************\n");
    printf("               %s Details             \n", enemies[enemyNum].enemyName);
    printf("********************************************\n");
    printf("Health: %d\n", enemies[enemyNum].enemyHealth);
    printf("Damage: %d\n", enemies[enemyNum].enemyDamage);
    printf("********************************************\n");
}

// Allows the player to travel to a planet
void travelToPlanet() {
    int choice;
    printf("\n");
    printf("********************************************\n");
    printf("                  Travel Menu                \n");
    printf("********************************************\n");
    printf("Current Planet: %s\n", planets[currentPlanet].planetName);
    displayPlanets();
    printf("Enter the number of the planet you want to travel to: ");
    scanf("%d", &choice);
    if(choice > 0 && choice <= MAX_PLANETS && choice != currentPlanet + 1) {
        int distance = abs(currentPlanet - (choice - 1));
        int travelCost = (distance + 1) * 10;
        if(playerCredits >= travelCost) {
            playerCredits -= travelCost;
            currentPlanet = choice - 1;
            printf("You have successfully travelled to %s planet.\n", planets[currentPlanet].planetName);
            displayPlanetDetails(currentPlanet);
        } else {
            printf("You do not have enough credits to make this trip.\n");
        }
    } else if(choice == currentPlanet + 1) {
        printf("You are already on this planet.\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Allows the player to buy or sell resources
void shop() {
    int choice;
    printf("\n");
    printf("********************************************\n");
    printf("                     Shop                    \n");
    printf("********************************************\n");
    displayPlanetDetails(currentPlanet);
    printf("Credits: %d\n", playerCredits);
    printf("1. Buy Resources\n");
    printf("2. Sell Resources\n");
    printf("3. Exit Shop\n");
    printf("********************************************\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("\n");
        printf("********************************************\n");
        printf("                   Buy Menu                  \n");
        printf("********************************************\n");
        for(int i = 0; i < MAX_RESOURCES; i++) {
            printf("%d. %s: %d credits\n", i + 1, resources[i], planets[currentPlanet].resourcePrices[i]);
        }
        printf("********************************************\n");
        printf("Enter the number of the resource you want to buy: ");
        int resourceChoice;
        scanf("%d", &resourceChoice);
        if(resourceChoice > 0 && resourceChoice <= MAX_RESOURCES) {
            printf("Enter the quantity you want to buy: ");
            int quantity;
            scanf("%d", &quantity);
            int totalPrice = quantity * planets[currentPlanet].resourcePrices[resourceChoice - 1];
            if(totalPrice > playerCredits) {
                printf("You do not have enough credits to make this purchase.\n");
            } else {
                playerCredits -= totalPrice;
                printf("You have successfully purchased %d units of %s.\n", quantity, resources[resourceChoice - 1]);
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } else if(choice == 2) {
        printf("\n");
        printf("********************************************\n");
        printf("                   Sell Menu                 \n");
        printf("********************************************\n");
        for(int i = 0; i < MAX_RESOURCES; i++) {
            printf("%d. %s: %d credits\n", i + 1, resources[i], planets[currentPlanet].resourcePrices[i]);
        }
        printf("********************************************\n");
        printf("Enter the number of the resource you want to sell: ");
        int resourceChoice;
        scanf("%d", &resourceChoice);
        if(resourceChoice > 0 && resourceChoice <= MAX_RESOURCES) {
            printf("Enter the quantity you want to sell: ");
            int quantity;
            scanf("%d", &quantity);
            int totalPrice = quantity * planets[currentPlanet].resourcePrices[resourceChoice - 1];
            playerCredits += totalPrice;
            printf("You have successfully sold %d units of %s.\n", quantity, resources[resourceChoice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } else if(choice == 3) {
        printf("Exiting shop.\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Allows the player to fight an enemy
void fightEnemy() {
    int choice;
    printf("\n");
    printf("********************************************\n");
    printf("               Choose an enemy                \n");
    printf("********************************************\n");
    displayEnemies();
    printf("Enter the number of the enemy you want to fight: ");
    scanf("%d", &choice);
    if(choice > 0 && choice <= MAX_ENEMIES) {
        displayEnemyDetails(choice - 1);
        printf("Are you ready to fight? (1. Yes 2. No): ");
        int ready;
        scanf("%d", &ready);
        if(ready == 1) {
            struct Enemy currentEnemy = enemies[choice - 1];
            int totalEnemyDamage = 0;
            int totalPlayerDamage = 0;
            while(playerHealth > 0 && currentEnemy.enemyHealth > 0) {
                int playerDamage = rand() % 11 + 5;
                totalPlayerDamage += playerDamage;
                printf("You attacked the enemy and did %d damage. Enemy health is now %d.\n", playerDamage, currentEnemy.enemyHealth - playerDamage);
                currentEnemy.enemyHealth -= playerDamage;
                if(currentEnemy.enemyHealth > 0) {
                    int enemyDamage = rand() % currentEnemy.enemyDamage + 1;
                    totalEnemyDamage += enemyDamage;
                    printf("The enemy attacked you and did %d damage. Your health is now %d.\n", enemyDamage, playerHealth - enemyDamage);
                    playerHealth -= enemyDamage;
                }
            }
            if(playerHealth <= 0) {
                printf("You lost the fight and have been transported back to your base planet.\n");
                currentPlanet = 0;
                playerCredits = 100;
                playerHealth = 100;
            } else {
                int lootCredits = rand() % 51 + 50;
                playerCredits += lootCredits;
                printf("Congratulations! You have won the fight and earned %d credits.\n", lootCredits);
                enemiesDefeated++;
            }
        } else if(ready == 2) {
            printf("You chickened out of the fight.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Displays the player stats
void displayPlayerStats() {
    printf("\n");
    printf("********************************************\n");
    printf("                  Player Stats               \n");
    printf("********************************************\n");
    printf("Name: %s\n", playerName);
    printf("Current Planet: %s\n", planets[currentPlanet].planetName);
    printf("Credits: %d\n", playerCredits);
    printf("Health: %d\n", playerHealth);
    printf("Enemies Defeated: %d\n", enemiesDefeated);
    printf("********************************************\n");
}

// Ends the game
void gameOver() {
    printf("Thank you for playing Procedural Space Adventure!\n");
    exit(EXIT_SUCCESS);
}