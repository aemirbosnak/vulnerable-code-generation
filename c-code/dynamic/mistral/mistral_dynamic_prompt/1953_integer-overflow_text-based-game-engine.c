#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    char weapon[32];
    int health;
    int armor;
} Player;

void init_player(Player* player) {
    strcpy(player->name, "New Player");
    strcpy(player->weapon, "Dagger");
    player->health = 100;
    player->armor = 0;
}

void attack(Player* attacker, Player* defender, int power) {
    int damage = power * (attacker->armor / 10);
    defender->health -= damage;
    printf("%s attacks %s with a %s and deals %d points of damage.\n",
           attacker->name, defender->name, attacker->weapon, damage);
    if (defender->health <= 0) {
        printf("%s has been defeated!\n", defender->name);
    }
}

int main() {
    Player player, enemy;
    init_player(&player);
    printf("Welcome, %s! You are a brave warrior equipped with a %s.\n", player.name, player.weapon);
    while (1) {
        int input;
        printf("Enter the power of your attack (1-100): ");
        scanf("%d", &input);
        if (input > 100 || input < 1) {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            continue;
        }
        attack(&player, &enemy, input);
    }
    return 0;
}
