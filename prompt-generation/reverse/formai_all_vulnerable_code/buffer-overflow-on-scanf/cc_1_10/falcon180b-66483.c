//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void intro();
void character_creation();
void play_game();
void combat(int player_health, int enemy_health);

int main() {
    intro();
    character_creation();
    play_game();
    return 0;
}

// Introduction
void intro() {
    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer traveling through the galaxy.\n");
    printf("Create your character and embark on an epic journey!\n\n");
}

// Character creation
void character_creation() {
    char name[20];
    int health;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your starting health (100-200): ");
    scanf("%d", &health);

    if (health < 100 || health > 200) {
        printf("Invalid health. Setting health to 100.\n");
        health = 100;
    }

    printf("\nYour name is %s and you have %d health points.\n\n", name, health);
}

// Play the game
void play_game() {
    int player_health = 100;
    int enemy_health = 75;

    while (player_health > 0 && enemy_health > 0) {
        combat(player_health, enemy_health);
    }

    if (player_health <= 0) {
        printf("\nYou have been defeated by the enemy. Game over.\n");
    } else {
        printf("\nYou have defeated the enemy. Congratulations!\n");
    }
}

// Combat
void combat(int player_health, int enemy_health) {
    printf("\nYou encounter an enemy spaceship!\n");
    printf("Enemy health: %d\n", enemy_health);

    int attack_damage;

    printf("Enter your attack (1-10): ");
    scanf("%d", &attack_damage);

    if (attack_damage > 10 || attack_damage < 1) {
        printf("Invalid attack. Dealing 5 damage.\n");
        attack_damage = 5;
    }

    enemy_health -= attack_damage;

    if (enemy_health <= 0) {
        printf("\nYou have destroyed the enemy spaceship!\n");
    } else {
        printf("\nThe enemy fires back! You take 5 damage.\n");
        player_health -= 5;
    }

    printf("\nYour health: %d\n", player_health);
    printf("Enemy health: %d\n\n", enemy_health);
}