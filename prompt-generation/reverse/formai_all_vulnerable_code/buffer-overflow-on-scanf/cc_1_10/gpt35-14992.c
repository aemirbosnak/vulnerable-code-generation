//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SHIP_HEALTH 100
#define MAX_ENEMY_HEALTH 50
#define MAX_ENEMY_DAMAGE 10
#define MAX_PLAYER_NAME 20

int player_health = MAX_SHIP_HEALTH;
int enemy_health = MAX_ENEMY_HEALTH;
char player_name[MAX_PLAYER_NAME];

void clear_screen() {
    system("clear || cls");
}

void print_intro() {
    printf("Welcome to the post-apocalyptic universe, %s!\n", player_name);
    printf("Your spaceship has crash-landed on a deserted planet, and you must repair it to escape.\nBut beware, you are not alone in the vastness of space.\nAn unknown enemy race wants to capture you, and it won't be easy to fight them off.\n");
    printf("Get ready for an adventure of a lifetime!\n\n");
}

void print_menu() {
    printf("What do you want to do?\n");
    printf("1. Repair ship\n");
    printf("2. Attack enemy\n");
    printf("3. Check ship health\n");
    printf("4. Check enemy health\n");
    printf("5. Quit game\n\n");
}

void print_ship_health() {
    printf("Your ship's health: %d/%d\n", player_health, MAX_SHIP_HEALTH);
}

void print_enemy_health() {
    printf("Enemy's health: %d/%d\n", enemy_health, MAX_ENEMY_HEALTH);
}

int calculate_enemy_damage() {
    return (rand() % MAX_ENEMY_DAMAGE) + 1;
}

bool is_player_alive() {
    return player_health > 0;
}

bool is_enemy_alive() {
    return enemy_health > 0;
}

void repair_ship() {
    int repair_amount = rand() % 20 + 1;
    player_health += repair_amount;
    printf("You successfully repaired your ship and gained %d health.\n", repair_amount);
    if (player_health > MAX_SHIP_HEALTH) {
        player_health = MAX_SHIP_HEALTH;
    }
}

void attack_enemy() {
    int player_damage = rand() % 20 + 1;
    int enemy_damage = calculate_enemy_damage();
    enemy_health -= player_damage;
    printf("You dealt %d damage to the enemy.\n", player_damage);
    if (!is_enemy_alive()) {
        printf("Congratulations, you defeated the enemy!\n");
        return;
    }
    printf("The enemy retaliated and dealt %d damage to you.\n", enemy_damage);
    player_health -= enemy_damage;
    if (!is_player_alive()) {
        printf("You died.\n");
    }
}

int main() {
    srand(time(NULL));
    clear_screen();
    printf("Welcome to the post-apocalyptic space adventure!\n\n");
    printf("Please enter your name: ");
    fgets(player_name, MAX_PLAYER_NAME, stdin);
    strtok(player_name, "\n"); // remove trailing newline character
    clear_screen();
    print_intro();
    while (true) {
        print_menu();
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // eat up trailing newline character
        switch (choice) {
            case 1:
                repair_ship();
                break;
            case 2:
                attack_enemy();
                break;
            case 3:
                print_ship_health();
                break;
            case 4:
                print_enemy_health();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    }
    return 0;
}