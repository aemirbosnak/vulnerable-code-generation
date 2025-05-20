//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>

int health = 100;
int strength = 50;
int room = 1;

void printIntro() {
    printf("Welcome to Dungeon Crawler!\n");
    printf("You awaken to find yourself in a dark dungeon.\n");
    printf("Your goal is to navigate through the rooms and defeat the final boss.\n");
    printf("Let's begin...\n\n");
}

void processInput(char action) {
    switch(action) {
        case 'a':
            printf("You attempt to open the door to the left...\n");
            if(room == 1) {
                printf("The door is locked...\n");
            } else if(room == 2) {
                printf("The door creaks open and reveals a small room with a treasure chest!\n");
                printf("You gain 50 gold and 25 health!\n");
                health += 25;
            } else if(room == 3) {
                printf("The door leads to a room filled with goblins!\n");
                printf("Prepare for battle!\n");
            }
            break;
        case 'd':
            printf("You attempt to open the door to the right...\n");
            if(room == 1) {
                printf("The door creaks open and reveals a staircase leading downwards...\n");
                room = 2;
            } else if(room == 2) {
                printf("The door leads to a room with a dragon guarding the exit...\n");
                printf("Prepare for battle!\n");
            } else if(room == 3) {
                printf("The door leads to a room with a chest full of gold!\n");
                printf("You gain 100 gold!\n");
            }
            break;
        case 'w':
            printf("You continue to explore the current room...\n");
            if(room == 1) {
                printf("You see a hallway leading east but it appears to be blocked by rubble...\n");
            } else if(room == 2) {
                printf("You find nothing else of interest...\n");
            } else if(room == 3) {
                printf("You find a map of the dungeon on a table...\n");
                printf("The map reveals a secret room somewhere on this floor...\n");
            }
            break;
        case 's':
            printf("You return to the previous room...\n");
            if(room == 1) {
                printf("You see the entrance you came from...\n");
            } else if(room == 2) {
                printf("You see the stairs leading back up to the previous room...\n");
                room = 1;
            }
            break;
        default:
            printf("Invalid option...\n");
            break;
    }
}

void battle(char enemyType) {
    int enemyHealth;
    int enemyStrength;
    int playerDamage;
    int enemyDamage;

    switch(enemyType) {
        case 'g':
            printf("You encounter a goblin!\n");
            enemyHealth = 25;
            enemyStrength = 10;
            break;
        case 'd':
            printf("You encounter a dragon!\n");
            enemyHealth = 100;
            enemyStrength = 25;
            break;
        default:
            printf("Invalid enemy type...\n");
            break;
    }

    while(health > 0 && enemyHealth > 0) {
        playerDamage = strength;
        enemyDamage = enemyStrength;

        enemyHealth -= playerDamage;
        printf("You deal %d damage to the enemy!\n", playerDamage);
        
        if(enemyHealth <= 0) {
            printf("You have defeated the enemy!\n");
            break;
        }

        health -= enemyDamage;
        printf("The enemy deals %d damage to you!\n", enemyDamage);

        if(health <= 0) {
            printf("You have been defeated...\n");
            break;
        }
    }
}

int main() {
    char action;
    printIntro();

    while(room != 3) {
        printf("Current Stats: Health - %d, Strength - %d\n", health, strength);
        printf("Choose an action (a - left, d - right, w - explore, s - back): ");
        scanf(" %c", &action);
        printf("\n");

        processInput(action);
    }

    battle('d');

    printf("Congratulations, you have defeated the final boss and escaped the dungeon!");
    return 0;
}