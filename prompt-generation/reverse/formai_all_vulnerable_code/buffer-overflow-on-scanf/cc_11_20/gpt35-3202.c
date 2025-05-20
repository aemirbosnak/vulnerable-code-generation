//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the input string contains only digits
bool isDigit(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true; 
}

// Function to print the options menu and return the user input choice
int menu() {
    int choice;
    printf("\n\nWelcome to the Post-Apocalyptic Adventure Game!\n");
    printf("1. Explore the ruins\n");
    printf("2. Search for supplies\n");
    printf("3. Fight off mutants\n");
    printf("4. Exit game\n");
    printf("Enter your choice[1-4]: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    bool gameOver = false;
    int playerHealth = 100;
    int mutantHealth = 50;
    int playerAmmo = 5;
    int playerFood = 3;
    int playerWater = 2;
    int playerMedkit = 1;
    char playerName[20];
    
    printf("What is your name? ");
    scanf("%s", playerName);
    printf("Welcome, %s! You are alone in a post-apocalyptic world.\n", playerName);

    while (gameOver == false) {
        int choice = menu();
        switch (choice) {
            case 1:
                printf("\nYou explore the ruins...");
                int randomChance = rand() % 10 + 1;
                if (randomChance > 3) {
                    printf("\nYou found a mutant!");
                    printf("\n\n%10s   %10s   %10s", "Player Health", "Mutant Health", "Player Ammo");
                    printf("\n%10d   %10d   %10d\n", playerHealth, mutantHealth, playerAmmo);
                    printf("\nDo you want to fight? [Y/N]");
                    char answer[2];
                    scanf("%s", answer);
                    if (strcmp(answer, "Y") == 0) {
                        while (playerHealth > 0 && mutantHealth > 0) {
                            printf("\n\n%10s   %10s   %10s", "Player Health", "Mutant Health", "Player Ammo");
                            printf("\n%10d   %10d   %10d\n", playerHealth, mutantHealth, playerAmmo);
                            printf("\nSelect an action:\n");
                            printf("1. Shoot the mutant\n");
                            printf("2. Use a medkit\n");
                            printf("3. Run away\n");
                            printf("Enter your choice[1-3]: ");
                            int action;
                            scanf("%d", &action);
                            switch (action) {
                                case 1:
                                    if (playerAmmo <= 0) {
                                        printf("\nYou are out of ammo!");
                                    } else {
                                        int damage = rand() % 10 + 1;
                                        printf("You hit the mutant and dealt %d damage!", damage);
                                        playerAmmo--;
                                        mutantHealth -= damage;
                                    }
                                    break;
                                case 2:
                                    if (playerMedkit <= 0) {
                                        printf("\nYou are out of medkits!");
                                    } else {
                                        playerMedkit--;
                                        playerHealth += 20;
                                        printf("\nYou used a medkit and gained 20 health points!");
                                        if (playerHealth > 100) {
                                            playerHealth = 100;
                                        }
                                    }
                                    break;
                                case 3:
                                    printf("\nYou ran away from the mutant!");
                                    break;
                                default:
                                    printf("\nInvalid action!");
                                    break;
                            }
                            if (mutantHealth <= 0) {
                                printf("\nYou defeated the mutant!");
                            } else {
                                int mutantDamage = rand() % 10 + 1;
                                playerHealth -= mutantDamage;
                                printf("\nThe mutant hit you and dealt %d damage!", mutantDamage);
                                if (playerHealth <= 0) {
                                    printf("\nYou died from the mutant attack!");
                                    gameOver = true;
                                }
                            }
                        }
                    } else {
                        printf("\nYou backed away from the mutant!");
                    }
                } else {
                    printf("\nYou didn't encounter any mutants.");
                }
                break;
            case 2:
                printf("\nYou search for supplies...");
                int randomSupply = rand() % 10 + 1;
                if (randomSupply > 5) {
                    printf("\nYou found some supplies!");
                    int randomType = rand() % 4 + 1;
                    int amount;
                    switch (randomType) {
                        case 1:
                            printf("\nYou found some ammo!");
                            printf("\nHow many do you want to take? ");
                            char ammoString[5];
                            scanf("%s", ammoString);
                            while (isDigit(ammoString) == false) {
                                printf("\nInvalid input! Enter a number: ");
                                scanf("%s", ammoString);
                            }
                            amount = atoi(ammoString);
                            if (amount > 0) {
                                playerAmmo += amount;
                                printf("\nYou took %d ammo.", amount);
                            }
                            break;
                        case 2:
                            printf("\nYou found some food!");
                            printf("\nHow many do you want to take? ");
                            char foodString[5];
                            scanf("%s", foodString);
                            while (isDigit(foodString) == false) {
                                printf("\nInvalid input! Enter a number: ");
                                scanf("%s", foodString);
                            }
                            amount = atoi(foodString);
                            if (amount > 0) {
                                playerFood += amount;
                                printf("\nYou took %d food.", amount);
                            }
                            break;
                        case 3:
                            printf("\nYou found some water!");
                            printf("\nHow many do you want to take? ");
                            char waterString[5];
                            scanf("%s", waterString);
                            while (isDigit(waterString) == false) {
                                printf("\nInvalid input! Enter a number: ");
                                scanf("%s", waterString);
                            }
                            amount = atoi(waterString);
                            if (amount > 0) {
                                playerWater += amount;
                                printf("\nYou took %d water.", amount);
                            }
                            break;
                        case 4:
                            printf("\nYou found a medkit!");
                            playerMedkit++;
                            printf("\nYou took 1 medkit.");
                            break;
                    }
                } else {
                    printf("\nYou didn't find any supplies.");
                }
                break;
            case 3:
                printf("\nYou are attacked by mutants!");
                while (playerHealth > 0 && mutantHealth > 0) {
                    printf("\n\n%10s   %10s   %10s", "Player Health", "Mutant Health", "Player Ammo");
                    printf("\n%10d   %10d   %10d\n", playerHealth, mutantHealth, playerAmmo);
                    printf("\nSelect an action:\n");
                    printf("1. Shoot the mutant\n");
                    printf("2. Use a medkit\n");
                    printf("3. Run away\n");
                    printf("Enter your choice[1-3]: ");
                    int action;
                    scanf("%d", &action);
                    switch (action) {
                        case 1:
                            if (playerAmmo <= 0) {
                                printf("\nYou are out of ammo!");
                            } else {
                                int damage = rand() % 10 + 1;
                                printf("You hit the mutant and dealt %d damage!", damage);
                                playerAmmo--;
                                mutantHealth -= damage;
                            }
                            break;
                        case 2:
                            if (playerMedkit <= 0) {
                                printf("\nYou are out of medkits!");
                            } else {
                                playerMedkit--;
                                playerHealth += 20;
                                printf("\nYou used a medkit and gained 20 health points!");
                                if (playerHealth > 100) {
                                    playerHealth = 100;
                                }
                            }
                            break;
                        case 3:
                            printf("\nYou ran away from the mutants!");
                            break;
                        default:
                            printf("\nInvalid action!");
                            break;
                    }
                    if (mutantHealth <= 0) {
                        printf("\nYou defeated the mutants!");
                        break;
                    } else {
                        int mutantDamage = rand() % 10 + 1;
                        playerHealth -= mutantDamage;
                        printf("\nThe mutants hit you and dealt %d damage!", mutantDamage);
                        if (playerHealth <= 0) {
                            printf("\nYou died from the mutant attack!");
                            gameOver = true;
                        }
                    }
                }
                break;
            case 4:
                printf("Exiting game...");
                gameOver = true;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}