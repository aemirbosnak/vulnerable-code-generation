//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int player_health;
int player_attack;
int enemy_health;
int enemy_attack;
int gold;
int choice;

// Function prototypes
void start_game();
void create_player();
void create_enemy();
int attack(int attack1, int attack2);
void display_stats();

int main() {
    srand(time(NULL));
    start_game();
    return 0;
}

void start_game() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    create_player();
    create_enemy();
    while(player_health > 0 && enemy_health > 0) {
        display_stats();
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Flee\n");
        scanf("%d", &choice);
        if(choice == 1) {
            enemy_health = attack(player_attack, enemy_attack);
            if(enemy_health <= 0) {
                printf("\nYou have defeated the enemy and gained %d gold!\n", rand() % 10 + 1);
                gold += rand() % 10 + 1;
            }
        }
        else if(choice == 2) {
            player_health -= enemy_attack;
        }
        else if(choice == 3) {
            printf("\nYou have fled the battle.\n");
            break;
        }
    }
    if(player_health <= 0) {
        printf("\nYou have been defeated by the enemy.\n");
    }
    else {
        printf("\nYou have successfully fled the battle.\n");
    }
}

void create_player() {
    printf("Creating player...\n");
    player_health = rand() % 10 + 1;
    player_attack = rand() % 10 + 1;
}

void create_enemy() {
    printf("Creating enemy...\n");
    enemy_health = rand() % 10 + 1;
    enemy_attack = rand() % 10 + 1;
}

int attack(int attack1, int attack2) {
    int damage = attack1 - attack2;
    if(damage > 0) {
        return damage;
    }
    else {
        return 0;
    }
}

void display_stats() {
    printf("\nStats:\n");
    printf("Player Health: %d\n", player_health);
    printf("Player Attack: %d\n", player_attack);
    printf("Enemy Health: %d\n", enemy_health);
    printf("Enemy Attack: %d\n", enemy_attack);
    printf("Gold: %d\n", gold);
}