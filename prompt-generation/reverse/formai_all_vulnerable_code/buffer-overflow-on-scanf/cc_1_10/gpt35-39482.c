//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROOMS 10

enum RoomType {
    EMPTY,
    TREASURE,
    MONSTER,
    EXIT
};

typedef struct Room {
    int id;
    enum RoomType type;
    bool visited;
} Room;

Room build_room(int id, enum RoomType type) {
    Room room;
    room.id = id;
    room.type = type;
    room.visited = false;
    return room;
}

void print_room(Room room) {
    printf("---- Room %d ----\n", room.id);
    switch (room.type) {
        case EMPTY:
            printf("You enter an empty room.\n");
            break;
        case TREASURE:
            printf("You have found treasure! Congratulations!\n");
            break;
        case MONSTER:
            printf("You have encountered a monster! Fight or flee?\n");
            break;
        case EXIT:
            printf("You have found the exit! Congratulations!\n");
            break;
    }
}

void print_map(Room rooms[], int current_room_id) {
    printf("Current Room: %d\n", current_room_id);
    for (int i = 0; i < ROOMS; i++) {
        if (rooms[i].id == current_room_id) {
            print_room(rooms[i]);
            rooms[i].visited = true;
        } else if (rooms[i].visited) {
            printf("---- Room %d ----\n", rooms[i].id);
            printf("You have already visited this room.\n");
        } else {
            printf("---- Room %d ----\n", rooms[i].id);
            printf("This room has not yet been explored.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    Room rooms[ROOMS];
    for (int i = 0; i < ROOMS; i++) {
        if (i == 0) {
            rooms[i] = build_room(i, EMPTY);
        } else if (i == ROOMS-1) {
            rooms[i] = build_room(i, EXIT);
        } else if (rand() % 2 == 0) {
            rooms[i] = build_room(i, TREASURE);
        } else {
            rooms[i] = build_room(i, MONSTER);
        }
    }
    int current_room_id = 0;
    bool game_over = false;
    while (!game_over) {
        print_map(rooms, current_room_id);
        char choice;
        printf("Enter 'F' to move forward, 'B' to move back, 'Q' to quit: ");
        scanf(" %c", &choice);
        if (choice == 'Q') {
            game_over = true;
        } else if (choice == 'F') {
            if (current_room_id == ROOMS-1) {
                printf("You have reached the exit! Congratulations, you win!\n");
                game_over = true;
            } else {
                current_room_id++;
            }
        } else if (choice == 'B') {
            if (current_room_id == 0) {
                printf("You cannot go back any further.\n");
            } else {
                current_room_id--;
            }
        } else {
            printf("Invalid choice. Please choose 'F', 'B', or 'Q'.\n");
        }
    }
    return 0;
}