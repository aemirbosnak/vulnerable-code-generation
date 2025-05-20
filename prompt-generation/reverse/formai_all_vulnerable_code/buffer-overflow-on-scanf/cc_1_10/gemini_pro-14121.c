//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MONSTERS 5

typedef struct {
    int x, y;
    int type;
} Monster;

typedef struct {
    int x, y;
    int visited;
} Room;

Room rooms[ROOMS][ROOMS];
Monster monsters[MONSTERS];

void init_rooms() {
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            rooms[i][j].x = i;
            rooms[i][j].y = j;
            rooms[i][j].visited = 0;
        }
    }
}

void init_monsters() {
    for (int i = 0; i < MONSTERS; i++) {
        monsters[i].x = rand() % ROOMS;
        monsters[i].y = rand() % ROOMS;
        monsters[i].type = rand() % 3;
    }
}

void draw_map() {
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            if (rooms[i][j].visited) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    init_rooms();
    init_monsters();

    int player_x = 0;
    int player_y = 0;

    while (1) {
        draw_map();

        char input;
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                if (player_y > 0) {
                    player_y--;
                }
                break;
            case 'a':
                if (player_x > 0) {
                    player_x--;
                }
                break;
            case 's':
                if (player_y < ROOMS - 1) {
                    player_y++;
                }
                break;
            case 'd':
                if (player_x < ROOMS - 1) {
                    player_x++;
                }
                break;
            case 'q':
                exit(0);
        }

        rooms[player_x][player_y].visited = 1;

        for (int i = 0; i < MONSTERS; i++) {
            if (monsters[i].x == player_x && monsters[i].y == player_y) {
                printf("You died!\n");
                exit(0);
            }
        }
    }

    return 0;
}