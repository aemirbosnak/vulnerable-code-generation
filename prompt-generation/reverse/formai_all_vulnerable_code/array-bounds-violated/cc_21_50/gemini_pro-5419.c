//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROOM_WIDTH 10
#define ROOM_HEIGHT 10
#define NUM_ROOMS 5

struct Room {
    int x, y;
    int walls[4]; // 0 = north, 1 = east, 2 = south, 3 = west
    struct Room *neighbors[4];
};

struct Player {
    int x, y;
    int health;
};

struct Enemy {
    int x, y;
    int health;
    int damage;
};

int main() {
    struct Room rooms[NUM_ROOMS];
    struct Player player;
    struct Enemy enemy;

    // Initialize the rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].x = rand() % ROOM_WIDTH;
        rooms[i].y = rand() % ROOM_HEIGHT;

        for (int j = 0; j < 4; j++) {
            rooms[i].walls[j] = 1;
            rooms[i].neighbors[j] = NULL;
        }
    }

    // Connect the rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < 4; j++) {
            int dx = 0, dy = 0;

            switch (j) {
                case 0: // north
                    dy = -1;
                    break;
                case 1: // east
                    dx = 1;
                    break;
                case 2: // south
                    dy = 1;
                    break;
                case 3: // west
                    dx = -1;
                    break;
            }

            int nx = rooms[i].x + dx;
            int ny = rooms[i].y + dy;

            if (nx >= 0 && nx < ROOM_WIDTH && ny >= 0 && ny < ROOM_HEIGHT) {
                rooms[i].neighbors[j] = &rooms[nx + ny * ROOM_WIDTH];
                rooms[i].walls[j] = 0;
                rooms[nx + ny * ROOM_WIDTH].neighbors[j ^ 2] = &rooms[i];
                rooms[nx + ny * ROOM_WIDTH].walls[j ^ 2] = 0;
            }
        }
    }

    // Initialize the player
    player.x = rooms[0].x;
    player.y = rooms[0].y;
    player.health = 100;

    // Initialize the enemy
    enemy.x = rooms[1].x;
    enemy.y = rooms[1].y;
    enemy.health = 100;
    enemy.damage = 20;

    // Game loop
    while (player.health > 0 && enemy.health > 0) {
        // Display the map
        for (int y = 0; y < ROOM_HEIGHT; y++) {
            for (int x = 0; x < ROOM_WIDTH; x++) {
                if (x == player.x && y == player.y) {
                    printf("P");
                } else if (x == enemy.x && y == enemy.y) {
                    printf("E");
                } else {
                    printf("%c", rooms[x + y * ROOM_WIDTH].walls[0] ? '-' : ' ');
                }
            }
            printf("\n");
        }

        // Get the player's input
        char input;
        printf("Input: ");
        scanf(" %c", &input);

        // Move the player
        switch (input) {
            case 'w':
                if (rooms[player.x + player.y * ROOM_WIDTH].walls[0] == 0) {
                    player.y--;
                }
                break;
            case 'a':
                if (rooms[player.x + player.y * ROOM_WIDTH].walls[3] == 0) {
                    player.x--;
                }
                break;
            case 's':
                if (rooms[player.x + player.y * ROOM_WIDTH].walls[2] == 0) {
                    player.y++;
                }
                break;
            case 'd':
                if (rooms[player.x + player.y * ROOM_WIDTH].walls[1] == 0) {
                    player.x++;
                }
                break;
        }

        // Move the enemy
        int dx = player.x - enemy.x;
        int dy = player.y - enemy.y;
        double dist = sqrt(dx * dx + dy * dy);

        if (dist <= 1.0) {
            // Attack the player
            player.health -= enemy.damage;
        } else {
            // Move towards the player
            enemy.x += dx / dist;
            enemy.y += dy / dist;
        }
    }

    // Game over
    if (player.health <= 0) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }

    return 0;
}