//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int hp;
    int attack;
    int defense;
} Player;

void print_menu() {
    printf("1. Attack\n");
    printf("2. Defend\n");
    printf("3. Heal\n");
    printf("4. Use Item\n");
    printf("5. Run\n");
}

void print_game_over() {
    printf("Game Over\n");
    exit(0);
}

int main() {
    Player player;
    Player enemy;

    // Initialize player
    player.hp = 100;
    player.attack = 10;
    player.defense = 5;

    // Initialize enemy
    enemy.hp = 100;
    enemy.attack = 10;
    enemy.defense = 5;

    while (player.hp > 0 && enemy.hp > 0) {
        // Print menu
        print_menu();

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Check for valid input
        if (choice < 1 || choice > 5) {
            printf("Invalid input\n");
            continue;
        }

        // Execute action
        switch (choice) {
            case 1:
                // Attack
                enemy.hp -= player.attack;
                printf("You attack the enemy and deal %d damage\n", player.attack);
                break;
            case 2:
                // Defend
                enemy.attack -= player.defense;
                printf("You defend and the enemy's attack is reduced by %d\n", player.defense);
                break;
            case 3:
                // Heal
                player.hp += 10;
                printf("You heal for 10 HP\n");
                break;
            case 4:
                // Use item
                printf("You use an item and it restores 20 HP\n");
                player.hp += 20;
                break;
            case 5:
                // Run
                printf("You run away and lose the game\n");
                print_game_over();
                break;
        }

        // Print enemy stats
        printf("Enemy HP: %d\n", enemy.hp);

        // Check if enemy is dead
        if (enemy.hp <= 0) {
            printf("You defeated the enemy\n");
            print_game_over();
        }
    }

    return 0;
}