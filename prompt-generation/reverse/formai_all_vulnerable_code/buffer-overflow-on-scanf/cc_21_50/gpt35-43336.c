//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Setting initial variables
    int fuel = 100;
    int oxygen = 100;
    int health = 100;
    int credits = 0;
    int choice;
    char name[20];

    // Introduction
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nHello %s!\n", name);
    printf("You are the captain of the spacecraft Odyssey, and your mission is to explore the galaxy and find new planets to colonize.\n");
    printf("You have a limited amount of resources, including fuel, oxygen, and your own health. Use them wisely or you might not make it back to Earth!\n");
    printf("You also have a credit account for buying supplies and upgrades along the way.\n");
    printf("Good luck and safe travels!\n");

    printf("\nPress any key to continue...");
    getchar();

    // Main game loop
    while (health > 0 && fuel > 0 && oxygen > 0) {
        system("clear");

        // Displaying resource levels
        printf("Fuel: %d\n", fuel);
        printf("Oxygen: %d\n", oxygen);
        printf("Health: %d\n", health);
        printf("Credits: %d\n", credits);

        // Displaying menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Explore a new planet\n");
        printf("2. Buy supplies\n");
        printf("3. Upgrade your spacecraft\n");
        printf("4. Rest and recover\n");
        printf("5. Quit the game\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Exploring a new planet
                printf("\nSearching for a new planet...\n");
                printf("...");
                printf("...");
                printf("...");
                printf("\nA new planet has been located!\n");

                // Randomly generate resource levels for the planet
                int planet_fuel = rand() % 51 + 50;
                int planet_oxygen = rand() % 51 + 50;
                int planet_hostility = rand() % 101;

                printf("\nThis planet has the following resources:\n");
                printf("Fuel: %d\n", planet_fuel);
                printf("Oxygen: %d\n", planet_oxygen);

                // Determine if the planet is hostile or not
                if (planet_hostility >= 50) {
                    printf("Warning: this planet is hostile and presents a significant risk to your health!\n");
                }
                else {
                    printf("This planet is safe to explore.\n");
                }

                // Ask the player if they want to land
                printf("\nDo you want to land on this planet?(y/n) ");
                char planet_choice;
                scanf("%s", &planet_choice);

                if (planet_choice == 'y') {
                    // Deduct resources needed to land
                    fuel -= 30;
                    oxygen -= 20;

                    printf("\nYou have landed on the planet!\n");

                    // Determine if the planet is hostile or not
                    if (planet_hostility >= 50) {
                        printf("You have encountered hostile life forms!\n");
                        printf("...");
                        printf("...");
                        printf("...");
                        printf("\nYou managed to escape with your life, but your health has been significantly reduced!\n");
                        health -= 50;
                    }
                    else {
                        // Add the planet's resources to the player's resources
                        fuel += planet_fuel;
                        oxygen += planet_oxygen;

                        printf("You have successfully collected resources from the planet!\n");
                    }
                }

                break;
            case 2: // Buying supplies
                printf("\nWhat supplies would you like to buy?\n");
                printf("1. Fuel\n");
                printf("2. Oxygen\n");
                printf("\nYour choice: ");
                int supply_choice;
                scanf("%d", &supply_choice);

                switch (supply_choice) {
                    case 1: // Buying fuel
                        printf("\nFuel costs 10 credits per unit.\n");
                        printf("How much fuel would you like to buy?(1-10) ");
                        int fuel_buy_choice;
                        scanf("%d", &fuel_buy_choice);

                        if (fuel_buy_choice <= 0 || fuel_buy_choice > 10) {
                            printf("\nInvalid choice.\n");
                            break;
                        }

                        int fuel_cost = fuel_buy_choice * 10;

                        if (credits >= fuel_cost) {
                            fuel += fuel_buy_choice;
                            credits -= fuel_cost;
                            printf("\nPurchase complete.\n");
                        } else {
                            printf("\nYou do not have enough credits.\n");
                        }

                        break;
                    case 2: // Buying oxygen
                        printf("\nOxygen costs 5 credits per unit.\n");
                        printf("How much oxygen would you like to buy?(1-20) ");
                        int oxygen_buy_choice;
                        scanf("%d", &oxygen_buy_choice);

                        if (oxygen_buy_choice <= 0 || oxygen_buy_choice > 20) {
                            printf("\nInvalid choice.\n");
                            break;
                        }

                        int oxygen_cost = oxygen_buy_choice * 5;

                        if (credits >= oxygen_cost) {
                            oxygen += oxygen_buy_choice;
                            credits -= oxygen_cost;
                            printf("\nPurchase complete.\n");
                        } else {
                            printf("\nYou do not have enough credits.\n");
                        }

                        break;
                    default:
                        printf("\nInvalid choice.\n");
                        break;
                }
                
                break;
            case 3: // Upgrading spacecraft
                printf("\nWhat would you like to upgrade?\n");
                printf("1. Fuel capacity\n");
                printf("2. Oxygen capacity\n");
                printf("\nYour choice: ");
                int upgrade_choice;
                scanf("%d", &upgrade_choice);

                switch (upgrade_choice) {
                    case 1: // Upgrading fuel capacity
                        printf("\nFuel capacity upgrades cost 50 credits per unit increase.\n");
                        printf("How much would you like to upgrade your fuel capacity?(1-10) ");
                        int fuel_upgrade_choice;
                        scanf("%d", &fuel_upgrade_choice);

                        if (fuel_upgrade_choice <= 0 || fuel_upgrade_choice > 10) {
                            printf("\nInvalid choice.\n");
                            break;
                        }

                        int fuel_upgrade_cost = fuel_upgrade_choice * 50;

                        if (credits >= fuel_upgrade_cost) {
                            fuel += fuel_upgrade_choice * 50;
                            credits -= fuel_upgrade_cost;
                            printf("\nUpgrade complete.\n");
                        } else {
                            printf("\nYou do not have enough credits.\n");
                        }

                        break;
                    case 2: // Upgrading oxygen capacity
                        printf("\nOxygen capacity upgrades cost 25 credits per unit increase.\n");
                        printf("How much would you like to upgrade your oxygen capacity?(1-20) ");
                        int oxygen_upgrade_choice;
                        scanf("%d", &oxygen_upgrade_choice);

                        if (oxygen_upgrade_choice <= 0 || oxygen_upgrade_choice > 20) {
                            printf("\nInvalid choice.\n");
                            break;
                        }

                        int oxygen_upgrade_cost = oxygen_upgrade_choice * 25;

                        if (credits >= oxygen_upgrade_cost) {
                            oxygen += oxygen_upgrade_choice * 20;
                            credits -= oxygen_upgrade_cost;
                            printf("\nUpgrade complete.\n");
                        } else {
                            printf("\nYou do not have enough credits.\n");
                        }

                        break;
                    default:
                        printf("\nInvalid choice.\n");
                        break;
                }
                
                break;
            case 4: // Rest and recover
                printf("\nResting and recovering...\n");
                printf("...");
                printf("...");
                printf("...");
                printf("\nYou have fully recovered!\n");
                health = 100;
                break;
            case 5: // Quitting the game
                printf("\nQuitting the game...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

        // Subtracting resources each turn
        fuel -= 10;
        oxygen -= 5;
        health -= 5;

        // Checking for loss conditions
        if (health <= 0) {
            printf("\nYou have died!\n");
            printf("Game over.\n");
        } else if (fuel <= 0) {
            printf("\nYou have run out of fuel!\n");
            printf("Game over.\n");
        } else if (oxygen <= 0) {
            printf("\nYou have run out of oxygen!\n");
            printf("Game over.\n");
        }
    }
    
    return 0;
}