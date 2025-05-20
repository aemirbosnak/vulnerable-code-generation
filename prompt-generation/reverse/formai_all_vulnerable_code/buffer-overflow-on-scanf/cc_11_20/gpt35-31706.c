//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed for random number generator

    // Arrays to store planet names and enemy names
    char planetNames[5][20] = {"Terra", "Auraxis", "Nexus", "Elysium", "Olympus"};
    char enemyNames[3][20] = {"Zorgon", "Krynn", "Nebula"};

    // Array to store the status of each planet
    int planetStatus[5] = {0, 0, 0, 0, 0}; // 0 = Unexplored, 1 = Explored, 2 = Conquered

    // Player stats
    int playerLevel = 1, playerHealth = 100, playerCredits = 100;

    // Introduction message
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are an explorer in the galaxy, searching for valuable resources.\n");
    printf("Your goal is to explore and conquer all of the planets in the galaxy.\n");
    printf("Good luck!\n\n");

    // Game loop
    while(1) {
        // Display player stats
        printf("Level: %d\tHealth: %d\tCredits: %d\n\n", playerLevel, playerHealth, playerCredits);

        // Display planet status options
        printf("Planet Status Options:\n");
        printf("1. Explore Unexplored Planet\n");
        printf("2. Conquer Explored Planet\n");
        printf("3. View Planets\n");
        printf("4. Exit Game\n\n");

        // Prompt for player's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Explore unexplored planet
                for(int i = 0; i < 5; i++) {
                    if(planetStatus[i] == 0) {
                        // Generate a random event
                        int event = generateRandomNumber(1, 3);

                        printf("\nHeading to %s...\n", planetNames[i]);

                        switch(event) {
                            case 1:
                                // No event
                                printf("No event encountered.\n");
                                break;
                            case 2:
                                // Encounter enemy
                                printf("Encountered an enemy ship!\n");

                                int enemyHealth = generateRandomNumber(50, 100);
                                int enemyDamage = generateRandomNumber(10, 20);
                                char enemyName[20];
                                strcpy(enemyName, enemyNames[generateRandomNumber(0, 2)]);

                                while(1) {
                                    // Display battle options
                                    printf("\nBattle Options: \n");
                                    printf("1. Attack\n");
                                    printf("2. Run\n\n");

                                    // Prompt for player's choice
                                    int battleChoice;
                                    printf("Enter your choice: ");
                                    scanf("%d", &battleChoice);

                                    switch(battleChoice) {
                                        case 1:
                                            // Player attacks
                                            printf("You attack the %s for %d damage.\n", enemyName, playerLevel * 10);
                                            enemyHealth -= playerLevel * 10;

                                            if(enemyHealth <= 0) {
                                                // Enemy defeated
                                                printf("You defeated the %s!\n", enemyName);

                                                // Reward
                                                int creditsEarned = generateRandomNumber(50, 100);
                                                playerCredits += creditsEarned;
                                                printf("You earned %d credits!\n", creditsEarned);

                                                planetStatus[i] = 1;
                                                printf("%s is now explored.\n", planetNames[i]);

                                                break;
                                            }

                                            // Enemy attacks
                                            printf("The %s attacks you for %d damage.\n", enemyName, enemyDamage);
                                            playerHealth -= enemyDamage;

                                            if(playerHealth <= 0) {
                                                // Player defeated
                                                printf("You were defeated by the %s.\n", enemyName);
                                                printf("GAME OVER.\n");
                                                exit(0);
                                            }

                                            break;
                                        case 2:
                                            // Player runs away
                                            printf("You run away from the %s.\n", enemyName);
                                            break;
                                        default:
                                            printf("Invalid choice.\n");
                                            break;
                                    }
                                }
                                break;
                            case 3:
                                // Discover resource
                                printf("Discovered a valuable resource!\n");

                                int creditsFound = generateRandomNumber(50, 100);
                                playerCredits += creditsFound;

                                printf("You found %d credits!\n", creditsFound);
                                planetStatus[i] = 1;
                                printf("%s is now explored.\n", planetNames[i]);

                                break;
                            default:
                                printf("Invalid event.\n");
                                break;
                        }

                        break;
                    }
                }

                break;
            case 2:
                // Conquer explored planet
                printf("Conquering an explored planet...\n");

                // Find an explored planet
                int planetIndex = -1;
                for(int i = 0; i < 5; i++) {
                    if(planetStatus[i] == 1) {
                        planetIndex = i;
                        break;
                    }
                }

                // No explored planets found
                if(planetIndex == -1) {
                    printf("No explored planets found.\n");
                    break;
                }

                // Generate a random enemy
                int enemyHealth = generateRandomNumber(100, 150);
                int enemyDamage = generateRandomNumber(20, 30);
                char enemyName[20];
                strcpy(enemyName, enemyNames[generateRandomNumber(0, 2)]);

                printf("\nHeading to %s...\n", planetNames[planetIndex]);
                printf("Defending against enemy forces...\n");

                while(1) {
                    // Display battle options
                    printf("\nBattle Options: \n");
                    printf("1. Attack\n");
                    printf("2. Run\n\n");

                    // Prompt for player's choice
                    int battleChoice;
                    printf("Enter your choice: ");
                    scanf("%d", &battleChoice);

                    switch(battleChoice) {
                        case 1:
                            // Player attacks
                            printf("You attack the %s for %d damage.\n", enemyName, playerLevel * 10);
                            enemyHealth -= playerLevel * 10;

                            if(enemyHealth <= 0) {
                                // Enemy defeated
                                printf("You defeated the %s!\n", enemyName);

                                // Reward
                                int creditsEarned = generateRandomNumber(100, 200);
                                playerCredits += creditsEarned;
                                printf("You earned %d credits!\n", creditsEarned);

                                planetStatus[planetIndex] = 2;
                                printf("%s is now conquered.\n", planetNames[planetIndex]);

                                break;
                            }

                            // Enemy attacks
                            printf("The %s attacks you for %d damage.\n", enemyName, enemyDamage);
                            playerHealth -= enemyDamage;

                            if(playerHealth <= 0) {
                                // Player defeated
                                printf("You were defeated by the %s.\n", enemyName);
                                printf("GAME OVER.\n");
                                exit(0);
                            }

                            break;
                        case 2:
                            // Player runs away
                            printf("You run away from the %s.\n", enemyName);
                            break;
                        default:
                            printf("Invalid choice.\n");
                            break;
                    }
                }

                break;
            case 3:
                // View planets
                printf("Planet\t\tStatus\n");
                printf("------------------------\n");

                for(int i = 0; i < 5; i++) {
                    printf("%s\t\t", planetNames[i]);

                    if(planetStatus[i] == 0) {
                        printf("Unexplored\n");
                    } else if(planetStatus[i] == 1) {
                        printf("Explored\n");
                    } else {
                        printf("Conquered\n");
                    }
                }

                printf("\n");

                break;
            case 4:
                // Exit game
                printf("Exiting game...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}