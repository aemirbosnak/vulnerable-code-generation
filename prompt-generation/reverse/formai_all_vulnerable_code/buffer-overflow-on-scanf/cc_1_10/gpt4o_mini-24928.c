//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_MONSTERS 5

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    int health;
} Player;

typedef struct {
    Position pos;
    int health;
} Monster;

char dungeon[HEIGHT][WIDTH];
Player player;
Monster monsters[MAX_MONSTERS];

void init_dungeon() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dungeon[i][j] = '.';
        }
    }
}

void place_player() {
    player.pos.x = rand() % WIDTH;
    player.pos.y = rand() % HEIGHT;
    dungeon[player.pos.y][player.pos.x] = '@';
    player.health = 100;
}

void place_monsters() {
    for (int i = 0; i < MAX_MONSTERS; i++) {
        monsters[i].pos.x = rand() % WIDTH;
        monsters[i].pos.y = rand() % HEIGHT;
        monsters[i].health = 30;
        dungeon[monsters[i].pos.y][monsters[i].pos.x] = 'M';
    }
}

void print_dungeon() {
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", dungeon[i][j]);
        }
        printf("\n");
    }
    printf("Player health: %d\n", player.health);
}

void move_player(int dx, int dy) {
    int newX = player.pos.x + dx;
    int newY = player.pos.y + dy;

    if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
        printf("You can't move there!\n");
        return;
    }

    if (dungeon[newY][newX] == 'M') {
        printf("You encountered a monster!\n");
        player.health -= 10; // The player takes damage
        printf("You lost 10 health! Died? %s\n", player.health <= 0 ? "Yes" : "No");
    }

    dungeon[player.pos.y][player.pos.x] = '.'; // Clear old position
    player.pos.x = newX;
    player.pos.y = newY;
    dungeon[player.pos.y][player.pos.x] = '@'; // Mark new position
}

int main() {
    srand(time(NULL));
    init_dungeon();
    place_player();
    place_monsters();

    char command;
    print_dungeon();

    while (player.health > 0) {
        printf("Enter command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'w': move_player(0, -1); break;
            case 's': move_player(0, 1); break;
            case 'a': move_player(-1, 0); break;
            case 'd': move_player(1, 0); break;
            case 'q': printf("Exiting game...\n"); return 0;
            default: printf("Unknown command!\n"); break;
        }
        
        print_dungeon();
    }

    printf("Game Over! You have died!\n");
    return 0;
}