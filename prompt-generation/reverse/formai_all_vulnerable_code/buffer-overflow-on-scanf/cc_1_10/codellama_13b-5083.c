//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Declare variables
int health = 100;
int damage = 20;
int enemy_health = 50;
int enemy_damage = 10;
bool is_player_turn = true;

// Declare functions
void print_status() {
    printf("Health: %d\n", health);
    printf("Enemy Health: %d\n", enemy_health);
    if (is_player_turn) {
        printf("Your turn.\n");
    } else {
        printf("Enemy's turn.\n");
    }
}

void player_turn() {
    int player_choice = 0;
    printf("Choose your action:\n");
    printf("1. Attack\n");
    printf("2. Use potion\n");
    scanf("%d", &player_choice);
    if (player_choice == 1) {
        enemy_health -= damage;
        if (enemy_health <= 0) {
            printf("You have defeated the enemy!\n");
            exit(0);
        }
    } else if (player_choice == 2) {
        health += 20;
        printf("You have recovered 20 health points.\n");
    }
    is_player_turn = false;
}

void enemy_turn() {
    enemy_health -= damage;
    if (enemy_health <= 0) {
        printf("You have defeated the enemy!\n");
        exit(0);
    }
    is_player_turn = true;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Game loop
    while (true) {
        // Print status
        print_status();

        // Player's turn
        if (is_player_turn) {
            player_turn();
        }

        // Enemy's turn
        if (!is_player_turn) {
            enemy_turn();
        }
    }

    return 0;
}