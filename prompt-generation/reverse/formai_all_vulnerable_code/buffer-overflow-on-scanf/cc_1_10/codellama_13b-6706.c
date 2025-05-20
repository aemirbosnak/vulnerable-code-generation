//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_ROOMS 100
#define MAX_PLAYER_HEALTH 100
#define MAX_PLAYER_DAMAGE 10
#define MAX_ENEMY_HEALTH 20
#define MAX_ENEMY_DAMAGE 5

typedef struct {
    int x, y;
    int health;
    int damage;
} Enemy;

typedef struct {
    int x, y;
    int health;
    int damage;
} Player;

typedef struct {
    int x, y;
    int width, height;
    int type;
} Room;

void init_player(Player *player) {
    player->x = 1;
    player->y = 1;
    player->health = MAX_PLAYER_HEALTH;
    player->damage = MAX_PLAYER_DAMAGE;
}

void init_enemy(Enemy *enemy) {
    enemy->x = rand() % (MAX_WIDTH - 2) + 1;
    enemy->y = rand() % (MAX_HEIGHT - 2) + 1;
    enemy->health = MAX_ENEMY_HEALTH;
    enemy->damage = MAX_ENEMY_DAMAGE;
}

void init_room(Room *room) {
    room->x = rand() % (MAX_WIDTH - 2) + 1;
    room->y = rand() % (MAX_HEIGHT - 2) + 1;
    room->width = rand() % 10 + 5;
    room->height = rand() % 10 + 5;
    room->type = rand() % 3;
}

void print_room(Room *room) {
    int i, j;
    for (i = 0; i < room->height; i++) {
        for (j = 0; j < room->width; j++) {
            if (room->type == 0) {
                printf(".");
            } else if (room->type == 1) {
                printf("*");
            } else if (room->type == 2) {
                printf("+");
            }
        }
        printf("\n");
    }
}

void print_player(Player *player) {
    printf("X: %d, Y: %d, Health: %d\n", player->x, player->y, player->health);
}

void print_enemy(Enemy *enemy) {
    printf("X: %d, Y: %d, Health: %d\n", enemy->x, enemy->y, enemy->health);
}

void move_player(Player *player, char direction) {
    if (direction == 'w' && player->y > 0) {
        player->y--;
    } else if (direction == 'a' && player->x > 0) {
        player->x--;
    } else if (direction == 's' && player->y < MAX_HEIGHT - 1) {
        player->y++;
    } else if (direction == 'd' && player->x < MAX_WIDTH - 1) {
        player->x++;
    }
}

void move_enemy(Enemy *enemy, Player *player) {
    if (enemy->x == player->x && enemy->y == player->y) {
        player->health -= enemy->damage;
        if (player->health <= 0) {
            printf("You have been killed.\n");
            exit(1);
        }
    }
    if (rand() % 2 == 0) {
        enemy->x++;
    } else {
        enemy->x--;
    }
    if (rand() % 2 == 0) {
        enemy->y++;
    } else {
        enemy->y--;
    }
}

int main() {
    srand(time(NULL));

    Player player;
    init_player(&player);

    Enemy enemy;
    init_enemy(&enemy);

    Room room;
    init_room(&room);

    print_room(&room);
    print_player(&player);
    print_enemy(&enemy);

    char direction;
    while (1) {
        printf("Enter direction (w, a, s, d): ");
        scanf("%c", &direction);
        move_player(&player, direction);
        move_enemy(&enemy, &player);
        print_room(&room);
        print_player(&player);
        print_enemy(&enemy);
        if (player.x == room.x && player.y == room.y) {
            printf("You have reached the exit.\n");
            exit(0);
        }
    }

    return 0;
}