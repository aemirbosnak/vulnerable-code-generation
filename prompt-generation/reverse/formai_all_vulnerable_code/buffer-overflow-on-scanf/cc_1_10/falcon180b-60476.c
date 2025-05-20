//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 10
#define GHOST_CHANCE 3

typedef struct {
    int x, y;
} Room;

Room rooms[ROOM_COUNT];

void generate_maze() {
    int i, j;

    for (i = 0; i < ROOM_COUNT; i++) {
        rooms[i].x = rand() % 10;
        rooms[i].y = rand() % 10;
    }
}

void print_maze() {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == rooms[0].x && j == rooms[0].y) {
                printf("S");
            } else if (i == rooms[1].x && j == rooms[1].y) {
                printf("E");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move(int dx, int dy) {
    int new_x = rooms[0].x + dx;
    int new_y = rooms[0].y + dy;

    if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10 &&
        (new_x!= rooms[1].x || new_y!= rooms[1].y)) {
        rooms[0].x = new_x;
        rooms[0].y = new_y;
    }
}

void encounter_ghost() {
    printf("You encounter a ghost!\n");
    exit(1);
}

int main() {
    srand(time(NULL));
    generate_maze();
    print_maze();

    int choice;
    while (1) {
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            move(0, -1);
            break;
        case 1:
            move(0, 1);
            break;
        case 2:
            move(-1, 0);
            break;
        case 3:
            move(1, 0);
            break;
        default:
            printf("Invalid choice.\n");
        }

        if (rooms[0].x == rooms[1].x && rooms[0].y == rooms[1].y) {
            printf("You escaped the haunted house!\n");
            return 0;
        }

        if (rand() % GHOST_CHANCE == 0) {
            encounter_ghost();
        }
    }

    return 0;
}