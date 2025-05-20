//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define game state variables
int player_health = 100;
int player_coins = 0;
int player_weapon_level = 1;
int current_location = 1;

// Define function to print current state
void print_state() {
    printf("Health: %d\nCoins: %d\nWeapon Level: %d\n", player_health, player_coins, player_weapon_level);
}

// Define function for location 1
void location_1() {
    printf("You are in the forest.\n");
    printf("There is a sign pointing to the north and to the south.\n");
    printf("What do you do? (1. Go north 2. Go south 3. Stay put)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        current_location = 2;
    } else if (choice == 2) {
        current_location = 3;
    }
}

// Define function for location 2
void location_2() {
    printf("You are in the mountain.\n");
    printf("There is a treasure chest in front of you and a monster behind you.\n");
    printf("What do you do? (1. Open chest 2. Fight monster 3. Run away)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        player_coins += 10;
        printf("You found 10 coins!\n");
    } else if (choice == 2) {
        int monster_health = 20;
        while (player_health > 0 && monster_health > 0) {
            printf("You attack!\n");
            monster_health -= player_weapon_level * 5;
            printf("The monster's health is now %d.\n", monster_health);
            printf("The monster attacks!\n");
            player_health -= 10;
            printf("Your health is now %d.\n", player_health);
        }
        if (player_health > 0) {
            printf("You defeated the monster!\n");
            player_coins += 20;
            printf("You found 20 coins!\n");
        } else {
            printf("You were defeated by the monster...\n");
            exit(0);
        }
    } else if (choice == 3) {
        current_location = 1;
    }
}

// Define function for location 3
void location_3() {
    printf("You are in the town.\n");
    printf("There is a blacksmith's shop and a potion shop.\n");
    printf("What do you do? (1. Visit blacksmith 2. Visit potion shop 3. Leave town)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        int upgrade_cost = player_weapon_level * 10;
        printf("The blacksmith can upgrade your weapon for %d coins. Do you want to upgrade? (1. Yes 2. No)\n", upgrade_cost);
        scanf("%d", &choice);
        if (choice == 1 && player_coins >= upgrade_cost) {
            player_coins -= upgrade_cost;
            player_weapon_level++;
            printf("Your weapon has been upgraded to level %d!\n", player_weapon_level);
        } else {
            printf("You do not have enough coins to upgrade your weapon...\n");
        }
    } else if (choice == 2) {
        printf("The potion shop sells healing potions for 10 coins. Do you want to buy one? (1. Yes 2. No)\n");
        scanf("%d", &choice);
        if (choice == 1 && player_coins >= 10) {
            player_coins -= 10;
            player_health += 30;
            if (player_health > 100) {
                player_health = 100;
            }
            printf("You have been healed!\n");
        } else {
            printf("You do not have enough coins to buy a healing potion...\n");
        }
    } else if (choice == 3) {
        current_location = 1;
    }
}

// Define function for game loop
void *game_loop(void *arg) {
    while (1) {
        printf("\n\n\n");
        print_state();
        if (current_location == 1) {
            location_1();
        } else if (current_location == 2) {
            location_2();
        } else if (current_location == 3) {
            location_3();
        }
        if (player_health <= 0) {
            printf("GAME OVER. You have died.\n");
            exit(0);
        }
    }
}

// Main function to start the game
int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, &game_loop, NULL);
    pthread_join(tid, NULL);
    return 0;
}