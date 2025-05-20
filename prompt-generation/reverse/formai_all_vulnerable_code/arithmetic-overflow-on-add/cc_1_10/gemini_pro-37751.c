//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point pos;
    int fuel;
    int cargo;
} ship;

typedef struct {
    int x, y;
    int type;
} planet;

#define NUM_PLANETS 10

planet planets[NUM_PLANETS];
ship player;

void init_game() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = rand() % 100 - 50;
        planets[i].y = rand() % 100 - 50;
        planets[i].type = rand() % 3;
    }
    player.pos.x = 0;
    player.pos.y = 0;
    player.fuel = 100;
    player.cargo = 0;
}

void print_game() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (%d, %d)\n", i, planets[i].x, planets[i].y);
    }
    printf("Player: (%d, %d), Fuel: %d, Cargo: %d\n", player.pos.x, player.pos.y, player.fuel, player.cargo);
}

void move_player(int dx, int dy) {
    player.pos.x += dx;
    player.pos.y += dy;
    player.fuel--;
}

void land_on_planet(int planet_index) {
    if (player.pos.x == planets[planet_index].x && player.pos.y == planets[planet_index].y) {
        printf("Landed on planet %d\n", planet_index);
        if (planets[planet_index].type == 0) {
            player.cargo++;
        } else if (planets[planet_index].type == 1) {
            player.fuel += 50;
        }
    }
}

int main() {
    init_game();
    print_game();
    while (player.fuel > 0) {
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);
        int dx = 0, dy = 0;
        if (sscanf(input, "move %d %d", &dx, &dy) == 2) {
            move_player(dx, dy);
        } else if (sscanf(input, "land %d", &dx) == 1) {
            land_on_planet(dx);
        } else if (strcmp(input, "quit\n") == 0) {
            break;
        }
        print_game();
    }
    printf("Game over!\n");
    return 0;
}