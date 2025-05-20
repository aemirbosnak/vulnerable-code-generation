//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearScreen() {
    system("clear || cls"); // clear screen for different OS
}

void delay(int seconds) {
    int milliSeconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milliSeconds);
}

void displayIntro() {
    clearScreen();
    printf("\n\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*             PROCEDURAL SPACE ADVENTURE         *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*    WELCOME TO THE POST-APOCALYPTIC GALAXY      *\n");
    printf("*    YOU ARE THE LAST HOPE OF THE UNIVERSE!      *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");
    printf("Press ENTER to continue...");
    getchar();
}

void displayMenu() {
    clearScreen();
    printf("\n\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*                     MENU                      *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*       1. Travel to another planet             *\n");
    printf("*       2. Repair the spaceship                 *\n");
    printf("*       3. Upgrade weapons                      *\n");
    printf("*       4. Check inventory                      *\n");
    printf("*       5. Exit game                            *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");
}

void travelPlanet() {
    clearScreen();
    printf("\n\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*              TRAVEL TO ANOTHER PLANET          *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");

    // randomly select planet
    srand(time(NULL));
    int planetNumber = (rand() % 7) + 1;
    char planetName[20];
    char planetDesc[200];
    switch (planetNumber) {
        case 1:
            strcpy(planetName, "Zograh");
            strcpy(planetDesc, "A radioactive planet with high levels of toxicity.");
            break;
        case 2:
            strcpy(planetName, "Xormia");
            strcpy(planetDesc, "A rocky terrain with extreme weather conditions.");
            break;
        case 3:
            strcpy(planetName, "Grytha");
            strcpy(planetDesc, "A mysterious planet with ancient ruins and artifacts.");
            break;
        case 4:
            strcpy(planetName, "Krynn");
            strcpy(planetDesc, "A gas giant with floating cities and alien creatures.");
            break;
        case 5:
            strcpy(planetName, "Vespa");
            strcpy(planetDesc, "A desert planet with valuable resources and dangerous nomads.");
            break;
        case 6:
            strcpy(planetName, "Lumin");
            strcpy(planetDesc, "A jungle planet with lush vegetation and hostile predators.");
            break;
        case 7:
            strcpy(planetName, "Nebula");
            strcpy(planetDesc, "A planet surrounded by a colorful nebula with unique properties.");
            break;
    }
    printf("You have arrived at planet %s!\n\n", planetName);
    printf("Description: %s\n\n", planetDesc);
    
    delay(2);
    printf("Do you want to explore %s?\n", planetName);
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);

    // explore planet or not
    if (choice == 1) {
        clearScreen();
        printf("You are now exploring planet %s...\n\n", planetName);
        delay(2);
        printf("You discovered an ancient alien artifact!\n");
        printf("The artifact looks like a weapon of some sort.\n");
        printf("Do you want to take it?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou took the alien artifact!\n");
        } else {
            printf("\nYou left the artifact and continued exploring.\n");
        }
        delay(2);
        printf("\nWhile exploring, you encounter hostile alien creatures!\n");
        printf("You have to use your weapons to defend yourself.\n");
        delay(2);
        int health = 100;
        int weapon = 1; // 1 is basic weapon
        while (health > 0) {
            clearScreen();
            printf("Health: %d\n\n", health);
            printf("1. Basic weapon\n");
            printf("2. Upgrade weapon\n");
            scanf("%d", &choice);
            if (choice == 2) {
                printf("\nYou need to upgrade your spaceship's weapon system first!\n");
                delay(2);
                break;
            } else {
                srand(time(NULL));
                int damage = (rand() % 10) + 1; // random damage
                health -= damage;
                printf("\nYou dealt %d damage to the alien creature!\n", damage);
                printf("The alien creature retaliated and dealt %d damage to you!\n", damage);
                delay(2);
            }
        }
        if (health <= 0) {
            printf("\nYou defeated the hostile alien creature!\n");
            printf("Congratulations! You have successfully explored planet %s!\n", planetName);
        } else {
            printf("\nThe alien creature defeated you...\n");
            printf("GAME OVER!\n");
        }
    } else {
        printf("You decided to leave planet %s and continue your space adventure.\n", planetName);
        delay(2);
    }
}

void repairShip() {
    clearScreen();
    printf("\n\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*                   REPAIR SHIP                 *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");

    int repairCost = 50; // arbitrary cost
    printf("Your spaceship needs repairs.\n");
    printf("The cost to repair is %d space credits.\n", repairCost);
    printf("You currently have 100 space credits.\n");
    printf("Do you want to proceed with the repair?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        if (100 >= repairCost) {
            printf("\nYou paid %d space credits for the repair.\n", repairCost);
            printf("Your spaceship has been repaired.\n");
            delay(2);
        } else {
            printf("\nYou don't have enough space credits to pay for the repair.\n");
            printf("You need to travel to another planet to find more resources.\n");
            delay(2);
        }
    } else {
        printf("\nYou decided to skip the repair and continue your space adventure.\n");
        delay(2);
    }
}

void upgradeWeapon() {
    clearScreen();
    printf("\n\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*                UPGRADE WEAPON                 *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");

    int upgradeCost = 100; // arbitrary cost
    printf("Your spaceship's weapons are outdated.\n");
    printf("The cost to upgrade is %d space credits.\n", upgradeCost);
    printf("You currently have 100 space credits.\n");
    printf("Do you want to proceed with the upgrade?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        if (100 >= upgradeCost) {
            printf("\nYou paid %d space credits for the upgrade.\n", upgradeCost);
            printf("Your spaceship's weapons have been upgraded!\n");
            delay(2);
        } else {
            printf("\nYou don't have enough space credits to pay for the upgrade.\n");
            printf("You need to travel to another planet to find more resources.\n");
            delay(2);
        }
    } else {
        printf("\nYou decided to skip the upgrade and continue your space adventure.\n");
        delay(2);
    }
}

void checkInventory() {
    clearScreen();
    printf("\n\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*                CHECK INVENTORY                *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");

    printf("You currently have the following items:\n");
    printf("- Basic weapon\n");
    printf("- Alien artifact (if you picked it up)\n");
    printf("\nPress ENTER to continue...");
    getchar();
}

int main() {
    displayIntro();
    int userChoice;
    do {
        displayMenu();
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                travelPlanet();
                break;
            case 2:
                repairShip();
                break;
            case 3:
                upgradeWeapon();
                break;
            case 4:
                checkInventory();
                break;
            case 5:
                printf("\nThank you for playing PROCEDURAL SPACE ADVENTURE!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                delay(2);
                break;
        }
    } while (userChoice != 5);
    return 0;
}