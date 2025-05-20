//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100; // Player health
int ammo = 10; // Player ammunition
int food = 5; // Player food supply
int location = 0; // Player location tracker
int end = 0; // End game tracker

// Function to display player status
void status() {
    printf("\n------------------------\n");
    printf("Location: %d\nHealth: %d\nAmmo: %d\nFood: %d\n", location, health, ammo, food);
    printf("------------------------\n");
}

// Function for event at location 0
void location_zero() {
    printf("\nYou see a destroyed building in the distance.\n");
    printf("What would you like to do?\n");
    printf("1. Investigate the building\n2. Move on\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nAs you enter the building, you hear a loud noise coming from upstairs.\n");
        printf("What would you like to do?\n");
        printf("1. Investigate the noise\n2. Leave the building\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nAs you climb the stairs, you are suddenly ambushed by a group of raiders.\n");
            printf("You have no choice but to fight!\n");

            int raider_health = 50;
            while (raider_health > 0 && health > 0) {
                printf("\nYour health: %d\nRaider's health: %d\n", health, raider_health);
                printf("What would you like to do?\n");
                printf("1. Shoot\n2. Run\n");

                scanf("%d", &choice);

                if (choice == 1) {
                    printf("\nYou shoot the raider, dealing 25 damage.\n");
                    raider_health -= 25;
                } else {
                    printf("\nYou try to run, but the raider catches up to you and attacks!\n");
                    int damage = rand() % 20 + 1;
                    printf("You take %d damage.\n", damage);
                    health -= damage;
                }
            }

            if (raider_health <= 0) {
                printf("\nYou defeated the raiders and found a valuable item in the building!\n");
                ammo += 5;
            } else {
                printf("\nYou have been defeated by the raiders.\n");
                end = 1;
            }
        } else {
            printf("\nYou leave the building and continue on your journey.\n");
            location = 1;
        }
    } else {
        printf("\nYou continue on your journey.\n");
        location = 1;
    }
}

// Function for event at location 1
void location_one() {
    printf("\nYou come across a group of survivors who look hungry.\n");
    printf("What would you like to do?\n");
    printf("1. Offer some food\n2. Keep moving\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        if (food > 0) {
            printf("\nYou offer the survivors some food.\n");
            food--;

            int chance = rand() % 2 + 1;
            if (chance == 1) {
                printf("\nThe survivors are grateful and offer you a valuable item in return!\n");
                ammo += 10;
            } else {
                printf("\nThe survivors betray you and steal some of your ammo!\n");
                ammo -= 5;
            }
        } else {
            printf("\nYou don't have any food to offer.\n");
        }
    }

    printf("\nYou continue on your journey.\n");
    location = 2;
}

// Function for event at location 2
void location_two() {
    printf("\nYou see a deserted town in the distance.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the town\n2. Avoid the town\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nAs you explore the town, you discover a group of survivors in the town square.\n");
        printf("What would you like to do?\n");
        printf("1. Approach the survivors\n2. Leave the town\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nAs you approach the survivors, they tell you about a nearby bunker that is still intact.\n");
            printf("They offer to take you there, but they need your help fighting off some raiders.\n");

            int raider_health = 75;
            while (raider_health > 0 && health > 0) {
                printf("\nYour health: %d\nRaider's health: %d\n", health, raider_health);
                printf("What would you like to do?\n");
                printf("1. Shoot\n2. Run\n");

                scanf("%d", &choice);

                if (choice == 1) {
                    printf("\nYou shoot the raider, dealing 35 damage.\n");
                    raider_health -= 35;
                } else {
                    printf("\nYou try to run, but the raiders catch up to you and attack!\n");
                    int damage = rand() % 30 + 1;
                    printf("You take %d damage.\n", damage);
                    health -= damage;
                }
            }

            if (raider_health <= 0) {
                printf("\nYou defeated the raiders and the survivors take you to the bunker.\n");
                end = 2;
            } else {
                printf("\nYou have been defeated by the raiders.\n");
                end = 1;
            }
        } else {
            printf("\nYou leave the town and continue on your journey.\n");
            location = 3;
        }
    } else {
        printf("\nYou avoid the town and continue on your journey.\n");
        location = 3;
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the post-apocalyptic adventure game!\n");
    printf("You are a lone survivor trying to navigate the dangerous wasteland.\n");
    printf("Your goal is to reach the safety of a nearby bunker before your resources run out.\n");

    while (!end) {
        switch (location) {
            case 0:
                location_zero();
                break;
            case 1:
                location_one();
                break;
            case 2:
                location_two();
                break;
            case 3:
                printf("\nYou continue on your journey.\n");
                printf("What would you like to do?\n");
                printf("1. Check your status\n2. Move to the next location\n");

                int choice;
                scanf("%d", &choice);

                if (choice == 1) {
                    status();
                }

                location = 4;
                break;
            case 4:
                printf("\nYou see a deserted road up ahead.\n");
                printf("What would you like to do?\n");
                printf("1. Rest and recover health\n2. Continue on your journey\n");

                scanf("%d", &choice);

                if (choice == 1) {
                    printf("\nYou take a break and recover some health.\n");
                    health += 25;
                    if (health > 100) {
                        health = 100;
                    }
                }

                location = 5;
                break;
            case 5:
                printf("\nYou see the bunker in the distance!\n");
                printf("What would you like to do?\n");
                printf("1. Run to the bunker\n2. Take it slow\n");

                scanf("%d", &choice);

                if (choice == 1) {
                    printf("\nYou run to the bunker and reach safety!\n");
                    end = 2;
                } else {
                    printf("\nYou take it slow and make it to the bunker.\n");
                    end = 2;
                }

                break;
            default:
                break;
        }

        // Check if player has run out of resources
        if (health <= 0) {
            printf("\nYou have died in the wasteland.\n");
            end = 1;
        } else if (ammo <= 0 && food <= 0) {
            printf("\nYou have run out of resources and cannot continue.\n");
            end = 1;
        }
    }

    if (end == 2) {
        printf("\nCongratulations! You have reached the safety of the bunker!\n");
    } else {
        printf("\nGame over.\n");
    }

    return 0;
}