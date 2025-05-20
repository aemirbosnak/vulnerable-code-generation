//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_PLAYERS 100

typedef struct {
    int x;
    int y;
    int visited;
} Room;

typedef struct {
    char name[20];
    int x;
    int y;
} Player;

int num_rooms;
int num_players;

Room rooms[MAX_ROOMS];
Player players[MAX_PLAYERS];

void generate_maze() {
    int i, j;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].x = i % 10;
        rooms[i].y = i / 10;
        rooms[i].visited = 0;
    }

    int start_x = rand() % 10;
    int start_y = rand() % 6;
    rooms[0].x = start_x;
    rooms[0].y = start_y;

    for (i = 1; i < MAX_ROOMS; i++) {
        int dx, dy;
        do {
            dx = rand() % 3 - 1;
            dy = rand() % 3 - 1;
        } while (dx == 0 && dy == 0);

        int nx = rooms[i - 1].x + dx;
        int ny = rooms[i - 1].y + dy;

        if (nx >= 0 && nx < 10 && ny >= 0 && ny < 6 &&!rooms[i].visited) {
            rooms[i].x = nx;
            rooms[i].y = ny;
            rooms[i].visited = 1;
        }
    }
}

void generate_players() {
    int i;
    for (i = 0; i < num_players; i++) {
        players[i].x = rand() % 10;
        players[i].y = rand() % 6;
    }
}

int main() {
    srand(time(NULL));

    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    generate_maze();
    generate_players();

    return 0;
}