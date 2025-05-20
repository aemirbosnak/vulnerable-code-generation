#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER_NAME_LENGTH 20

void print_game_intro() {
    printf("Welcome to the Dungeon of Doom!\n");
    printf("Enter your brave warrior's name:\n");
}

int main() {
    char player_name[MAX_PLAYER_NAME_LENGTH];
    int player_health = 100;
    char enemy_name[] = "Goblin King";
    int enemy_health = 50;

    print_game_intro();
    scanf("%s", player_name);

    while (player_health > 0 && enemy_health > 0) {
        printf("%s attacks the %s for %d damage!\n", player_name, enemy_name, player_health);
        player_health -= 10;
        enemy_health -= 5;

        if (enemy_health <= 0) {
            printf("%s has been defeated! You are the champion of the Dungeon of Doom!\n", enemy_name);
            break;
        }

        printf("%s retaliates with %d damage!\n", enemy_name, enemy_health);
        player_health -= enemy_health;
    }

    if (player_health <= 0) {
        printf("Game Over. You have died in the Dungeon of Doom.\n");
    }

    return 0;
}
