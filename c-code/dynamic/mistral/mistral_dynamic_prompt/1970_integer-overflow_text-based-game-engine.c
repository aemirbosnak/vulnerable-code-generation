#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_HEALTH 100

struct player {
    char name[MAX_NAME_LEN];
    int health;
};

struct enemy {
    char type[20];
    int health;
};

void create_player(struct player *player, char *name) {
    strcpy(player->name, name);
    player->health = MAX_HEALTH;
}

void display_player(struct player *player) {
    printf("Player: %s\nHealth: %d\n", player->name, player->health);
}

struct enemy *create_enemy(char *type, int health) {
    struct enemy *enemy = (struct enemy *) malloc(sizeof(struct enemy));
    strcpy(enemy->type, type);
    enemy->health = health;
    return enemy;
}

void attack(struct player *player, struct enemy *enemy) {
    player->health -= enemy->health;
}

int main(int argc, char *argv[]) {
    struct player player;
    struct enemy *dragon = create_enemy("Dragon", 50);
    create_player(&player, argv[1]);

    while (player.health > 0) {
        printf("Player attacks the Dragon!\n");
        attack(&player, dragon);
        printf("Dragon attacks the player!\n");
        printf("Dragon's health: %d\n", dragon->health);
        if (dragon->health <= 0) {
            free(dragon);
            break;
        }
        printf("Player's health: %d\n", player.health);
    }

    if (player.health <= 0) {
        printf("Game Over! You died, %s.\n", player.name);
    } else {
        printf("You defeated the Dragon, %s! Congratulations!\n", player.name);
    }

    return 0;
}
