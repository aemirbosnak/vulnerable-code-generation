//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MAX_MONSTERS 5

typedef struct {
    int x, y;
    int type;
} monster;

typedef struct {
    int x, y;
    int visited;
} room;

room rooms[ROOMS][ROOMS];
monster monsters[MAX_MONSTERS];

void generate_rooms() {
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            rooms[i][j].x = i;
            rooms[i][j].y = j;
            rooms[i][j].visited = 0;
        }
    }
}

void generate_monsters() {
    for (int i = 0; i < MAX_MONSTERS; i++) {
        monsters[i].x = rand() % ROOMS;
        monsters[i].y = rand() % ROOMS;
        monsters[i].type = rand() % 3;
    }
}

void print_rooms() {
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            if (rooms[i][j].visited) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void print_monsters() {
    for (int i = 0; i < MAX_MONSTERS; i++) {
        printf("%d %d %d\n", monsters[i].x, monsters[i].y, monsters[i].type);
    }
}

int main() {
    srand(time(NULL));
    generate_rooms();
    generate_monsters();

    int x, y;
    while (1) {
        printf("Enter your coordinates (x, y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= ROOMS || y < 0 || y >= ROOMS) {
            printf("Invalid coordinates.\n");
            continue;
        }

        if (rooms[x][y].visited) { 
            printf ("You have already visited this room.\n"); 
            continue; 
        }

        rooms[x][y].visited = 1;

        for (int i = 0; i < MAX_MONSTERS; i++) {
            if (monsters[i].x == x && monsters[i].y == y) {
                printf("You encountered a monster of type %d.\n", monsters[i].type);
                break;
            }
        }

        print_rooms();
        print_monsters();
    }

    return 0;
}