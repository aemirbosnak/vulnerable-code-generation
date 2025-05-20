//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: distributed
// Adventure.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 100
#define MAX_CMDS 10

typedef struct {
    char name[MAX_INPUT];
    int x;
    int y;
    int health;
} Player;

void init_player(Player *player) {
    player->x = 0;
    player->y = 0;
    player->health = 100;
    strcpy(player->name, "Player");
}

void print_player(Player *player) {
    printf("Player: %s (%d,%d) (%d health)\n", player->name, player->x, player->y, player->health);
}

void move_player(Player *player, int dx, int dy) {
    player->x += dx;
    player->y += dy;
}

void attack_player(Player *player, int damage) {
    player->health -= damage;
    if (player->health <= 0) {
        printf("You died\n");
        exit(1);
    }
}

void handle_command(Player *player, char *cmd) {
    if (strcmp(cmd, "move") == 0) {
        int dx, dy;
        scanf("%d %d", &dx, &dy);
        move_player(player, dx, dy);
    } else if (strcmp(cmd, "attack") == 0) {
        int damage;
        scanf("%d", &damage);
        attack_player(player, damage);
    } else if (strcmp(cmd, "look") == 0) {
        print_player(player);
    } else {
        printf("Unknown command: %s\n", cmd);
    }
}

int main() {
    Player player;
    init_player(&player);

    char cmd[MAX_INPUT];
    while (1) {
        printf("> ");
        fgets(cmd, MAX_INPUT, stdin);
        if (strcmp(cmd, "quit\n") == 0) {
            break;
        }
        handle_command(&player, cmd);
    }

    return 0;
}