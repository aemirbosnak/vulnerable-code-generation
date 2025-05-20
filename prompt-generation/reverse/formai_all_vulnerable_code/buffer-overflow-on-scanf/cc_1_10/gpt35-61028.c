//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100;
int level = 1;
int damage = 20;
int stamina = 50;

void introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are the chosen one to save the kingdom from the evil sorcerer.\n");
    printf("Let's start your journey!\n\n");
}

void game_over() {
    printf("Unfortunately, you have lost the game.\n");
    printf("But don't worry, you can try again!\n");
    exit(0);
}

void win_game() {
    printf("Congratulations! You have won the game!\n");
    printf("The kingdom is saved!\n");
    exit(0);
}

void attack() {
    printf("You attack the enemy with your sword!\n");
    int random_damage = rand() % damage;
    printf("You deal %d damage to the enemy!\n", random_damage);
    stamina -= 10;
}

void defend() {
    printf("You defend yourself with your shield!\n");
    stamina -= 5;
}

void heal() {
    printf("You use your healing potion!\n");
    int random_healing = rand() % 20;
    health += random_healing;
    printf("You gain %d health!\n", random_healing);
}

void run_away() {
    printf("You run away from the enemy!\n");
    stamina -= 20;
}

void enemy_attack() {
    printf("The enemy attacks you!\n");
    int random_enemy_damage = rand() % 15 + 5;
    printf("You take %d damage!\n", random_enemy_damage);
    health -= random_enemy_damage;
}

void level_up() {
    level++;
    printf("You have leveled up! You are now level %d!\n", level);
    health += 20;
    damage += 5;
}

int main() {
    srand(time(NULL));
    introduction();

    while (1) {
        printf("Current Level: %d\n", level);
        printf("Current Health: %d\n", health);
        printf("Current Stamina: %d\n\n", stamina);

        int random_encounter = rand() % 5;
        if (random_encounter == 0) {
            printf("You encounter a bear!\n");
            printf("What do you want to do?\n");
            printf("1. Attack\n");
            printf("2. Defend\n");
            printf("3. Heal\n");
            printf("4. Run Away\n");

            int action;
            scanf("%d", &action);

            switch (action) {
                case 1:
                    attack();
                    enemy_attack();
                    break;
                case 2:
                    defend();
                    enemy_attack();
                    break;
                case 3:
                    heal();
                    enemy_attack();
                    break;
                case 4:
                    run_away();
                    break;
                default:
                    printf("Invalid input. Try again.\n\n");
                    break;
            }

            if (health <= 0) {
                game_over();
            }

            if (stamina <= 0) {
                printf("You are too tired to continue! You return to your village to rest.\n");
                stamina += 50;
                break;
            }

            if (level == 3) {
                win_game();
            }

            int random_treasure = rand() % 10;
            if (random_treasure == 0) {
                printf("You found a treasure chest!\n");
                printf("You gain 50 gold!\n");
                printf("You gain a potion of healing!\n");
            }

            int random_level_up = rand() % 20;
            if (random_level_up == 0) {
                level_up();
            }
        }
    }

    return 0;
}