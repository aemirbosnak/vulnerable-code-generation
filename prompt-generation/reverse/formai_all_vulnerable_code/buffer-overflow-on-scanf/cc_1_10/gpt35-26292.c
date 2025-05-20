//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int attack;
    int defense;
    int health;
} Player;

typedef struct {
    char name[MAX_NAME_LEN];
    int reward;
} Planet;

void print_planet_info(Planet planet) {
    printf("You have landed on planet %s. Your mission is to defeat all enemies and collect %d space coins.\n", planet.name, planet.reward);
}

void generate_random_enemy(Player* enemy) {
    char names[5][MAX_NAME_LEN] = {"Zorg", "Gorgon", "Xalax", "Krogan", "Vorlon"};
    int healths[5] = {50, 70, 90, 110, 130};
    int attacks[5] = {15, 20, 25, 30, 35};
    int defenses[5] = {10, 15, 20, 25, 30};
    int random_index = rand() % 5;
    strcpy(enemy->name, names[random_index]);
    enemy->health = healths[random_index];
    enemy->attack = attacks[random_index];
    enemy->defense = defenses[random_index];
}

void battle(Player* player, Player* enemy) {
    printf("A wild %s appears!\n", enemy->name);
    while (player->health > 0 && enemy->health > 0) {
        printf("Your health: %d. Enemy health: %d.\n", player->health, enemy->health);
        int turn = rand() % 2;
        int multiplier = (turn == 0) ? (player->attack - enemy->defense) : (enemy->attack - player->defense);
        if (multiplier < 0) multiplier = 0;
        int damage = rand() % multiplier + 1;
        if (turn == 0) {
            printf("You attack the %s for %d damage!\n", enemy->name, damage);
            enemy->health -= damage;
        } else {
            printf("The %s attacks you for %d damage.\n", enemy->name, damage);
            player->health -= damage;
        }
    }
    if (player->health <= 0) {
        printf("You have been defeated.\n");
        exit(0);
    } else {
        printf("Congratulations, you have defeated the %s!\n", enemy->name);
    }
}

int main() {
    srand(time(NULL));
    Planet planets[5] = {{"Alderaan", 500}, {"Naboo", 1000}, {"Coruscant", 2000}, {"Tatooine", 4000}, {"Hoth", 8000}};
    Player player = {"Jedi", 50, 30, 100};
    int i;
    for (i = 0; i < 5; i++) {
        print_planet_info(planets[i]);
        char choice;
        printf("Do you want to land on this planet? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            Player enemy;
            generate_random_enemy(&enemy);
            printf("You have encountered an enemy on planet %s. Prepare for battle!\n", planets[i].name);
            battle(&player, &enemy);
            printf("You have defeated the enemy and earned %d space coins!\n", planets[i].reward);
            player.health += planets[i].reward;
        } else {
            printf("You have chosen to fly to the next planet.\n");
        }
    }
    printf("Congratulations, you have completed your space adventure with %d space coins!\n", player.health);
    return 0;
}