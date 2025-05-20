//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 256
#define MAX_ROOMS 10

typedef struct {
    char name[256];
    char description[256];
    char *items[10];
    int num_items;
    int x;
    int y;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Game;

void print_room_description(Game *game, int room_index) {
    Room *room = &game->rooms[room_index];
    printf("You are in %s\n", room->name);
    printf("%s\n", room->description);
    printf("You see:\n");
    for (int i = 0; i < room->num_items; i++) {
        printf("- %s\n", room->items[i]);
    }
}

void move_north(Game *game, int room_index) {
    Room *room = &game->rooms[room_index];
    int new_room_index = room->y - 1;
    if (new_room_index < 0) {
        printf("You cannot move north from this room.\n");
    } else {
        print_room_description(game, new_room_index);
    }
}

void move_south(Game *game, int room_index) {
    Room *room = &game->rooms[room_index];
    int new_room_index = room->y + 1;
    if (new_room_index >= game->num_rooms) {
        printf("You cannot move south from this room.\n");
    } else {
        print_room_description(game, new_room_index);
    }
}

void move_east(Game *game, int room_index) {
    Room *room = &game->rooms[room_index];
    int new_room_index = room->x + 1;
    if (new_room_index >= game->num_rooms) {
        printf("You cannot move east from this room.\n");
    } else {
        print_room_description(game, new_room_index);
    }
}

void move_west(Game *game, int room_index) {
    Room *room = &game->rooms[room_index];
    int new_room_index = room->x - 1;
    if (new_room_index < 0) {
        printf("You cannot move west from this room.\n");
    } else {
        print_room_description(game, new_room_index);
    }
}

int main() {
    srand(time(NULL));

    Game game = {
        .num_rooms = 10,
        .rooms = {
            {
                .name = "Starting Room",
                .description = "You are in a small, dark room. There is a door to the north.",
                .num_items = 1,
                .items = {"torch"},
                .x = 0,
                .y = 0
            },
            {
                .name = "Dark Room",
                .description = "You are in a small, dark room. There is a door to the south.",
                .num_items = 1,
                .items = {"key"},
                .x = 0,
                .y = 1
            },
            {
                .name = "Crystal Room",
                .description = "You are in a small, dark room. There is a door to the east.",
                .num_items = 2,
                .items = {"crystal", "gold"},
                .x = 1,
                .y = 0
            },
            {
                .name = "Sun Room",
                .description = "You are in a small, dark room. There is a door to the west.",
                .num_items = 2,
                .items = {"candle", "torch"},
                .x = -1,
                .y = 0
            },
            {
                .name = "Treasure Room",
                .description = "You are in a small, dark room. There is a door to the north.",
                .num_items = 3,
                .items = {"gold", "diamond", "sword"},
                .x = 0,
                .y = 1
            },
            {
                .name = "Boss Room",
                .description = "You are in a small, dark room. There is a door to the south.",
                .num_items = 4,
                .items = {"book", "map", "compass", "sword"},
                .x = 0,
                .y = -1
            },
            {
                .name = "Final Room",
                .description = "You are in a small, dark room. There is a door to the west.",
                .num_items = 5,
                .items = {"book", "map", "compass", "sword", "amulet"},
                .x = -1,
                .y = 0
            }
        }
    };

    int room_index = 0;
    print_room_description(&game, room_index);

    while (1) {
        char input[MAX_INPUT_LENGTH];
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "north") == 0) {
            move_north(&game, room_index);
        } else if (strcmp(input, "south") == 0) {
            move_south(&game, room_index);
        } else if (strcmp(input, "east") == 0) {
            move_east(&game, room_index);
        } else if (strcmp(input, "west") == 0) {
            move_west(&game, room_index);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}