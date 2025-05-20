//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char *name;
    Point location;
    int is_visited;
} Room;

Room rooms[] = {
    {"Living Room", {0, 0}, 0},
    {"Kitchen", {0, 1}, 0},
    {"Bathroom", {1, 0}, 0},
    {"Bedroom", {1, 1}, 0}
};

int num_rooms = sizeof(rooms) / sizeof(Room);

void print_room(Room *room) {
    printf("You are in the %s.\n", room->name);
}

int main() {
    srand(time(NULL));

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");

        print_room(&rooms[player_x + player_y * 2]);

        char move;
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                player_y--;
                break;
            case's':
                player_y++;
                break;
            case 'a':
                player_x--;
                break;
            case 'd':
                player_x++;
                break;
            default:
                printf("Invalid move.\n");
        }

        if (player_x < 0) {
            player_x = num_rooms - 1;
        } else if (player_x >= num_rooms) {
            player_x = 0;
        }

        if (player_y < 0) {
            player_y = num_rooms - 1;
        } else if (player_y >= num_rooms) {
            player_y = 0;
        }

        int room_index = player_x + player_y * 2;

        if (!rooms[room_index].is_visited) {
            rooms[room_index].is_visited = 1;
            printf("You discovered a new room: %s\n", rooms[room_index].name);
        }
    }

    return 0;
}